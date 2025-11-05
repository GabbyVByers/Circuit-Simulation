
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
                illustrator.click_on_component();
                illustrator.begin_new_node();
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

        illustrator.pan_screen();
        illustrator.draw_grid();
        illustrator.manage_new_node();
        illustrator.draw_wires();
        illustrator.draw_voltage_source(voltage_source);
        illustrator.draw_resistor(resistor);
        illustrator.draw_selection_bar();

        std::cout << illustrator.wires.size() << "\n";

        window.display();
    }

    return 0;
}

