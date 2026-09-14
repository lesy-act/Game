cmake_minimum_required(VERSION 3.20)

project(SDL2Demo
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ============================================================
# TÌM SDL2
# ============================================================
find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2)

# ============================================================
# TÌM SDL2_image — fallback thủ công cho macOS
# ============================================================
# Thử cách 1: qua config package (Windows/Linux, một số macOS)
find_package(SDL2_image QUIET CONFIG)

if(NOT TARGET SDL2_image::SDL2_image)
    # Thử cách 2: qua module FindSDL2_image
    find_package(SDL2_image QUIET MODULE)
endif()

if(NOT TARGET SDL2_image::SDL2_image)
    # Thử cách 3: tìm thủ công (macOS Homebrew)
    message(STATUS "SDL2_image::SDL2_image target not found, using manual search...")

    find_path(SDL2_IMAGE_INCLUDE_DIR
        NAMES SDL_image.h
        HINTS
            /opt/homebrew/include      # Apple Silicon
            /usr/local/include         # Intel Mac
            /opt/homebrew/opt/sdl2_image/include
            /usr/local/opt/sdl2_image/include
        PATH_SUFFIXES SDL2
    )

    find_library(SDL2_IMAGE_LIBRARY
        NAMES SDL2_image
        HINTS
            /opt/homebrew/lib
            /usr/local/lib
            /opt/homebrew/opt/sdl2_image/lib
            /usr/local/opt/sdl2_image/lib
    )

    if(NOT SDL2_IMAGE_INCLUDE_DIR)
        message(FATAL_ERROR "SDL2_image.h not found. Cài bằng: brew install sdl2_image")
    endif()

    if(NOT SDL2_IMAGE_LIBRARY)
        message(FATAL_ERROR "libSDL2_image not found. Cài bằng: brew install sdl2_image")
    endif()

    # Tạo imported target để dùng giống SDL2_image::SDL2_image
    add_library(SDL2_image::SDL2_image UNKNOWN IMPORTED)
    set_target_properties(SDL2_image::SDL2_image PROPERTIES
        IMPORTED_LOCATION "${SDL2_IMAGE_LIBRARY}"
        INTERFACE_INCLUDE_DIRECTORIES "${SDL2_IMAGE_INCLUDE_DIR}"
    )

    message(STATUS "SDL2_image include: ${SDL2_IMAGE_INCLUDE_DIR}")
    message(STATUS "SDL2_image library: ${SDL2_IMAGE_LIBRARY}")
endif()

# ============================================================
# EXECUTABLE
# ============================================================
add_executable(SDL2Demo
    src/main.cpp
    src/App/App.cpp
    src/Texturemanager/TextureManager.cpp
    src/Player.cpp
)

target_include_directories(SDL2Demo
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(SDL2Demo
    PRIVATE
        SDL2::SDL2
        SDL2_image::SDL2_image
)