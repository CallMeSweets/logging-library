cmake_minimum_required(VERSION 3.21)
project(LoggerLibrary)

set(CMAKE_CXX_STANDARD 23)

set(SOURCE_FILES main.cpp Logger.h)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(LoggerLibrary ${SOURCE_FILES})
target_link_libraries(LoggerLibrary PRIVATE Threads::Threads)

#add_library(LoggerLibrary ${SOURCE_FILES})
