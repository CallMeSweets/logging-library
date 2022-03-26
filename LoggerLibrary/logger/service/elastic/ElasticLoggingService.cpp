//
// Created by ola on 26.03.2022.
//

#include "ElasticLoggingService.h"

void ElasticLoggingService::log(Log* log, int args)
{

}

void doRequest()
{

}
const char* doRequestBody(Log* log, int args)
{
    string body{R"({
  "message": "sgsg",
  "level": "ERROR",
  "code": 3,
  "class": "aaaaa"
})"};
}

ElasticLoggingService::ElasticLoggingService(const char* newIndexName)
{
    this -> indexName = newIndexName;
}

ElasticLoggingService::~ElasticLoggingService()
{

}