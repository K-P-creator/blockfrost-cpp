cmake_minimum_required(VERSION 3.16)
project(blockfrost-cpp VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# ===============================
# Dependencies
# ===============================

set(BUILD_SHARED_LIBS OFF)         # Static libraries only
set(CPR_BUILD_SHARED_LIBS OFF)     # Force static cpr build

# CPR (C++ Requests)
set(CPR_USE_SYSTEM_CURL OFF)
FetchContent_Declare(
  cpr
  GIT_REPOSITORY https://github.com/libcpr/cpr.git
  GIT_TAG 1.10.4
)
FetchContent_MakeAvailable(cpr)

# GoogleTest
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

# ===============================
# Library
# ===============================

file(GLOB_RECURSE SDK_SOURCES
    src/*.cpp
    src/cardano/*.cpp
)

# Exclude main.cpp
list(REMOVE_ITEM SDK_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

add_library(blockfrost_sdk STATIC ${SDK_SOURCES})

target_include_directories(blockfrost_sdk
    PUBLIC
        ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(blockfrost_sdk
    PUBLIC
        cpr::cpr
)

# ===============================
# Demo Executable (optional)
# ===============================

if(EXISTS "${PROJECT_SOURCE_DIR}/src/main.cpp")
    add_executable(blockfrost_demo src/main.cpp)
    target_link_libraries(blockfrost_demo PRIVATE blockfrost_sdk)
endif()

# ===============================
# Unit Tests
# ===============================

file(GLOB TEST_SOURCES tests/test_*.cpp)

add_executable(test_blockfrost ${TEST_SOURCES})

target_include_directories(test_blockfrost
    PRIVATE
        ${PROJECT_SOURCE_DIR}/tests
)

target_link_libraries(test_blockfrost
    PRIVATE
        blockfrost_sdk
        gtest_main
)

set_target_properties(test_blockfrost PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/tests
)

include(GoogleTest)
gtest_add_tests(TARGET test_blockfrost
                TEST_PREFIX ""
                TEST_WORKING_DIR ${CMAKE_BINARY_DIR}/bin/tests
                AUTO)

add_custom_target(run_all_tests
    DEPENDS test_blockfrost
)
