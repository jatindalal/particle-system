#include "particle_system.h"
#include <cstdlib>
#include <SFML/Graphics/VertexArray.hpp>

ParticleSystem::ParticleSystem(size_t num_particles, float c_x, float c_y)
    : m_num_particles(num_particles)
    , m_x(c_x)
    , m_y(c_y)
{
    m_multi_color = false;
    reset_particles();
}

void ParticleSystem::reset_particles()
{
    m_particles = std::vector<Particle>(m_num_particles);
    m_vertices = sf::VertexArray(sf::PrimitiveType::Triangles,
                                 m_num_particles * 3);
    for (size_t i = 0; i < m_num_particles; ++i) {
        reset_particle(i);
    }        
}

void ParticleSystem::reset_particle(size_t index)
{
    m_vertices[3 * index + 0].position = sf::Vector2f(m_x, m_y + m_size);
    m_vertices[3 * index + 1].position = sf::Vector2f(m_x + m_size, m_y);
    m_vertices[3 * index + 2].position = sf::Vector2f(m_x - m_size, m_y);
    if (!m_multi_color) {
        m_vertices[3 * index + 0].color = m_color;
        m_vertices[3 * index + 1].color = m_color;
        m_vertices[3 * index + 2].color = m_color;
    } else {
        sf::Color color(
            ((float) rand() / (RAND_MAX))*255,
            ((float) rand() / (RAND_MAX))*255,
            ((float) rand() / (RAND_MAX))*255,
            ((float) rand() / (RAND_MAX))*255
        );
        m_vertices[3 * index + 0].color = color;
        m_vertices[3 * index + 1].color = color;
        m_vertices[3 * index + 2].color = color;
    }

    auto& particle = m_particles[index];
    particle.velocity =
        sf::Vector2f(static_cast<float>(rand()) / (float)RAND_MAX * 8 - 4,
                     static_cast<float>(rand()) / (float)RAND_MAX * 8 - 4);
    particle.lifetime = 30 + rand() % 60;
}

void ParticleSystem::update(int c_x, int c_y, int size,
                            sf::Color color, size_t num_particles,
                            bool multi_color)
{
    if (num_particles != m_num_particles) {
        m_num_particles =  num_particles;
        reset_particles();
    }
    m_x = c_x;
    m_y = c_y;
    m_size = size;
    m_color = color;
    m_multi_color = multi_color;

    for (size_t i = 0; i < m_num_particles; ++i) {
        if (m_particles[i].lifetime == 0) reset_particle(i);

        m_vertices[3*i + 0].position += m_particles[i].velocity;
        m_vertices[3*i + 1].position += m_particles[i].velocity;
        m_vertices[3*i + 2].position += m_particles[i].velocity;
        --m_particles[i].lifetime;
    }
}

sf::VertexArray& ParticleSystem::get_vertices() {
    return m_vertices;
}

