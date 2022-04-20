cmake_minimum_required(VERSION 3.21)
project(LoggerLibrary)

set(CMAKE_CXX_STANDARD 20)

set(HEADERS_FILES
        src/logger/Logger.h
        src/logger/model/Log.h
        src/logger/model/LogPriority.h
        src/logger/service/LoggingService.h
        src/logger/service/file/FileLoggingService.h
        src/logger/service/elastic/ElasticLoggingService.h
        src/logger/parser/YamlConfigurationParser.h)

set(SOURCES_FILES
        main.cpp
        src/logger/Logger.cpp
        src/logger/model/Log.cpp
        src/logger/service/file/FileLoggingService.cpp
        src/logger/service/elastic/ElasticLoggingService.cpp
        src/logger/parser/YamlConfigurationParser.cpp)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG beb9e98806bb84bcc130a2cebfbcbbc6ce62b335) # The commit hash for 1.7.2. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_Declare(yaml-cpp GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
        GIT_TAG yaml-cpp-0.7.0)
FetchContent_MakeAvailable(cpr yaml-cpp)

add_executable(LoggerLibrary ${SOURCES_FILES} ${HEADERS_FILES})
target_link_libraries(LoggerLibrary PRIVATE cpr::cpr yaml-cpp::yaml-cpp)


add_library(loglib STATIC ${SOURCES_FILES})
target_link_libraries(loglib PRIVATE cpr::cpr yaml-cpp::yaml-cpp)
set_target_properties(loglib PROPERTIES LINKER_LANGUAGE CXX)