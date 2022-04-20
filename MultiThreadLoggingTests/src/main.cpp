#include <iostream>
#include <thread>

#include "Logger.h"

void log(int n){
    Logger::Info("Thread index: %d", n);
}

int main() {
    Logger::readConfiguration();

    std::thread threads[10];

    for (int i = 0; i < 10; ++i) {
        threads[i] = std::thread(log, i);
    }

    for (int i = 0; i < 10; ++i) {
        threads[i].join();
    }

    return 0;
}
