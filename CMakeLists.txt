cmake_minimum_required(VERSION 3.27)

project(root)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED Off)
set (CMAKE_CXX_EXTENSIONS Off)

add_subdirectory(src)
add_subdirectory(test)
