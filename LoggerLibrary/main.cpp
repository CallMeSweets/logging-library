#include <iostream>
#include "Logger.h"

#include <thread>

void log(int n){
    Logger::Info("%d", n);
}

int main() {
    Logger::enableFileOutput("text.txt");
    std::thread threads[10];

    for (int i = 0; i < 10; ++i) {
        threads[i] = std::thread(log, i);
    }

    for (int i = 0; i < 10; ++i) {
        threads[i].join();
    }

    return 0;
}
