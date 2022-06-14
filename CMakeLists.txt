cmake_minimum_required(VERSION 3.20)
project(c___primer_problems)

set(CMAKE_CXX_STANDARD 11)

add_executable(c___primer_problems main.cpp MSharePtr.h template/debug.h memory/UniquePtrTest.cpp memory/UniquePtrTest.h memory/Movie.h enable_if/enable_if.h template/subTemplate.h)


add_executable(Enable_if_test enable_if/enable_if.h enable_if/main.cpp)

add_executable(MemoryTest memory/main.cpp)

add_executable(memoryAlign memory_align/main.cpp)

add_executable(ObjectOriented OO/main.cpp)

add_executable(VirtualFunctionAddress OO/virtual_address/main.cpp)

add_executable(explict_demo explict/main.cpp)

add_executable(function function/main.cpp)

add_executable(is_subclass_of template/is_sub_of/main.cpp template/is_sub_of/is_sub_class.h)

add_executable(unsigned_char string/unsigned_char/main.cpp string/unsigned_char/unsigned_char.h)

add_executable(singleton OO/singleton/main.cpp)

add_executable(LRUCache OO/LRUCache/main.cpp OO/LRUCache/LRUCache.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")

add_executable(avx avx/main.cpp)