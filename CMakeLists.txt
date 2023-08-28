cmake_minimum_required(VERSION 3.26)
project(Launcher)


set(CMAKE_CXX_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR ./SFML-2.6.0/lib/cmake/SFML)


find_package(SFML COMPONENTS system window graphics audio REQUIRED)

include_directories(C:/Users/evgen/CLionProjects/SFML-2.6.0/include)

add_subdirectory(src)

target_link_libraries(Launcher sfml-graphics sfml-audio)