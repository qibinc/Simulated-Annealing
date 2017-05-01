cmake_minimum_required(VERSION 3.7)
project(SA)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp SA.cpp SA.h StateImp.cpp StateImp.h TSPSA.cpp TSPSA.h TSPStateImp.cpp TSPStateImp.h)
add_executable(SA ${SOURCE_FILES})