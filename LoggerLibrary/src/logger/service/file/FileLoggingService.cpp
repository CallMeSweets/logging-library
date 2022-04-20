//
// Created by ola on 25.03.2022.
//

#include "FileLoggingService.h"

void FileLoggingService::log(Log* log) {
    if(file)
    {
        fprintf(file, "%s\t", log -> getTimestamp());
        fprintf(file, "%s", log -> getPriorityName());
        fprintf(file, log -> getMessage().c_str(), "");
        fprintf(file, "\n");
    }

    delete log;
}

FileLoggingService::FileLoggingService(const char* filePath){
    logFilePath = filePath;
    if(file == nullptr){
        file = fopen(logFilePath, "a");

        if(file == nullptr){
            printf("Logger: Failed to open file at %s", filePath);
        }
    }
}

FileLoggingService::~FileLoggingService() {
    fclose(file);
    file = nullptr;
}

int FileLoggingService::instance() {
    return 1;
}
