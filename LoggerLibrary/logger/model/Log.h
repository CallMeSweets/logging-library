//
// Created by ola on 25.03.2022.
//

#ifndef LOGGING_LIBRARY_LOG_H
#define LOGGING_LIBRARY_LOG_H

#include "LogPriority.h"
#include <cstring>
#include <stdio.h>

class Log {
private:
    const char* message;
    const char* timestamp;
    int args;
    LogPriority::LogPriority priority;
public:
    const char* getMessage();
    const char* getPriorityName();
    const char* getTimestamp();
    int getArgs();
    LogPriority::LogPriority getPriority();

    void setMessage(const char* newMessage);
    void setTimestamp(const char* newTimestamp);
    void setPriority(LogPriority::LogPriority newPriority);
    void setArgs(int newArgs);
};


#endif //LOGGING_LIBRARY_LOG_H
