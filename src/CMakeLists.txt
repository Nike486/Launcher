cmake_minimum_required(VERSION 3.25)

include_directories("../include")

set(scrFiles
        main.cpp
        Game.cpp
        )

add_executable(Launcher ${scrFiles})