#pragma once

#include "utilities.h"

class Illustrator {
public:
    sf::RenderWindow* window = nullptr;
    sf::Font* font = nullptr;
    sf::Vector2f global_origin;
    float scale = 0.0f;

    // members
    Illustrator(sf::RenderWindow* window, float scale);
    ~Illustrator();
    void zoom_scroll(const sf::Event::MouseWheelScrolled* scroll);
    void pan_screen();
    void draw_grid();

    // coordinates
    sf::Vector2f get_screen_pos_mouse();
    sf::Vector2f world_to_screen(sf::Vector2i world_pos);
    sf::Vector2i screen_to_world(sf::Vector2f screen_pos);
    
    // draw
    void draw_voltage_source(VoltageSource& voltage_source);
    void draw_resistor(Resistor& resistor);
    void draw_ground();
};

