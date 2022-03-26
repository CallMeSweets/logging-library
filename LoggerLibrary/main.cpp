#include <iostream>
#include "logger/Logger.h"

#include <thread>
#include <cpr/cpr.h>
#include "logger/service/file/FileLoggingService.h"

using namespace std;

void log(int n){
    Logger::Info("%d", n);
}

void test() {
//    cpr::Response r = cpr::Get(cpr::Url{"https://api.filmweb.pl/v1/vod/providers/list"});
//    r.status_code;                  // 200
//    r.header["content-type"];       // application/json; charset=utf-8
//    r.text;                         // JSON text string
//    Logger::Info("Status code: %d, Text %d", r.error.message, r.header["content-type"]);
//    cpr::Url  url{"https://api.filmweb.pl/v1/vod/providers/list"};
//    cpr::Response response = cpr::Get(url);
//
//    cout << response.error.message;


    cpr::Url urlEs{"localhost:9200/logging-03-2022/_doc"};
//    cpr::Payload payload{{"message", "secret message"}};
//    payload.Add({"level", "INFO"});
//    payload.Add({"code", "2"});
//    payload.Add({"class", "Car.java"});
//    cpr::Response responseEs = cpr::Post(urlEs, payload);

    std::string body{R"({
  "message": "sgsg",
  "level": "ERROR",
  "code": 3,
  "class": "aaaaa"
})"};
    cout << body;
    cpr::Response response = cpr::Post(urlEs, cpr::Header{{"Content-Type", "application/json"}}, cpr::Body{body});

    cout << response.status_code;

    cout << response.error.message;

}

char* getTimestamp()
{
    time_t now = time(0);
    char* time =  ctime(&now);
    time[strcspn(time, "\n")] = '\0';
    return time;
}

int main() {
//    Logger::enableFileOutput("text.txt");

    LoggingService* service = new FileLoggingService{"logg.txt"};
    Logger::enableFileService(service);
//    test();
    std::thread threads[10];

    for (int i = 0; i < 10; ++i) {
        threads[i] = std::thread(log, i);
    }

    for (int i = 0; i < 10; ++i) {
        threads[i].join();
    }

    return 0;
}
