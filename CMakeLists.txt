cmake_minimum_required(VERSION 3.5)

project(proj)

set(IMGUI_SFML_FIND_SFML OFF)
set(IMGUI_DIR "${PROJECT_SOURCE_DIR}/imgui")
set(IMGUI_SFML_IMGUI_DEMO ON)

add_subdirectory(SFML)
add_subdirectory(imgui-sfml)

add_executable(proj
    main.cpp
)
target_link_libraries(proj PUBLIC
    ImGui-SFML::ImGui-SFML
)
