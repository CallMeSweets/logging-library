//
// Created by ola on 25.03.2022.
//

#ifndef LOGGING_LIBRARY_LOG_H
#define LOGGING_LIBRARY_LOG_H

#include "LogPriority.h"
#include <cstring>
#include <string>

using namespace std;

class Log {
private:
    string message;
    const char* timestamp;
    LogPriority::LogPriority priority;
public:
    string getMessage();
    const char* getPriorityName();
    const char* getTimestamp();
    LogPriority::LogPriority getPriority();
    string toJson();

    void setMessage(string newMessage);
    void setTimestamp(const char* newTimestamp);
    void setPriority(LogPriority::LogPriority newPriority);
};


#endif //LOGGING_LIBRARY_LOG_H
