#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

#include <imgui-SFML.h>
#include <imgui.h>

#include "particle_system.h"

class Handler
{
public:
    Handler();
    void run();
private:
    ImVec4 m_color;
    int m_size, m_cx, m_cy;
    int m_num_particles;
    bool m_multi_colour;
    ParticleSystem p;

    sf::RenderWindow m_window;
    sf::Clock m_clock;
};
