//
// Created by s3ba on 17.03.2022.
//

#include "Logger.h"
#include "parser/YamlConfigurationParser.h"

void Logger::setPriority(LogPriority::LogPriority priority) {
    getInstance().priority = priority;
}

void Logger::enableService(LoggingService* loggingService){
    getInstance().pushBackService(loggingService);
}

void Logger::disableService(int instance){
    getInstance().freeService(instance);
}

Logger& Logger::getInstance() {
    static Logger logger;
    return logger;
}

char* Logger::getCurrentTimestamp()
{
    time_t now = time(0);
    char* time =  ctime(&now);
    time[strcspn(time, "\n")] = '\0';
    return time;
}

void Logger::log(Log* log)
{
    if(priority <= log -> getPriority())
    {

        std::scoped_lock lock(log_mutex);
        printf("%s\t", log -> getTimestamp());
        printf("%s", log -> getPriorityName());
        printf(log -> getMessage().c_str(), "");
        printf("\n");

        if(!services.empty())
        {
            for (const auto &service : services){
                service->log(log);
            }
        }
    }
}

void Logger::pushBackService(LoggingService* loggingService){
    services.push_back(loggingService);
}

void Logger::freeServices(){
    for (const auto &service : services){
        delete service;
    }
}

void Logger::freeService(int instance) {
    for (const auto &service : services){
        if(service->instance() == instance) {
            delete service;
        }
    }
}

void Logger::readConfiguration() {
    YamlConfigurationParser::read();
}

string Logger::format(const char* fmt, ...){
    int size = 512;
    char* buffer = 0;
    buffer = new char[size];
    va_list vl;
    va_start(vl, fmt);
    int nsize = vsnprintf(buffer, size, fmt, vl);
    if(size<=nsize){ //fail delete buffer and try again
        delete[] buffer;
        buffer = 0;
        buffer = new char[nsize+1]; //+1 for /0
        nsize = vsnprintf(buffer, size, fmt, vl);
    }
    std::string ret(buffer);
    va_end(vl);
    delete[] buffer;
    return ret;
}
