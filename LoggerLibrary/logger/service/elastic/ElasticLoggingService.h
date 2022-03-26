//
// Created by ola on 26.03.2022.
//

#ifndef LOGGERLIBRARY_ELASTICLOGGINGSERVICE_H
#define LOGGERLIBRARY_ELASTICLOGGINGSERVICE_H

#include "../LoggingService.h"
#include <cpr/cpr.h>
#include <string>

using namespace std;

class ElasticLoggingService: public LoggingService {
private:
   const char* indexName;
public:
    void log(Log* log, int args) override;
    void doRequest();
    const char* doRequestBody();
    ElasticLoggingService(const char* newIndexName);
    ~ElasticLoggingService();
};


#endif //LOGGERLIBRARY_ELASTICLOGGINGSERVICE_H
