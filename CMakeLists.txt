cmake_minimum_required(VERSION 3.31)
project(lodis)

set(CMAKE_CXX_STANDARD 20)

add_executable(lodis src/main.cpp
        src/lodis/data_item.cpp
        src/lodis/data_item.h
        src/lodis/in_memory_db.cpp
        src/lodis/in_memory_db.h)
