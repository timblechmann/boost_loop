cmake_minimum_required (VERSION 2.6) 
project (boost_loop) 

add_definitions(-std=c++11)

add_executable(loop_test libs/loop/tests/loop_test.cpp)
