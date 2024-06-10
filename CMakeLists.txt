cmake_minimum_required(VERSION 3.27)
project(BotGM)

set(CMAKE_CXX_STANDARD 23)

add_executable(BotGM main.cpp
        fenSupporter.cpp
        board.cpp
        fenSupporter.h
        board.h
        UCI/command.cpp
        UCI/command.h
        UCI/commandExecutor.cpp
        UCI/commandExecutor.h)
