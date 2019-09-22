cmake_minimum_required(VERSION 3.14)
project(c_linked_list)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 99)

add_subdirectory(googletest-master/googletest)

set(SOURCE_FILES test.cpp LinkedList.c)

add_executable(c_linked_list ${SOURCE_FILES})
target_link_libraries(c_linked_list gtest gtest_main)
include_directories(googletest-master/googletest/include ${CMAKE_CURRENT_SOURCE_DIR})