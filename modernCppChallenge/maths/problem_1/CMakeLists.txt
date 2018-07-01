cmake_minimum_required (VERSION 3.5)

project(modernCppProb1)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++11")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")
set (CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})


# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")


# target_sources(modernCppProb1 PUBLIC "${PROJECT_SOURCE_DIR}/src/prob1.cpp")

add_executable(modernCppProb1 ${PROJECT_SOURCE_DIR}/src/prob1.cpp)