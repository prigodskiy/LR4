cmake_minimum_required(VERSION 3.15)
project(DataStructures LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

if(CMAKE_BUILD_TYPE STREQUAL "Coverage")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage -O0 -g")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -O0 -g")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

include(FetchContent)
FetchContent_Declare(googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(INSTALL_GTEST OFF)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

enable_testing()
include_directories(${CMAKE_SOURCE_DIR}/include)

set(C_SOURCES src/stack.c src/queue.c src/tree.c)

add_executable(test_stack tests/test_stack.cpp ${C_SOURCES})
target_link_libraries(test_stack PRIVATE gtest gtest_main)
gtest_discover_tests(test_stack)

add_executable(test_queue tests/test_queue.cpp ${C_SOURCES})
target_link_libraries(test_queue PRIVATE gtest gtest_main)
gtest_discover_tests(test_queue)

add_executable(test_tree tests/test_tree.cpp ${C_SOURCES})
target_link_libraries(test_tree PRIVATE gtest gtest_main)
gtest_discover_tests(test_tree)

add_executable(test_tree_cpp tests/test_tree_cpp.cpp src/tree.cpp)
target_link_libraries(test_tree_cpp PRIVATE gtest gtest_main)
gtest_discover_tests(test_tree_cpp)

add_executable(main main.c ${C_SOURCES})