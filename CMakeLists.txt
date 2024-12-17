cmake_minimum_required(VERSION 3.30)
project(connect_4)

set(CMAKE_CXX_STANDARD 23)

include_directories(include include/players)
add_subdirectory(src)

add_executable(connect_4 main.cpp)
