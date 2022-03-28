//
// Created by ola on 28.03.2022.
//

#include "YamlConfigurationParser.h"


void YamlConfigurationParser::read() {
//    while(true) {
        YAML::Node config;
        try {
            config = YAML::LoadFile(configFilePath);
        } catch (YAML::BadFile &e) {
            std::cout << "read error!" << std::endl;
        }

        if (config["logger"]["priority"].IsDefined()) {
            auto priority = config["logger"]["priority"].as<string>();
            Logger::setPriority(LogPriority::priorityFromText(priority));
        } else {
            Logger::setPriority(LogPriority::InfoPriority);
        }

        if (config["service"]["file"]["enable"].IsDefined()) {
            if (config["service"]["file"]["enable"].as<bool>()) {
                LoggingService *service;
                if (config["service"]["file"]["path"].IsDefined()) {
                    service = new FileLoggingService(config["service"]["file"]["path"].as<string>().c_str());
                } else {
                    service = new FileLoggingService("log.txt");
                }
                Logger::enableService(service);
            } else {
                Logger::disableService(1);
            }
        }

        if (config["service"]["elastic"]["enable"].IsDefined()) {
            if (config["service"]["elastic"]["enable"].as<bool>()) {
                if (config["service"]["elastic"]["index"].IsDefined() &&
                    config["service"]["elastic"]["host"].IsDefined() &&
                    config["service"]["elastic"]["port"].IsDefined()) {
                    LoggingService *service = new ElasticLoggingService(
                            config["service"]["elastic"]["index"].as<string>(),
                            config["service"]["elastic"]["host"].as<string>(),
                            config["service"]["elastic"]["port"].as<string>());

                    Logger::enableService(service);
                }
            } else {
                Logger::disableService(2);
            }
        }

        YamlConfigurationParser::enabled = true;

//        std::chrono::seconds timespan(10);
//        std::this_thread::sleep_for(timespan);
//    }
}


