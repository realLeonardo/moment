cmake_minimum_required(VERSION 3.17)
project(moment)

set(CMAKE_CXX_STANDARD 17)

add_library(moment SHARED src/moment.h test/main.cpp)