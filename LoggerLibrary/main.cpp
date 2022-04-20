#include "src/logger/Logger.h"
#include "src/logger/parser/YamlConfigurationParser.h"

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

}

int main() {
    Logger::readConfiguration();
    Logger::Info("Tu seba: %s aaaadfdsgsdgsdgsdgdsgsdzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz: %d %s", "afas ", 1, "aaaa");
    logzz2(2);
//    std::thread threads[10];
//
//    for (int i = 0; i < 10; ++i) {
//        threads[i] = std::thread(logzz2, i);
//    }
//
//    for (int i = 0; i < 10; ++i) {
//        threads[i].join();
//    }


    return 0;
}
