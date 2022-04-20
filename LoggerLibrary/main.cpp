#include "logger/Logger.h"
#include "logger/parser/YamlConfigurationParser.h"

#include <thread>
#include <chrono>
#include <iostream>

using namespace std;

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
    Logger::Info("Tu seba: %s aaaadfdsgsdgsdgsdgdsgsdzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz: %d", "afas ", n);
}

int main() {
    Logger::readConfiguration();
    std::thread threads[10];

    for (int i = 0; i < 10; ++i) {
        threads[i] = std::thread(logzz2, i);
    }

    for (int i = 0; i < 10; ++i) {
        threads[i].join();
    }


    return 0;
}
