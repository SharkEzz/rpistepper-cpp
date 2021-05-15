cmake_minimum_required(VERSION 3.20)

project(rpistepper VERSION 0.1)

add_library(rpistepper SHARED
    src/stepper.cpp
)

set_target_properties(rpistepper PROPERTIES VERSION 0.1)
set_target_properties(rpistepper PROPERTIES SOVERSION 0.1)
set_target_properties(rpistepper PROPERTIES PUBLIC_HEADER src/stepper.hpp)

target_include_directories(rpistepper PRIVATE include)
target_link_libraries(rpistepper pigpio rt)
