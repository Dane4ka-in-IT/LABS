cmake_minimum_required(VERSION 3.10)
project(binary_to_hex)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(binary_to_hex main.cpp)