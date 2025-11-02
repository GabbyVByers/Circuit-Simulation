#pragma once

#include "utilities.h"

class Illustrator {
public:
    sf::RenderWindow* window = nullptr;
    float globalx = 0.0f;
    float globaly = 0.0f;
    float scale = 0.0f;

    // members
    Illustrator(sf::RenderWindow* window, float scale);
    void zoom_scroll(const sf::Event::MouseWheelScrolled* scroll);
    void pan_screen();
    void draw_grid();

    // voltage
    void draw_voltage_source(VoltageSource& vs);
};

