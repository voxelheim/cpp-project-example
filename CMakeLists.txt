# PROJECT SETTINGS

cmake_minimum_required(VERSION 3.1)

project(cpp-project-example LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# COVERAGE

option(CODE_COVERAGE "Enable coverage reporting" OFF)

add_library(coverage_config INTERFACE)

if(CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(
        coverage_config INTERFACE
        -O0        # no optimization
        -g         # generate debug info
        --coverage # sets all required flags
    )
    if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.13)
        target_link_options(coverage_config INTERFACE --coverage)
    else()
        target_link_libraries(coverage_config INTERFACE --coverage)
    endif()
endif()

# LIBRARY

set(src_files src/example.cpp)
set(include_files include/example.hpp)

add_library(example STATIC ${src_files} ${include_files})
target_include_directories(example PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(example PUBLIC coverage_config)

# TEST

option (BUILD_TESTING "Build the testing tree." ON)

set(test_files test/example_test.cpp)

if (BUILD_TESTING)
    enable_testing()
    add_executable(tests ${test_files})
    target_link_libraries(tests PRIVATE example)
    add_test(NAME test_example COMMAND tests)
endif()

