cmake_minimum_required(VERSION 3.20)
project(c___primer_problems)

set(CMAKE_CXX_STANDARD 17)

add_executable(c___primer_problems main.cpp MSharePtr.h template/debug.h memory/UniquePtrTest.cpp memory/UniquePtrTest.h memory/Movie.h enableIf/enable_if.h)


add_executable(Enable_if_test enableIf/enable_if.h enableIf/main.cpp)

add_executable(MemoryTest memory/main.cpp)

add_executable(memoryAlign memoryAlign/main.cpp)

add_executable(ObjectOriented OO/main.cpp)

add_executable(VirtualFunctionAddress OO/virtualAddress/main.cpp)

add_executable(explict_demo explict/main.cpp)

add_executable(function function/main.cpp function/stdvisit.h)

add_executable(is_subclass_of template/isSubOf/main.cpp template/isSubOf/isSubClass.h)

add_executable(unsigned_char string/unsigned_char/main.cpp string/unsigned_char/unsigned_char.h)

add_executable(singleton OO/singleton/main.cpp)

add_executable(LRUCache OO/lruCache/main.cpp OO/lruCache/LRUCache.h)

add_executable(IO IO/ofstream.h IO/main.cpp)

add_executable(Numerical numerical/main.cpp)

add_executable(Constructor OO/constructor/main.cpp)

add_executable(VirtualOverride OO/polymophic/virtualoverride/main.cpp)

add_executable(swap template/swap/main.cpp template/swap/Widget.h)

add_executable(private_acess template/private_access/main.cpp)

add_executable(testMove template/move/TestTemplateConstructor.cpp)

add_executable(compile_time_type_detection string/compile_time_detection/main.cpp)

add_executable(performance_insert_vs_emplace performance/main.cpp)

add_executable(double_issue_study double/main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")

add_executable(avx avx/main.cpp)

