cmake_minimum_required(VERSION 3.17)

project(matrix)

set(CMAKE_CXX_STANDART 17)

add_executable(${CMAKE_PROJECT_NAME})

target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    main.cpp)