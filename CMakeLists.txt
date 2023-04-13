cmake_minimum_required(VERSION 3.7)

set(PROJECT_NAME "MyFirstProject")

project(
        ${PROJECT_NAME}
        VERSION 0.1
        DESCRIPTION "An example project with CMake"
        LANGUAGES CXX)


set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

# tells cmake to look in these directories for another cmake config file
add_subdirectory(src)
add_subdirectory(resources)
add_subdirectory(apps)