cmake_minimum_required(VERSION 3.18)
project(raspi VERSION 0.0.1)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} SYSTEM INTERFACE include)

include(CTest)
if (BUILD_TESTING) # option is created by CTest
    enable_testing()
    add_subdirectory(tests)
endif ()