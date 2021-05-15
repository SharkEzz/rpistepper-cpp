cmake_minimum_required(VERSION 3.20)

project(rpistepper VERSION 0.1)

add_library(rpistepper SHARED src/stepper.cpp)

set_target_properties(rpistepper PROPERTIES VERSION 0.1 SOVERSION 1 PUBLIC_HEADER include/stepper.hpp)

target_include_directories(rpistepper PUBLIC include src)
target_link_libraries(rpistepper pigpio rt)

install(TARGETS rpistepper LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} PUBLIC_HEADER_DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES ${CMAKE_BINARY_DIR}/rpistepper.pc DESTINATION ${CMAKE_INSTALLDATAROOTDIR}/pkgconfig)
