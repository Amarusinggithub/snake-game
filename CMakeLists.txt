cmake_minimum_required(VERSION 3.10)


project(SnakeGame)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

add_executable(snake_game "src/main.cpp" "src/game.cpp" "src/snake.cpp" "src/food.cpp")

find_package(SDL3 REQUIRED)
target_include_directories(snake_game PRIVATE ${CMAKE_SOURCE_DIR}/include)


include_directories(${SDL3_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/src)


target_link_libraries(snake_game ${SDL3_LIBRARIES})