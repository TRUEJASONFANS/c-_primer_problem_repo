
include_directories(..)

add_executable(container_test main.cpp)

target_link_libraries(container_test container)

add_executable(tuple_test tuple_test.cpp)