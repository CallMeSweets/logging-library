cmake_minimum_required(VERSION 3.21)
project(ElasticFileConsoleLoggingTest)

set(CMAKE_CXX_STANDARD 20)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

add_executable(ElasticFileConsoleLoggingTest src/main.cpp)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG beb9e98806bb84bcc130a2cebfbcbbc6ce62b335) # The commit hash for 1.7.2. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_Declare(yaml-cpp GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
        GIT_TAG yaml-cpp-0.7.0)
FetchContent_MakeAvailable(cpr yaml-cpp)

include(FindPkgConfig)
find_package(LogLib REQUIRED)
include_directories(${CMAKE_CURRENT_LIST_DIR}/../LogLib/include/logger)
target_link_libraries(${PROJECT_NAME} ${LOGLIB_LIBRARY}  cpr::cpr yaml-cpp::yaml-cpp)