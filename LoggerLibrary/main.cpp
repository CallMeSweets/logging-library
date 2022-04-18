#include "logger/Logger.h"
#include "logger/parser/YamlConfigurationParser.h"

#include <thread>
#include <chrono>


void logzz(int n){
    int i = 0;
//    while(true){
        i++;
//        std::chrono::seconds timespan(3);
//        std::this_thread::sleep_for(timespan);
//        Logger::Info("info secret", n);
//        if(i > 100)
//            break;
//    }
}

void logzz2(int n){
    Logger::Info("info secret", n);
}


int main() {
    Logger::readConfiguration();
    logzz2(1);

//    std::thread threads[2];

    for (int i = 0; i < 10; ++i) {
        logzz(i);
//        if(i < 2){
//            threads[i] = std::thread(logzz, i);
//        } else {
//            threads[i] = std::thread(logzz2, i);
//        }
    }

//    for (int i = 0; i < 2; ++i) {
//        threads[i].join();
//    }


    return 0;
}
