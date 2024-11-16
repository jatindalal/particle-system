#pragma once

#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/VertexArray.hpp"
#include <stddef.h>

class ParticleSystem
{
public:
    struct Particle {
        sf::Vector2f velocity;
        int lifetime;
    };

    ParticleSystem(size_t num_particles, float c_x, float c_y);

    void reset_particles();
    void reset_particle(size_t index);
    void update(int c_x, int c_y, int size, sf::Color color,
                size_t num_particles, bool multi_color);
    sf::VertexArray& get_vertices();

private:
    size_t m_num_particles;

    std::vector<Particle> m_particles;
    sf::VertexArray m_vertices;

    // Particle properties
    sf::Color m_color;
    float m_size, m_x, m_y;
    bool m_multi_color;
};
