cmake_minimum_required(VERSION 3.22)
project(ubuntu_playground)

set(CMAKE_CXX_STANDARD 17)
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG        v1.14.0
)

FetchContent_MakeAvailable(googletest)

enable_testing()
include_directories(.)

add_executable(playground main.cpp
        src/custom_string.h
        src/custom_string.cpp
        src/csv_file_dumper.h
        src/csv_file_dumper.cpp)

add_executable(test_custom_string test/test_custom_string.cpp
        src/custom_string.h
        src/custom_string.cpp)

target_include_directories(test_custom_string PUBLIC
        ${googletest_SOURCE_DIR}/googletest/include
)

target_link_libraries(test_custom_string PRIVATE gtest_main)