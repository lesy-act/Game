cmake_minimum_required(VERSION 3.20)

project(SDL2Demo
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2)

add_executable(SDL2Demo
    src/main.cpp
    src/App.cpp
)

target_include_directories(SDL2Demo
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(SDL2Demo
    PRIVATE
        SDL2::SDL2
)