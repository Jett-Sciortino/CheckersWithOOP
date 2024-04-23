cmake_minimum_required(VERSION 3.26)
project(CheckersWithOOP)

set(CMAKE_CXX_STANDARD 17)

add_executable(CheckersWithOOP main.cpp
        Piece.h
        Piece.cpp
        Move.h
        Move.cpp
        Board.h
        Board.cpp
        Player.h
        Player.cpp
        Coordinate.cpp
        Coordinate.h
        TextColor.h)