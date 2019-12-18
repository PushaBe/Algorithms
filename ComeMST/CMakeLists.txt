cmake_minimum_required(VERSION 3.15)
project(ComeMST)

set(CMAKE_CXX_STANDARD 17)

add_executable(ComeMST main.cpp RandomGenerator.cpp RandomGenerator.h MSTKruskal.cpp MSTKruskal.h DSU.cpp DSU.h DFS.cpp DFS.h)