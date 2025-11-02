
#include "Illustrator.h"
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>

void Illustrator::draw_voltage_source(VoltageSource& vs) {
    float x = globalx + (vs.position.x * scale);
    float y = globaly + (vs.position.y * scale);

    float body_radius = scale;
    sf::CircleShape body(body_radius);
    body.setFillColor(sf::Color(0, 0, 0));
    body.setOutlineThickness(1.0f);
    body.setOutlineColor(sf::Color(255, 255, 255));
    body.setPosition(sf::Vector2f(x - scale, y - scale));
    window->draw(body);

    float connection_radius = 0.08 * scale;
    sf::CircleShape connection(connection_radius);
    connection.setFillColor(sf::Color(255, 255, 255));
    if ((vs.dir == 0) || (vs.dir == 2)) {
        connection.setPosition(sf::Vector2f(x - connection_radius, y - scale - connection_radius));
        window->draw(connection);
        connection.setPosition(sf::Vector2f(x - connection_radius, y + scale - connection_radius));
        window->draw(connection);
    }
    else {
        connection.setPosition(sf::Vector2f(x - scale - connection_radius, y - connection_radius));
        window->draw(connection);
        connection.setPosition(sf::Vector2f(x + scale - connection_radius, y - connection_radius));
        window->draw(connection);
    }

    if (vs.dir == 0) {
        std::vector<sf::Vertex> symbols = {
            sf::Vertex{sf::Vector2f(x + 0.0f * scale, y - 0.7f * scale)},
            sf::Vertex{sf::Vector2f(x + 0.0f * scale, y - 0.3f * scale)},
            sf::Vertex{sf::Vector2f(x - 0.2f * scale, y - 0.5f * scale)},
            sf::Vertex{sf::Vector2f(x + 0.2f * scale, y - 0.5f * scale)},
            sf::Vertex{sf::Vector2f(x - 0.2f * scale, y + 0.5f * scale)},
            sf::Vertex{sf::Vector2f(x + 0.2f * scale, y + 0.5f * scale)},
        };
        window->draw(&symbols[0], symbols.size(), sf::PrimitiveType::Lines);
    }
    if (vs.dir == 1) {
        std::vector<sf::Vertex> symbols = {
            sf::Vertex{sf::Vector2f(x + 0.3f * scale, y - 0.0f * scale)},
            sf::Vertex{sf::Vector2f(x + 0.7f * scale, y - 0.0f * scale)},
            sf::Vertex{sf::Vector2f(x + 0.5f * scale, y - 0.2f * scale)},
            sf::Vertex{sf::Vector2f(x + 0.5f * scale, y + 0.2f * scale)},
            sf::Vertex{sf::Vector2f(x - 0.5f * scale, y + 0.2f * scale)},
            sf::Vertex{sf::Vector2f(x - 0.5f * scale, y - 0.2f * scale)},
        };
        window->draw(&symbols[0], symbols.size(), sf::PrimitiveType::Lines);
    }
    if (vs.dir == 2) {
        std::vector<sf::Vertex> symbols = {
            sf::Vertex{sf::Vector2f(x + 0.0f * scale, y + 0.7f * scale)},
            sf::Vertex{sf::Vector2f(x + 0.0f * scale, y + 0.3f * scale)},
            sf::Vertex{sf::Vector2f(x - 0.2f * scale, y + 0.5f * scale)},
            sf::Vertex{sf::Vector2f(x + 0.2f * scale, y + 0.5f * scale)},
            sf::Vertex{sf::Vector2f(x - 0.2f * scale, y - 0.5f * scale)},
            sf::Vertex{sf::Vector2f(x + 0.2f * scale, y - 0.5f * scale)},
        };
        window->draw(&symbols[0], symbols.size(), sf::PrimitiveType::Lines);
    }
    if (vs.dir == 3) {
        std::vector<sf::Vertex> symbols = {
            sf::Vertex{sf::Vector2f(x - 0.3f * scale, y - 0.0f * scale)},
            sf::Vertex{sf::Vector2f(x - 0.7f * scale, y - 0.0f * scale)},
            sf::Vertex{sf::Vector2f(x - 0.5f * scale, y - 0.2f * scale)},
            sf::Vertex{sf::Vector2f(x - 0.5f * scale, y + 0.2f * scale)},
            sf::Vertex{sf::Vector2f(x + 0.5f * scale, y + 0.2f * scale)},
            sf::Vertex{sf::Vector2f(x + 0.5f * scale, y - 0.2f * scale)},
        };
        window->draw(&symbols[0], symbols.size(), sf::PrimitiveType::Lines);
    }

    sf::Text text(*font);
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << vs.voltage;
    std::string myString = oss.str();
    text.setString(oss.str() + "V");
    text.setCharacterSize(scale * 0.7f);
    text.setFillColor(sf::Color::White);
    if ((vs.dir == 0) || (vs.dir == 2)) {
        text.setPosition(sf::Vector2f(x + (scale * 1.2f), y - (scale * 0.47f)));
    }
    else {
        text.setPosition(sf::Vector2f(x - (text.getLocalBounds().size.x * 0.5f), y - (scale * 2.0f)));
    }
    window->draw(text);
}

