//
// Created by ola on 25.03.2022.
//

#include "Log.h"


const char* Log::getMessage() {
    return message;
}

const char* Log::getPriorityName() {
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

LogPriority::LogPriority Log::getPriority() {
    return priority;
}

const char* Log::getTimestamp() {
    return this -> timestamp;
}

int Log::getArgs() {
    return this -> args;
}

void Log::setMessage(const char* newMessage){
    this->message = newMessage;
}

void Log::setPriority(LogPriority::LogPriority newPriority){
    this->priority = newPriority;
}

void Log::setTimestamp(const char* newTimestamp) {
    this -> timestamp = newTimestamp;
}

void Log::setArgs(int newArgs){
    this -> args = newArgs;
}

string Log::toJson() {
    string begin = "{";
    string end = "}";
    string json =
            begin
            + "\"timestamp\": " + "\"" + this->getTimestamp()+ "\","
            + "\"message\": " + "\"" + this->getMessage()+ "\","
            + "\"priority\": " + "\"" + this->getPriorityName()+ "\","
            + "\"args\": " + "\"" + to_string(this->getArgs()) + "\"    " +
            end
            ;

    return json;
}