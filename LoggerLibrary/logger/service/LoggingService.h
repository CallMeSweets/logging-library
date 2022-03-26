//
// Created by ola on 25.03.2022.
//

#ifndef LOGGERLIBRARY_LOGGINGSERVICE_H
#define LOGGERLIBRARY_LOGGINGSERVICE_H

#include "../model/Log.h"

class LoggingService {
public:
    virtual void log(Log* log) = 0;
    ~LoggingService() = default;
};

#endif