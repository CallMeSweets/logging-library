cmake_minimum_required(VERSION 3.21)
project(LoggerLibrary)

set(CMAKE_CXX_STANDARD 23)

set(HEADERS_FILES logger/Logger.h logger/model/Log.h logger/service/file/FileLoggingService.h logger/service/elastic/ElasticLoggingService.h)
set(SOURCES_FILES main.cpp logger/model/Log.cpp logger/service/file/FileLoggingService.cpp logger/service/elastic/ElasticLoggingService.cpp)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG beb9e98806bb84bcc130a2cebfbcbbc6ce62b335) # The commit hash for 1.7.2. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(LoggerLibrary ${SOURCES_FILES} ${HEADERS_FILES})
target_link_libraries(LoggerLibrary PRIVATE Threads::Threads cpr::cpr)

#add_library(LoggerLibrary ${SOURCE_FILES})
