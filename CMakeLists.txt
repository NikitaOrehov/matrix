cmake_minimum_required(VERSION 3.10)
project(matrix
        LANGUAGES CXX)
set(CMake_CXX_FLAGS "${CMake_CXX_FLAGS} - std=17++")
include_directories(function_matrix)
add_subdirectory(function_matrix)
add_executable(main main.cpp)
include_directories(decision_CLY)
add_subdirectory(decision_CLY)

target_link_libraries(main function_matrix decision_CLY)


