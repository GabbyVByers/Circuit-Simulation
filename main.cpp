
#include "illustrator.h"

int main() {
    sf::RenderWindow window;
    window.create(sf::VideoMode({ 1920, 1080 }), "My Window");

    Illustrator illustrator(&window, 40.0f);

    VoltageSource voltage_source;
    voltage_source.world_position = sf::Vector2i(25, 10);
    voltage_source.voltage = 6.7;
    voltage_source.dir = 0;

    Resistor resistor;
    resistor.world_position = sf::Vector2i(30, 10);
    resistor.dir = 0;
    resistor.resistance = 34.67;


    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            if (event->is<sf::Event::MouseButtonPressed>()) {

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
        illustrator.pan_screen();
        illustrator.draw_grid();
        illustrator.draw_voltage_source(voltage_source);
        illustrator.draw_resistor(resistor);

        sf::CircleShape testPoint(10.0f);
        sf::Vector2f screen_pos_mouse = illustrator.get_screen_pos_mouse();
        testPoint.setPosition(sf::Vector2f(screen_pos_mouse.x - 10.0f, screen_pos_mouse.y - 10.0f));
        window.draw(testPoint);

        window.display();
    }

    return 0;
}

