cmake_minimum_required(VERSION 2.8.12)
project(problem-solving)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

file(
    GLOB_RECURSE
    ALGOSPOT_SRC_FILES
    ${PROJECT_SOURCE_DIR}/problems/*.cpp
    ${PROJECT_SOURCE_DIR}/algospot-driver/*.cpp
    ${PROJECT_SOURCE_DIR}/algospot-driver/*.h
)
file(
    GLOB_RECURSE
    BOJ_SRC_FILES
    ${PROJECT_SOURCE_DIR}/boj/*.cpp
    ${PROJECT_SOURCE_DIR}/boj/*.h
)

add_definitions(-DDRIVER)
add_executable(algospot ${ALGOSPOT_SRC_FILES})
add_executable(boj ${BOJ_SRC_FILES})
