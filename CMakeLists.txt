cmake_minimum_required(VERSION 3.6)
project(B_Tree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c btree.c btree.h demo.c linklist.c linklist.h)
add_executable(B_Tree ${SOURCE_FILES})