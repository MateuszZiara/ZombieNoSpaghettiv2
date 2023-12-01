cmake_minimum_required(VERSION 3.26)
project(ZombieNoSpaghetti)

include(FetchContent)

set(BUILD_SHARED_LIBS  OFF)
set(CMAKE_CXX_STANDARD 17)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.6.1)
FETCHCONTENT_MAKEAVAILABLE(SFML)



add_executable(ZombieNoSpaghetti main.cpp
        Header/WindowConfig.h
        Source/WindowConfig.cpp
        Header/Player.h
        Source/Player.cpp
        Header/Collision.h
        Source/Collision.cpp
        Header/BitMap.h
        Source/BitMap.cpp
        Header/Button.h
        Source/Button.cpp
        Header/CustomButtons.h
        Source/CustomButtons.cpp
        Header/Animations.h
        Source/Animations.cpp
        Source/Arrow.cpp
        Header/Arrow.h
        Header/Engine.h
        Header/Zombie.h
)

target_link_libraries(ZombieNoSpaghetti sfml-graphics)