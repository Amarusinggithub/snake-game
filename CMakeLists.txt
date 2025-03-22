cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(SDL3SnakeGame)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL3 REQUIRED)
include_directories(${SDL3_INCLUDE_DIRS} src )

add_executable(SnakeGame src/main.cpp src/game.cpp src/snake.cpp src/food.cpp src/globals.cpp )
string(STRIP ${SDL3_LIBRARIES} SDL3_LIBRARIES)
target_link_libraries(SnakeGame ${SDL3_LIBRARIES})