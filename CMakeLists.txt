cmake_minimum_required(VERSION 3.27)
project(BotGM)

set(CMAKE_CXX_STANDARD 23)

add_executable(BotGM main.cpp
        Bitboard.cpp
        FenSupporter.cpp
        board.cpp)
