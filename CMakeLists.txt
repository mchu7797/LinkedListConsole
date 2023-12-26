cmake_minimum_required(VERSION 3.27)
project(LinkedListConsole)

set(CMAKE_CXX_STANDARD 17)

add_executable(LinkedListConsole
               main.cpp
               node.h
               linked_list.h
               linked_list.cc)
