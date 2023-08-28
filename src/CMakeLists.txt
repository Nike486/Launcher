cmake_minimum_required(VERSION 3.26)



include_directories("../include")
include(FetchContent)


set(scrFiles
        main.cpp
        Game.cpp
        Config.cpp
        SFMLContent.cpp
        SFMLClass.cpp
)


FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

add_executable(Launcher ${scrFiles})

target_link_libraries(Launcher nlohmann_json::nlohmann_json)