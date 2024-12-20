cmake_minimum_required(VERSION 3.28)
project(connect_4)

set(CMAKE_CXX_STANDARD 23)

find_package(fmt)

include_directories(include include/players)
add_subdirectory(src)

add_executable(${PROJECT_NAME} main.cpp ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} fmt::fmt)

