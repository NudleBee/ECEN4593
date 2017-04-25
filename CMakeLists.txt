cmake_minimum_required(VERSION 3.7)
project(ECEN4593)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp src/fetch.cpp src/fetch.h src/execute.cpp src/execute.h src/accessMem.cpp src/accessMem.h src/writeBack.cpp src/writeBack.h src/decode.cpp src/decode.h)
add_executable(ECEN4593 ${SOURCE_FILES})