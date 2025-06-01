cmake_minimum_required(VERSION 3.10)

project(Expression LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

set(ALL_FILES ${SOURCES} ${HEADERS})

add_executable(Expression ${ALL_FILES})
add_executable(main ${ALL_FILES})