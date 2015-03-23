cmake_minimum_required(VERSION 2.8.4)
project(lut_lang)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/Lexer.cpp
    src/Lexer.h
    src/lut.cpp)

add_executable(lut_lang ${SOURCE_FILES})