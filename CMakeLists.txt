cmake_minimum_required(VERSION 2.8.4)
project(algospot)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(
    GLOB_RECURSE
    SRC_FILES
    ${PROJECT_SOURCE_DIR}/problems/*.cpp
    ${PROJECT_SOURCE_DIR}/algospot-driver/*.cpp
    ${PROJECT_SOURCE_DIR}/algospot-driver/*.h
)

add_definitions(-DDRIVER)
add_executable(algospot ${SRC_FILES})