#pragma once

#include "utilities.h"

class Illustrator {
public:
    sf::RenderWindow* window = nullptr;
    sf::Font* font = nullptr;
    sf::Vector2f global_origin;
    float scale = 0.0f;

    // componenets
    std::vector<ScreenWire> wires;
    std::vector<VoltageSource> voltage_sources;
    std::vector<Resistor> resistors;

    void run() {
        pan_screen();
        draw_grid();
        manage_new_node();
        draw_wires();
        draw_currently_selected_component();
        draw_all_placed_components();
        draw_selection_bar();
    }

    // members
    Illustrator(sf::RenderWindow* window, float scale);
    ~Illustrator();
    void zoom_scroll(const sf::Event::MouseWheelScrolled* scroll);
    void pan_screen();
    void draw_grid();

    // coordinates
    sf::Vector2f get_mouse_screen_pos();
    sf::Vector2i get_mouse_world_pos();
    sf::Vector2f world_to_screen(sf::Vector2i world_pos);

    // draw
    void draw_voltage_source(VoltageSource& voltage_source);
    void draw_resistor(Resistor& resistor);
    void draw_ground();

    // node
    bool currently_drawing_new_node = false;
    int curr_new_node_direction = 0;
    sf::Vector2i new_node_start;
    sf::Vector2i new_node_end;
    void begin_new_node();
    void manage_new_node();
    void confirm_new_node();
    void draw_wires();

    // selection
    bool voltage_source_is_selected = false;
    bool resistor_is_selected = false;
    bool node_tool_is_selected = false;
    void draw_selection_bar();
    void click_on_component();
    void draw_dummy_voltage_source();
    void draw_dummy_resistor();
    void draw_dummy_wire();

    // placer
    int curr_voltage_source_direction = 0;
    int curr_resistor_direction = 0;
    void draw_currently_selected_component();
    void rotate_currently_selected_component();
    void place_currently_selected_component();
    void draw_all_placed_components();
};

