
#include "illustrator.h"

void Illustrator::draw_selection_bar() {
	sf::RectangleShape rect_bar;
	rect_bar.setPosition(sf::Vector2f(0.0f, 0.0f));
	rect_bar.setSize(sf::Vector2f((float)window->getSize().x, 50.0f * 3.0f));
    rect_bar.setFillColor({ 20, 20, 20 });
	window->draw(rect_bar);
    draw_dummy_voltage_source();
    draw_dummy_resistor();
    draw_dummy_wire();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
        voltage_source_is_selected = false;
        resistor_is_selected = false;
        node_tool_is_selected = false;
    }

    sf::RectangleShape box;
    box.setFillColor({ 0, 0, 0, 0 });
    box.setOutlineThickness(1.0f);
    box.setOutlineColor({ 255, 255, 255 });
    box.setSize(sf::Vector2f(50.0f * 2.5, 50.0f * 2.5));
    if (voltage_source_is_selected) {
        box.setPosition(sf::Vector2f(50.0f * 0.25f, 50.0f * 0.25f));
        window->draw(box);
    }
    if (resistor_is_selected) {
        box.setPosition(sf::Vector2f(50.0f * 3.25f, 50.0f * 0.25f));
        window->draw(box);
    }
    if (node_tool_is_selected) {
        box.setPosition(sf::Vector2f(50.0f * 6.25f, 50.0f * 0.25f));
        window->draw(box);
    }
}

void Illustrator::click_on_component() {
    sf::Vector2f mouse_pos = get_mouse_screen_pos();

    sf::Vector2f voltage_min = sf::Vector2f(50.0f * 0.25f, 50.0f * 0.25f);
    sf::Vector2f voltage_max = voltage_min + sf::Vector2f(50.0f * 2.5f, 50.0f * 2.5f);

    sf::Vector2f resistor_min = sf::Vector2f(50.0f * 3.25f, 50.0f * 0.25f);
    sf::Vector2f resistor_max = resistor_min + sf::Vector2f(50.0f * 2.5f, 50.0f * 2.5f);

    sf::Vector2f node_wire_min = sf::Vector2f(50.0f * 6.25f, 50.0f * 0.25f);
    sf::Vector2f node_wire_max = node_wire_min + sf::Vector2f(50.0f * 2.5f, 50.0f * 2.5f);

    if ((mouse_pos.x > voltage_min.x) &&
        (mouse_pos.y > voltage_min.y) &&
        (mouse_pos.x < voltage_max.x) &&
        (mouse_pos.y < voltage_max.y)) {
        voltage_source_is_selected = true;
        resistor_is_selected = false;
        node_tool_is_selected = false;
    }

    if ((mouse_pos.x > resistor_min.x) &&
        (mouse_pos.y > resistor_min.y) &&
        (mouse_pos.x < resistor_max.x) &&
        (mouse_pos.y < resistor_max.y)) {
        resistor_is_selected = true;
        voltage_source_is_selected = false;
        node_tool_is_selected = false;
    }

    if ((mouse_pos.x > node_wire_min.x) &&
        (mouse_pos.y > node_wire_min.y) &&
        (mouse_pos.x < node_wire_max.x) &&
        (mouse_pos.y < node_wire_max.y)) {
        node_tool_is_selected = true;
        voltage_source_is_selected = false;
        resistor_is_selected = false;
    }
}

