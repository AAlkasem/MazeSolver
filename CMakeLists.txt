cmake_minimum_required(VERSION 3.17)
project(Assignment_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assignment_2
        src/main.cpp src/maze_solver.cpp src/maze_solver.h src/stack.cpp src/stack.h)
