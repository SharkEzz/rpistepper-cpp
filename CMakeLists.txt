cmake_minimum_required(VERSION 3.20)

project(rpistepper VERSION 0.1)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-Wall -Wextra -Werror -O2)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB_RECURSE RPISTEPPER_SOURCES src/*.cpp)

add_executable(rpistepper ${RPISTEPPER_SOURCES})
target_link_libraries(rpistepper -lpigpio -lrt)
