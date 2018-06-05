cmake_minimum_required(VERSION 3.10)
project(SkipListCPPVersion)

set(CMAKE_CXX_STANDARD 11)

add_executable(SkipListCPPVersion main.cpp node.cpp node.h skiplist.cpp skiplist.h BasicTest.cpp)