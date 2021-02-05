cmake_minimum_required(VERSION 3.17)

project(matrix)

set(CMAKE_CXX_STANDART 17)

if (MSVC)
    add_compile_options(/EHsc)
endif()

add_executable(${CMAKE_PROJECT_NAME})

target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    src/matrix.cpp
    main.cpp)