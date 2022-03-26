#include "logger/Logger.h"
#include "logger/service/elastic/ElasticLoggingService.h"
#include "logger/service/file/FileLoggingService.h"

#include <thread>


void logzz(int n){
    Logger::Info("info secret", n);
}


int main() {

//    LoggingService* service = new FileLoggingService{"logg.txt"};
//    Logger::enableFileService(service);
    LoggingService* elService = new ElasticLoggingService{"logging-03-2022", "localhost", "9200"};
    Logger::enableFileService(elService);

    std::thread threads[10];

    for (int i = 0; i < 10; ++i) {
        threads[i] = std::thread(logzz, i);
    }

    for (int i = 0; i < 10; ++i) {
        threads[i].join();
    }

    return 0;
}
