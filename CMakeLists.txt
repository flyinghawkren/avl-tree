cmake_minimum_required(VERSION 3.5)

project(AVLTree)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)
file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.*)

add_executable(${PROJECT_NAME} ${SRC_FILES})