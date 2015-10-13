cmake_minimum_required(VERSION 3.2)
project(mosp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(mosp ${SOURCE_FILES} Map.cpp Map.h Tile.cpp Tile.h Coordinate.cpp Coordinate.h Living.cpp Living.h Object.cpp Object.h Move.cpp Move.h Pathfinder.cpp Pathfinder.h)