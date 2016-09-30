cmake_minimum_required(VERSION 3.6)
project(tree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp tree.cpp tree.h)
add_executable(tree ${SOURCE_FILES})