void Illustrator::draw_dummy_voltage_source() {
    sf::Vector2f screen_pos({50.0f * 1.5f, 50.0f * 1.5f});
    
    sf::CircleShape body(50.0f);
    body.setFillColor(sf::Color(0, 0, 0));
    body.setOutlineThickness(1.0f);
    body.setOutlineColor(sf::Color(255, 255, 255));
    body.setPosition(sf::Vector2f(screen_pos.x - 50.0f, screen_pos.y - 50.0f));
    window->draw(body);

    std::vector<sf::Vertex> symbols = {
        sf::Vertex{sf::Vector2f(screen_pos.x + 0.0f * 50.0f, screen_pos.y - 0.7f * 50.0f)},
        sf::Vertex{sf::Vector2f(screen_pos.x + 0.0f * 50.0f, screen_pos.y - 0.3f * 50.0f)},
        sf::Vertex{sf::Vector2f(screen_pos.x - 0.2f * 50.0f, screen_pos.y - 0.5f * 50.0f)},
        sf::Vertex{sf::Vector2f(screen_pos.x + 0.2f * 50.0f, screen_pos.y - 0.5f * 50.0f)},
        sf::Vertex{sf::Vector2f(screen_pos.x - 0.2f * 50.0f, screen_pos.y + 0.5f * 50.0f)},
        sf::Vertex{sf::Vector2f(screen_pos.x + 0.2f * 50.0f, screen_pos.y + 0.5f * 50.0f)},
    };
    window->draw(&symbols[0], symbols.size(), sf::PrimitiveType::Lines);
}

void Illustrator::draw_dummy_resistor() {
    sf::Vector2f screen_pos({ 50.0f * 4.5f, 50.0f * 1.5f });

    std::vector<sf::Vertex> symbols = {
        sf::Vertex{sf::Vector2f(screen_pos.x - (1.0f * 50.0f), screen_pos.y + (0.0f * 50.0f))},
        sf::Vertex{sf::Vector2f(screen_pos.x - (0.6f * 50.0f), screen_pos.y + (0.0f * 50.0f))},
        sf::Vertex{sf::Vector2f(screen_pos.x - (0.5f * 50.0f), screen_pos.y + (0.5f * 50.0f))},
        sf::Vertex{sf::Vector2f(screen_pos.x - (0.3f * 50.0f), screen_pos.y - (0.5f * 50.0f))},
        sf::Vertex{sf::Vector2f(screen_pos.x - (0.1f * 50.0f), screen_pos.y + (0.5f * 50.0f))},
        sf::Vertex{sf::Vector2f(screen_pos.x + (0.1f * 50.0f), screen_pos.y - (0.5f * 50.0f))},
        sf::Vertex{sf::Vector2f(screen_pos.x + (0.3f * 50.0f), screen_pos.y + (0.5f * 50.0f))},
        sf::Vertex{sf::Vector2f(screen_pos.x + (0.5f * 50.0f), screen_pos.y - (0.5f * 50.0f))},
        sf::Vertex{sf::Vector2f(screen_pos.x + (0.6f * 50.0f), screen_pos.y + (0.0f * 50.0f))},
        sf::Vertex{sf::Vector2f(screen_pos.x + (1.0f * 50.0f), screen_pos.y + (0.0f * 50.0f))},
    };
    window->draw(&symbols[0], symbols.size(), sf::PrimitiveType::LineStrip);
}

void Illustrator::draw_dummy_wire() {
    sf::Vector2f screen_pos({ 50.0f * 7.5f, 50.0f * 1.5f });

    std::vector<sf::Vertex> symbols = {
        sf::Vertex{sf::Vector2f(screen_pos.x - (1.0f * 50.0f), screen_pos.y + (0.0f * 50.0f))},
        sf::Vertex{sf::Vector2f(screen_pos.x + (1.0f * 50.0f), screen_pos.y + (0.0f * 50.0f))},
        sf::Vertex{sf::Vector2f(screen_pos.x + (0.0f * 50.0f), screen_pos.y - (1.0f * 50.0f))},
        sf::Vertex{sf::Vector2f(screen_pos.x + (0.0f * 50.0f), screen_pos.y + (1.0f * 50.0f))},
    };
    window->draw(&symbols[0], symbols.size(), sf::PrimitiveType::Lines);
    float ball_rad = 6.0f;
    sf::CircleShape ball(ball_rad);
    ball.setPosition(screen_pos - sf::Vector2f(ball_rad, ball_rad));
    window->draw(ball);
}

