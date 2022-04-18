//
// Created by ola on 28.03.2022.
//

#ifndef LOGGERLIBRARY_YAMLCONFIGURATIONPARSER_H
#define LOGGERLIBRARY_YAMLCONFIGURATIONPARSER_H

#include <string>
#include <yaml-cpp/yaml.h>
#include <iostream>
#include "../Logger.h"
#include "../service/file/FileLoggingService.h"
#include "../service/elastic/ElasticLoggingService.h"
#include <chrono>

using namespace std;

class YamlConfigurationParser {
public:
    inline static const char* configFilePath = "../config.yaml";

public:
    static void read();
};


#endif //LOGGERLIBRARY_YAMLCONFIGURATIONPARSER_H
