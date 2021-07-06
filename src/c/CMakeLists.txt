cmake_minimum_required(VERSION 3.17)
project(c)

set(CMAKE_C_COMPILER clang++)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++")

include_directories(.)

add_executable(c
        clipper.cpp
        clipper.h
        clipper.hpp
        clipper.cc main.c)
