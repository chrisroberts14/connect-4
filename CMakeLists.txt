cmake_minimum_required(VERSION 3.30)
project(connect_4)

set(CMAKE_CXX_STANDARD 23)

add_executable(connect_4
    main.cpp game.cpp game.h player.cpp player.h board.cpp board.h)
