cmake_minimum_required(VERSION 3.31)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        DynamicArray.h
        Stack.h
        SingleLinkedList.h
)
