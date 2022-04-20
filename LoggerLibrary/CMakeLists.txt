cmake_minimum_required(VERSION 3.21)
project(LoggerLibrary)

set(CMAKE_CXX_STANDARD 20)

set(HEADERS_FILES
        logger/Logger.h
        logger/model/Log.h
        logger/model/LogPriority.h
        logger/service/LoggingService.h
        logger/service/file/FileLoggingService.h
        logger/service/elastic/ElasticLoggingService.h
        logger/parser/YamlConfigurationParser.h)

set(SOURCES_FILES
        logger/Logger.cpp
        logger/model/Log.cpp
        logger/service/file/FileLoggingService.cpp
        logger/service/elastic/ElasticLoggingService.cpp
        logger/parser/YamlConfigurationParser.cpp)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG beb9e98806bb84bcc130a2cebfbcbbc6ce62b335) # The commit hash for 1.7.2. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_Declare(yaml-cpp GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
        GIT_TAG yaml-cpp-0.7.0)
FetchContent_MakeAvailable(cpr yaml-cpp)


add_library(loglib STATIC ${SOURCES_FILES})
target_link_libraries(loglib PRIVATE cpr::cpr yaml-cpp::yaml-cpp)
set_target_properties(loglib PROPERTIES LINKER_LANGUAGE CXX)