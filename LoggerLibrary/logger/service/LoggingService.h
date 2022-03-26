//
// Created by ola on 25.03.2022.
//

#include "../model/Log.h"
#include <iostream>
#include <string.h>

using namespace std;

class LoggingService {
public:
    virtual void log(Log* log, int args) = 0;
    ~LoggingService() = default;
};
