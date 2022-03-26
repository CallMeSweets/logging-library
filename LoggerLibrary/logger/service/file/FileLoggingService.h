//
// Created by ola on 25.03.2022.
//

#ifndef LOGGERLIBRARY_FILELOGGINGSERVICE_H
#define LOGGERLIBRARY_FILELOGGINGSERVICE_H

#include "../LoggingService.h"
#include "../../model/Log.h"

class FileLoggingService: public LoggingService{
public:
    void log(Log* log, int args) override;
    const char* getCurrentTimestamp();
    FileLoggingService(const char* filePath);
    ~FileLoggingService();

private:
    FILE* file = nullptr;
    const char* logFilePath = 0;
};


#endif //LOGGERLIBRARY_FILELOGGINGSERVICE_H
