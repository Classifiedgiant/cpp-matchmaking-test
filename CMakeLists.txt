cmake_minimum_required(VERSION 3.27)

project(root)

set (CMAKE_CXX_STANDARD 23)
set (CMAKE_CXX_STANDARD_REQUIRED On)
set (CMAKE_CXX_EXTENSIONS Off)

add_subdirectory(src)
add_subdirectory(test)
