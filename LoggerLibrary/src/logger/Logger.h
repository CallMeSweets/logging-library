//
// Created by s3ba on 17.03.2022.
//

#ifndef LOGGERLIBRARY_LOGGER_H
#define LOGGERLIBRARY_LOGGER_H

#include <cstdio>
#include <mutex>
#include <ctime>
#include <cstring>
#include "service/LoggingService.h"
#include "model/LogPriority.h"
#include <list>
#include <iostream>
#include <cstdarg>

using namespace std;

class Logger
{
private:
    LogPriority::LogPriority priority = LogPriority::InfoPriority;
    std::mutex log_mutex;
    list<LoggingService*> services;
public:
    static void setPriority(LogPriority::LogPriority priority);

    static void enableService(LoggingService* loggingService);

    static void disableService(int instance);

    static void readConfiguration();

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

    static Logger& getInstance();

    void log(Log* log);

    template<typename... Args>
    Log* makeLog(LogPriority::LogPriority log_priority, const char* formatMessage, Args... args)
    {
        Log* log = new Log();
        log -> setMessage(format(formatMessage, args...));
        log -> setPriority(log_priority);
        log -> setTimestamp(getCurrentTimestamp());

        return log;
    }

    std::string format(const char* fmt, ...);

    static char* getCurrentTimestamp();
    void pushBackService(LoggingService* loggingService);
    void freeServices();
    void freeService(int instance);

};

#endif //LOGGERLIBRARY_LOGGER_H
