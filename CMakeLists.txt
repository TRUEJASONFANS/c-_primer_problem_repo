cmake_minimum_required(VERSION 3.20)
project(c___primer_problems)

set(CMAKE_CXX_STANDARD 11)

add_executable(c___primer_problems main.cpp MSharePtr.h template/debug.h memory/UniquePtrTest.cpp memory/UniquePtrTest.h memory/Movie.h enable_if/enable_if.h enable_if/main.cpp)


add_executable(Enable_if_test enable_if/enable_if.h enable_if/main.cpp)

add_executable(MemoryTest memory/main.cpp)