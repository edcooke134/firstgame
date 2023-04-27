cmake_minimum_required(VERSION 3.7)

set(PROJECT_NAME "MyFirstProject")

project(
        ${PROJECT_NAME}
        VERSION 0.1
        DESCRIPTION "An example project with CMake"
        LANGUAGES C CXX)

include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)


# tells cmake to look in these directories for another cmake config file
add_subdirectory(src)
add_subdirectory(thirdparty/glad)
add_subdirectory(apps)