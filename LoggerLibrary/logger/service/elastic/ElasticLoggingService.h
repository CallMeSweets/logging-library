//
// Created by ola on 26.03.2022.
//

#ifndef LOGGERLIBRARY_ELASTICLOGGINGSERVICE_H
#define LOGGERLIBRARY_ELASTICLOGGINGSERVICE_H

#include "../LoggingService.h"
#include <cpr/cpr.h>
#include <bits/stdc++.h>
#include <cstring>

using namespace std;

class ElasticLoggingService: public LoggingService{
public:
    void log(Log* log) override;
    void send(Log* log);
    ElasticLoggingService(const string& newIndexName, const string& newHost, const string& newPort);
    ~ElasticLoggingService();

private:
    string indexName;
    string host;
    string port;
    string url;
};


#endif //LOGGERLIBRARY_ELASTICLOGGINGSERVICE_H
