cmake_minimum_required(VERSION 3.5)

project(proj)

set(IMGUI_SFML_FIND_SFML OFF)
set(IMGUI_DIR "${PROJECT_SOURCE_DIR}/imgui")

add_subdirectory(SFML)
add_subdirectory(imgui-sfml)

add_executable(proj
    main.cpp
    particle_system.cpp
    handler.cpp
)
target_link_libraries(proj PUBLIC
    ImGui-SFML::ImGui-SFML
)
