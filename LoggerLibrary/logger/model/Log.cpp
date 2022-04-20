//
// Created by ola on 25.03.2022.
//

#include "Log.h"

#include <utility>


string Log::getMessage() {
    return message;
}

const char* Log::getPriorityName() {
    return LogPriority::getPriorityName(priority);
}

LogPriority::LogPriority Log::getPriority() {
    return priority;
}

const char* Log::getTimestamp() {
    return this -> timestamp;
}

void Log::setMessage(string newMessage){
    this->message = std::move(newMessage);
}

void Log::setPriority(LogPriority::LogPriority newPriority){
    this->priority = newPriority;
}

void Log::setTimestamp(const char* newTimestamp) {
    this -> timestamp = newTimestamp;
}

string Log::toJson() {
    string begin = "{";
    string end = "}";
    string json =
            begin
            + "\"timestamp\": " + "\"" + this->getTimestamp()+ "\","
            + "\"message\": " + "\"" + this->getMessage()+ "\","
            + "\"priority\": " + "\"" + this->getPriorityName()+ "\"" +
            end
            ;

    return json;
}