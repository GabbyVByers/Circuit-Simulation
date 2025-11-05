
#include "illustrator.h"

int main() {
    sf::RenderWindow window; window.create(sf::VideoMode({ 1920, 1080 }), "My Window");
    Illustrator illustrator(&window, 40.0f);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scan::R) {
                    illustrator.rotate_currently_selected_component();
                }
            }
            if (event->is<sf::Event::MouseButtonPressed>()) {
                illustrator.click_on_component();
                illustrator.begin_new_node();
                illustrator.place_currently_selected_component();
            }
            if (event->is<sf::Event::MouseButtonReleased>()) {
                illustrator.confirm_new_node();
            }
            if (const auto* scroll = event->getIf<sf::Event::MouseWheelScrolled>()) {
                illustrator.zoom_scroll(scroll);
            }
            if (const auto* resized = event->getIf<sf::Event::Resized>()) {
                sf::FloatRect visible_area({ 0.0f, 0.0f }, sf::Vector2f(resized->size));
                window.setView(sf::View(visible_area));
            }
        }

        window.clear(sf::Color::Black);
        illustrator.run();
        window.display();

        std::cout << illustrator.voltage_sources.size() << "\n";
    }

    return 0;
}

