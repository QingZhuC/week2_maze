cmake_minimum_required(VERSION 3.20)

project(main)

add_executable(
    ${PROJECT_NAME}
    src/main.cpp
    src/control.cpp
    src/map.cpp
    src/character.cpp
    
)