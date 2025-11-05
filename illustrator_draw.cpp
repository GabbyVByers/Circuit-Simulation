
#include "Illustrator.h"
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>

void Illustrator::draw_voltage_source(VoltageSource& voltage_source) {
    sf::Vector2f screen_pos = world_to_screen(voltage_source.world_position);

    float body_radius = scale;
    sf::CircleShape body(body_radius);
    body.setFillColor(sf::Color(0, 0, 0));
    body.setOutlineThickness(1.0f);
    body.setOutlineColor(sf::Color(255, 255, 255));
    body.setPosition(sf::Vector2f(screen_pos.x - scale, screen_pos.y - scale));
    window->draw(body);

    if (voltage_source.dir == 0) {
        std::vector<sf::Vertex> symbols = {
            sf::Vertex{sf::Vector2f(screen_pos.x + 0.0f * scale, screen_pos.y - 0.7f * scale)},
            sf::Vertex{sf::Vector2f(screen_pos.x + 0.0f * scale, screen_pos.y - 0.3f * scale)},
            sf::Vertex{sf::Vector2f(screen_pos.x - 0.2f * scale, screen_pos.y - 0.5f * scale)},
            sf::Vertex{sf::Vector2f(screen_pos.x + 0.2f * scale, screen_pos.y - 0.5f * scale)},
            sf::Vertex{sf::Vector2f(screen_pos.x - 0.2f * scale, screen_pos.y + 0.5f * scale)},
            sf::Vertex{sf::Vector2f(screen_pos.x + 0.2f * scale, screen_pos.y + 0.5f * scale)},
        };
        window->draw(&symbols[0], symbols.size(), sf::PrimitiveType::Lines);
    }
    if (voltage_source.dir == 1) {
        std::vector<sf::Vertex> symbols = {
            sf::Vertex{sf::Vector2f(screen_pos.x + 0.3f * scale, screen_pos.y - 0.0f * scale)},
            sf::Vertex{sf::Vector2f(screen_pos.x + 0.7f * scale, screen_pos.y - 0.0f * scale)},
            sf::Vertex{sf::Vector2f(screen_pos.x + 0.5f * scale, screen_pos.y - 0.2f * scale)},
            sf::Vertex{sf::Vector2f(screen_pos.x + 0.5f * scale, screen_pos.y + 0.2f * scale)},
            sf::Vertex{sf::Vector2f(screen_pos.x - 0.5f * scale, screen_pos.y + 0.2f * scale)},
            sf::Vertex{sf::Vector2f(screen_pos.x - 0.5f * scale, screen_pos.y - 0.2f * scale)},
        };
        window->draw(&symbols[0], symbols.size(), sf::PrimitiveType::Lines);
    }
    if (voltage_source.dir == 2) {
        std::vector<sf::Vertex> symbols = {
            sf::Vertex{sf::Vector2f(screen_pos.x + 0.0f * scale, screen_pos.y + 0.7f * scale)},
            sf::Vertex{sf::Vector2f(screen_pos.x + 0.0f * scale, screen_pos.y + 0.3f * scale)},
            sf::Vertex{sf::Vector2f(screen_pos.x - 0.2f * scale, screen_pos.y + 0.5f * scale)},
            sf::Vertex{sf::Vector2f(screen_pos.x + 0.2f * scale, screen_pos.y + 0.5f * scale)},
            sf::Vertex{sf::Vector2f(screen_pos.x - 0.2f * scale, screen_pos.y - 0.5f * scale)},
            sf::Vertex{sf::Vector2f(screen_pos.x + 0.2f * scale, screen_pos.y - 0.5f * scale)},
        };
        window->draw(&symbols[0], symbols.size(), sf::PrimitiveType::Lines);
    }
    if (voltage_source.dir == 3) {
        std::vector<sf::Vertex> symbols = {
            sf::Vertex{sf::Vector2f(screen_pos.x - 0.3f * scale, screen_pos.y - 0.0f * scale)},
            sf::Vertex{sf::Vector2f(screen_pos.x - 0.7f * scale, screen_pos.y - 0.0f * scale)},
            sf::Vertex{sf::Vector2f(screen_pos.x - 0.5f * scale, screen_pos.y - 0.2f * scale)},
            sf::Vertex{sf::Vector2f(screen_pos.x - 0.5f * scale, screen_pos.y + 0.2f * scale)},
            sf::Vertex{sf::Vector2f(screen_pos.x + 0.5f * scale, screen_pos.y + 0.2f * scale)},
            sf::Vertex{sf::Vector2f(screen_pos.x + 0.5f * scale, screen_pos.y - 0.2f * scale)},
        };
        window->draw(&symbols[0], symbols.size(), sf::PrimitiveType::Lines);
    }

    sf::Text text(*font);
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << voltage_source.voltage;
    std::string myString = oss.str();
    text.setString(oss.str() + "V");
    text.setCharacterSize(scale * 0.7f);
    text.setFillColor(sf::Color::White);
    if ((voltage_source.dir == 0) || (voltage_source.dir == 2)) {
        text.setPosition(sf::Vector2f(screen_pos.x + (scale * 1.2f), screen_pos.y - (scale * 0.47f)));
    }
    else {
        text.setPosition(sf::Vector2f(screen_pos.x - (text.getLocalBounds().size.x * 0.5f), screen_pos.y - (scale * 2.0f)));
    }
    window->draw(text);
}

