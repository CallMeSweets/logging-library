//
// Created by s3ba on 17.03.2022.
//

#ifndef LOGGERLIBRARY_LOGGER_H
#define LOGGERLIBRARY_LOGGER_H

#include <stdio.h>
#include <mutex>
#include <ctime>
#include <string.h>
#include "service/LoggingService.h"
#include "model/LogPriority.h"
#include <list>
#include <iostream>

using namespace std;

class Logger
{
private:
    LogPriority::LogPriority priority = LogPriority::InfoPriority;
    std::mutex log_mutex;
    list<LoggingService*> services;
public:
    static void setPriority(LogPriority::LogPriority priority) {
        getInstance().priority = priority;
    }

    static void enableService(LoggingService* loggingService){
        getInstance().pushBackService(loggingService);
    }

    static void disableService(int instance){
        getInstance().freeService(instance);
    }

    template<typename... Args>
    static void Trace(const char* message, Args... args)
    {
        Log* log = getInstance().makeLog(LogPriority::TracePriority, message, args...);
        getInstance().log(log);
    }

    template<typename... Args>
    static void Debug(const char* message, Args... args)
    {
        Log* log = getInstance().makeLog(LogPriority::DebugPriority, message, args...);
        getInstance().log(log);
    }

    template<typename... Args>
    static void Info(const char* message, Args... args)
    {
        Log* log = getInstance().makeLog(LogPriority::InfoPriority, message, args...);
        getInstance().log(log);
    }

    template<typename... Args>
    static void Warn(const char* message, Args... args)
    {
        Log* log = getInstance().makeLog(LogPriority::WarnPriority, message, args...);
        getInstance().log(log);
    }

    template<typename... Args>
    static void Error(const char* message, Args... args)
    {
        Log* log = getInstance().makeLog(LogPriority::ErrorPriority, message, args...);
        getInstance().log(log);
    }

    template<typename... Args>
    static void Critical(const char* message, Args... args)
    {
        Log* log = getInstance().makeLog(LogPriority::CriticalPriority, message, args...);
        getInstance().log(log);
    }

private:
    Logger(){}

    Logger(const Logger&) = delete;
    Logger& operator = (const Logger&) = delete;

    ~Logger()
    {
        freeServices();
    }

    static Logger& getInstance()
    {
        static Logger logger;
        return logger;
    }

    template<typename... Args>
    Log* makeLog(LogPriority::LogPriority log_priority, const char* message, Args... args)
    {
        Log* log = new Log();
        log -> setMessage(message);
        log -> setPriority(log_priority);
        log -> setTimestamp(getCurrentTimestamp());
        log -> setArgs(args...);
        return log;
    }

    void log(Log* log)
    {
        if(priority <= log -> getPriority())
        {
            std::scoped_lock lock(log_mutex);
            printf("%s\t", log -> getTimestamp());
            printf("%s", log -> getPriorityName());
            printf(log -> getMessage(), log -> getArgs());
            printf("\n");

            if(!services.empty())
            {
                for (const auto &service : services){
                    cout << "instance: " << service -> instance();
                    service->log(log);
                }
            }
        }
    }

    static char* getCurrentTimestamp()
    {
        time_t now = time(0);
        char* time =  ctime(&now);
        time[strcspn(time, "\n")] = '\0';
        return time;
    }

    void pushBackService(LoggingService* loggingService){
        services.push_back(loggingService);
    }

    void freeServices(){
        for (const auto &service : services){
            delete service;
        }
    }

    void freeService(int instance) {
        for (const auto &service : services){
            if(service->instance() == instance) {
                delete service;
            }
        }
    }

};

#endif //LOGGERLIBRARY_LOGGER_H
