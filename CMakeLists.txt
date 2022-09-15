cmake_minimum_required(VERSION 3.23)
project(aux-bill)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp input_parser.cpp input_parser.hpp)

