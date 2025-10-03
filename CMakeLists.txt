cmake_minimum_required(VERSION 3.20)

project(main)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

include_directories(include)

add_executable(
    ${PROJECT_NAME}
    src/main.cpp
    src/control.cpp
    src/map.cpp
    src/character.cpp
    src/GameStart.cpp
    src/judge.cpp
    src/UI.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)