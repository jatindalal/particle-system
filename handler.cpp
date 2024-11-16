#include "handler.h"

Handler::Handler()
    : m_window(sf::VideoMode({800, 600}), "Particle System")
    , m_size(1)
    , m_multi_colour(false)
    , m_num_particles(10000)
    , m_color(0.0f, 1.0f, 0.6f, 1.0f)
    , p(m_num_particles, 800 / 2, 600 / 2)
{
    m_window.setVerticalSyncEnabled(true);
    (void)ImGui::SFML::Init(m_window);

    m_cx = (m_window.getSize().x / 2);
    m_cy = (m_window.getSize().y / 2);
}

void Handler::run()
{
    while (m_window.isOpen()) {
        while (const std::optional event = m_window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) m_window.close();
            ImGui::SFML::ProcessEvent(m_window, event.value());
        }

        ImGui::SFML::Update(m_window, m_clock.restart());

        ImGui::Begin("Particles");
        ImGui::Button("Particle System");
        ImGui::ColorEdit4("Particle Color", (float*)&m_color);
        ImGui::SliderInt("Size", &m_size, 1, 40);
        ImGui::SliderInt("Position x", &m_cx, 0, m_window.getSize().x);
        ImGui::SliderInt("Position y", &m_cy, 0, m_window.getSize().y);
        ImGui::SliderInt("Num Particles", &m_num_particles, 1000, 100000);
        ImGui::Checkbox("Multi Color", &m_multi_colour);
        ImGui::End();

        sf::Color particle_color((int)(m_color.x * 255), (int)(m_color.y * 255),
                                 (int)(m_color.z * 255), (int)(m_color.w * 255));
        p.update(m_cx, m_cy, m_size, particle_color, m_num_particles, m_multi_colour);

        m_window.clear(sf::Color(0, 0, 0));
        m_window.draw(p.get_vertices());

        ImGui::SFML::Render(m_window);
        m_window.display();

    }
    ImGui::SFML::Shutdown();
}
