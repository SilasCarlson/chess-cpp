cmake_minimum_required(VERSION 4.1)
project(chess)

set(CMAKE_CXX_STANDARD 20)

add_executable(chess
        src/main.cpp
        src/Board.cpp
        src/Board.h
        src/Pieces/Piece.cpp
        src/Pieces/Piece.h
        src/BoardSquare.cpp
        src/BoardSquare.h
        src/Game.cpp
        src/Game.h
        src/Pieces/Pawn.cpp
        src/Pieces/Pawn.h
        src/Pieces/Rook.cpp
        src/Pieces/Rook.h
        src/Pieces/Bishop.cpp
        src/Pieces/Bishop.h
        src/Pieces/Knight.cpp
        src/Pieces/Knight.h
        src/Pieces/Queen.cpp
        src/Pieces/Queen.h
        src/Pieces/King.cpp
        src/Pieces/King.h
)
