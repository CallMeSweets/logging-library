//
// Created by ola on 25.03.2022.
//

#ifndef LOGGERLIBRARY_LOGPRIORITY_H
#define LOGGERLIBRARY_LOGPRIORITY_H

#include <cstring>
#include <string>

using namespace std;

namespace LogPriority
{
    enum LogPriority
    {
        TracePriority, DebugPriority, InfoPriority, WarnPriority, ErrorPriority, CriticalPriority
    };

    static LogPriority priorityFromText(const string& priority){
        if(priority == "INFO") return LogPriority::InfoPriority;
        if(priority == "WARN") return LogPriority::WarnPriority;
        if(priority == "TRACE") return LogPriority::TracePriority;
        if(priority == "DEBUG") return LogPriority::DebugPriority;
        if(priority == "ERROR") return LogPriority::ErrorPriority;
        if(priority == "CRITICAL") return LogPriority::CriticalPriority;

        return LogPriority::InfoPriority;
    }

    static const char* getPriorityName(LogPriority priority) {
        switch (priority)
        {
            case LogPriority::InfoPriority: return "[INFO] ";
            case LogPriority::WarnPriority: return "[WARN] ";
            case LogPriority::TracePriority: return "[TRACE] ";
            case LogPriority::DebugPriority: return "[DEBUG] ";
            case LogPriority::ErrorPriority: return "[ERROR] ";
            case LogPriority::CriticalPriority: return "[CRITICAL] ";
            default: return "[UNKNOWN] ";
        }
    }

}

#endif //LOGGERLIBRARY_LOGPRIORITY_H
