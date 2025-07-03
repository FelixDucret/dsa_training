cmake_minimum_required(VERSION 4.1.0)

set(GOOGLETEST_VERSION 1.17.0)

project(dsa_training LANGUAGES CXX)

enable_testing()

add_subdirectory(googletest)

include_directories(googletest/include)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(WORKING_DIRECTORY Leet_Code_Problems/1472_Design_Browser_History)

add_executable(DSA_training ${WORKING_DIRECTORY}/tests.cpp ${WORKING_DIRECTORY}/1472.cpp ${WORKING_DIRECTORY}/1472.hpp)

target_link_libraries(DSA_training PRIVATE gtest)

include(GoogleTest)

gtest_discover_tests(DSA_training)
