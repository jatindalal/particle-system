#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

#include <imgui-SFML.h>
#include <imgui.h>

int main (int argc, char *argv[]) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");
    window.setVerticalSyncEnabled(true);
    auto val = ImGui::SFML::Init(window);
    if (!val)
        return -1;

    sf::Clock delta_clock;
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) window.close();
            ImGui::SFML::ProcessEvent(window, event.value());
        }

        ImGui::SFML::Update(window, delta_clock.restart());

        ImGui::ShowDemoWindow();

        window.clear(sf::Color(0, 0, 0));

        ImGui::SFML::Render(window);
        window.display();

    }
    ImGui::SFML::Shutdown();
    return 0;
}
