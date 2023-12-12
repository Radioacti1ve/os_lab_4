cmake_minimum_required(VERSION 3.10)

project(OS_lab4)

set(CMAKE_CXX_STANDARD 20)

add_library(real1 SHARED real1.cpp)
add_library(real2 SHARED real2.cpp)

add_executable(first main1.cpp)
target_link_libraries(first PRIVATE real1)

add_executable(second main2.cpp)
target_link_libraries(second PRIVATE real2)
