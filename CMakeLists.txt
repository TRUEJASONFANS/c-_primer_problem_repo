cmake_minimum_required(VERSION 3.21)
project(c___primer_problems)

set(CMAKE_CXX_STANDARD 11)

add_executable(c___primer_problems main.cpp MSharePtr.h template/debug.h template/remove_reference.h)