void Illustrator::draw_resistor(Resistor& resistor) {
    sf::Vector2f screen_pos = world_to_screen(resistor.world_position);

    if (resistor.dir == 1) {
        std::vector<sf::Vertex> symbols = {
            sf::Vertex{sf::Vector2f(screen_pos.x - (1.0f * scale), screen_pos.y + (0.0f * scale))},
            sf::Vertex{sf::Vector2f(screen_pos.x - (0.6f * scale), screen_pos.y + (0.0f * scale))},
            sf::Vertex{sf::Vector2f(screen_pos.x - (0.5f * scale), screen_pos.y + (0.5f * scale))},
            sf::Vertex{sf::Vector2f(screen_pos.x - (0.3f * scale), screen_pos.y - (0.5f * scale))},
            sf::Vertex{sf::Vector2f(screen_pos.x - (0.1f * scale), screen_pos.y + (0.5f * scale))},
            sf::Vertex{sf::Vector2f(screen_pos.x + (0.1f * scale), screen_pos.y - (0.5f * scale))},
            sf::Vertex{sf::Vector2f(screen_pos.x + (0.3f * scale), screen_pos.y + (0.5f * scale))},
            sf::Vertex{sf::Vector2f(screen_pos.x + (0.5f * scale), screen_pos.y - (0.5f * scale))},
            sf::Vertex{sf::Vector2f(screen_pos.x + (0.6f * scale), screen_pos.y + (0.0f * scale))},
            sf::Vertex{sf::Vector2f(screen_pos.x + (1.0f * scale), screen_pos.y + (0.0f * scale))},
        };
        window->draw(&symbols[0], symbols.size(), sf::PrimitiveType::LineStrip);
    }
    else {
        std::vector<sf::Vertex> symbols = {
            sf::Vertex{sf::Vector2f(screen_pos.x + (0.0f * scale), screen_pos.y - (1.0f * scale))},
            sf::Vertex{sf::Vector2f(screen_pos.x + (0.0f * scale), screen_pos.y - (0.6f * scale))},
            sf::Vertex{sf::Vector2f(screen_pos.x + (0.5f * scale), screen_pos.y - (0.5f * scale))},
            sf::Vertex{sf::Vector2f(screen_pos.x - (0.5f * scale), screen_pos.y - (0.3f * scale))},
            sf::Vertex{sf::Vector2f(screen_pos.x + (0.5f * scale), screen_pos.y - (0.1f * scale))},
            sf::Vertex{sf::Vector2f(screen_pos.x - (0.5f * scale), screen_pos.y + (0.1f * scale))},
            sf::Vertex{sf::Vector2f(screen_pos.x + (0.5f * scale), screen_pos.y + (0.3f * scale))},
            sf::Vertex{sf::Vector2f(screen_pos.x - (0.5f * scale), screen_pos.y + (0.5f * scale))},
            sf::Vertex{sf::Vector2f(screen_pos.x + (0.0f * scale), screen_pos.y + (0.6f * scale))},
            sf::Vertex{sf::Vector2f(screen_pos.x + (0.0f * scale), screen_pos.y + (1.0f * scale))},
        };
        window->draw(&symbols[0], symbols.size(), sf::PrimitiveType::LineStrip);
    }
    
    sf::Text text(*font);
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << resistor.resistance;
    std::string myString = oss.str();
    text.setString(oss.str() + "R");
    text.setCharacterSize(scale * 0.7f);
    text.setFillColor(sf::Color::White);
    if (resistor.dir == 0) {
        text.setPosition(sf::Vector2f(screen_pos.x + (scale * 0.7f), screen_pos.y - (scale * 0.47f)));
    }
    else {
        text.setPosition(sf::Vector2f(screen_pos.x - (text.getLocalBounds().size.x * 0.5f), screen_pos.y - (scale * 1.5f)));
    }
    window->draw(text);
}

void Illustrator::draw_ground() {

}

