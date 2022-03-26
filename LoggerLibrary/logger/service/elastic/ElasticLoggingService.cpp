//
// Created by ola on 26.03.2022.
//

#include "ElasticLoggingService.h"

void ElasticLoggingService::log(Log* log)
{
    send(log);
}

void ElasticLoggingService::send(Log* log)
{
    string body = log -> toJson();
    cpr::Url urlEs{this -> url};
    cpr::Response response = cpr::Post(urlEs, cpr::Header{{"Content-Type", "application/json"}}, cpr::Body{body});

    cout << response.status_code;
}

ElasticLoggingService::ElasticLoggingService(const string& newIndexName, const string& newHost, const string& newPort)
{
    this -> indexName = newIndexName;
    this -> host = newHost;
    this -> port = newPort;
    this -> url = host + ":" + port + "/" + indexName + "/_doc";
}

ElasticLoggingService::~ElasticLoggingService()
{

}