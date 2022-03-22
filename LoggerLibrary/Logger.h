//
// Created by s3ba on 17.03.2022.
//

#ifndef LOGGERLIBRARY_LOGGER_H
#define LOGGERLIBRARY_LOGGER_H

#include <stdio.h>
#include <mutex>
#include <ctime>
#include <string.h>

using namespace std;

enum LogPriority
{
    TracePriority, DebugPriority, InfoPriority, WarnPriority, ErrorPriority, CriticalPriority
};

class Logger
{
private:
    LogPriority priority = InfoPriority;
    std::mutex log_mutex;
    FILE* file = nullptr;
    const char* filePath = 0;
public:
    static void setPriority(LogPriority priority) {
        getInstance().priority = priority;
    }

    static void enableFileOutput(){
        Logger& logger = getInstance();
        logger.filePath = "logs.txt";
        logger.enable_file_output();
    }

    static void enableFileOutput(const char* newFilePath){
        Logger& logger = getInstance();
        logger.filePath = newFilePath;
        logger.enable_file_output();
    }

    template<typename... Args>
    static void Trace(const char* message, Args... args)
    {
        getInstance().log("[Trace]\t", TracePriority, message, args...);
    }

    template<typename... Args>
    static void Debug(const char* message, Args... args)
    {
        getInstance().log("[Debug]\t", DebugPriority, message, args...);
    }

    template<typename... Args>
    static void Info(const char* message, Args... args)
    {
        getInstance().log("[Info]\t", InfoPriority, message, args...);
    }

    template<typename... Args>
    static void Warn(const char* message, Args... args)
    {
        getInstance().log("[Warn]\t", WarnPriority, message, args...);
    }

    template<typename... Args>
    static void Error(const char* message, Args... args)
    {
        getInstance().log("[Error]\t", ErrorPriority, message, args...);
    }

    template<typename... Args>
    static void Critical(const char* message, Args... args)
    {
        getInstance().log("[Critical]\t", CriticalPriority, message, args...);
    }

private:
    Logger(){}

    Logger(const Logger&) = delete;
    Logger& operator = (const Logger&) = delete;

    ~Logger()
    {
        free_file();
    }

    static Logger& getInstance()
    {
        static Logger logger;
        return logger;
    }

    template<typename... Args>
    void log(const char* priority_level_str, LogPriority log_priority, const char* message, Args... args)
    {
        if(priority <= log_priority)
        {
            std::scoped_lock lock(log_mutex);
            printf("%s\t", getTimestamp());
            printf(priority_level_str);
            printf(message, args...);
            printf("\n");

            if(file)
            {
                fprintf(file, "%s\t", getTimestamp());
                fprintf(file, priority_level_str);
                fprintf(file, message, args...);
                fprintf(file, "\n");
            }
        }
    }

    static char* getTimestamp()
    {
        time_t now = time(0);
        char* time =  ctime(&now);
        time[strcspn(time, "\n")] = '\0';
        return time;
    }

    void enable_file_output(){
        if(file != nullptr){
            fclose(file);
        }

        file = fopen(filePath, "a");

        if(file == 0){
            printf("Logger: Failed to open file at %s", filePath);
        }
    }

    void free_file(){
        fclose(file);
        file = nullptr;
    }

};

#endif //LOGGERLIBRARY_LOGGER_H
