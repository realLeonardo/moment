cmake_minimum_required(VERSION 3.17)
project(moment)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_HEADERS
        src/moment.h
        src/moment_utils.h)

set(PROJECT_SOURCES
        src/moment.cpp
        src/moment_utils.cpp
        )

set(PROJECT_TESTCASES
        test/chrono-test.h
        test/main.cpp
        )

# add_library(moment STATIC ${PROJECT_HEADERS} ${PROJECT_SOURCES})
add_executable(moment_e ${PROJECT_HEADERS} ${PROJECT_SOURCES} ${PROJECT_TESTCASES})

# target_link_libraries(moment ${CMAKE_SOURCE_DIR}/libmoment.a)