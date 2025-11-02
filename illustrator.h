#pragma once

#include "utilities.h"

class Illustrator {
public:
    sf::RenderWindow* window = nullptr;
    sf::Font* font  = nullptr;
    float globalx   = 0.0f;
    float globaly   = 0.0f;
    float scale     = 0.0f;
    float node_size = 0.05f;

    // members
    Illustrator(sf::RenderWindow* window, float scale);
    void zoom_scroll(const sf::Event::MouseWheelScrolled* scroll);
    void pan_screen();
    void draw_grid();

    // draw
    void draw_voltage_source(VoltageSource& voltage_source);
    void draw_resistor(Resistor& resistor);
    void draw_ground();
};

