cmake_minimum_required(VERSION 3.9)
project(heap)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(SOURCES ${PROJECT_SOURCE_DIR}/source)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

option(BUILD_TESTS "Build unit tests" ON)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif(BUILD_TESTS)
