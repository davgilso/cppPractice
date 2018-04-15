cmake_minimum_required (VERSION 3.5)

project (myFirstDbus)

set (client_source_dir "${PROJECT_SOURCE_DIR}/client/src/")
set (server_source_dir "${PROJECT_SOURCE_DIR}/server/src/")

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14 -I/usr/include/dbus-1.0/ -I/usr/lib/x86_64-linux-gnu/dbus-1.0/include/")

file (GLOB source_files "${client_source_dir}/*.cpp" "${server_source_dir}/*.cpp")

add_executable (myFirstDbus ${source_files})
target_link_libraries(myFirstDbus "dbus-1")
