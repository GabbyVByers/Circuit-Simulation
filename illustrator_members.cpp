
#include "Illustrator.h"

Illustrator::Illustrator(sf::RenderWindow* window, float scale) {
    this->window = window;
    this->scale = scale;
    global_origin = sf::Vector2f(scale * 0.5f, scale * 0.5f);
    font = new sf::Font("arial.ttf");
}

Illustrator::~Illustrator() {
    delete font;
}

void Illustrator::zoom_scroll(const sf::Event::MouseWheelScrolled* scroll) {
    float zoom = 0.1f;

    if ((scale > 500.0f) && (scroll->delta > 0)) {
        return;
    }
    if ((scale < 35.0f) && (scroll->delta < 0)) {
        return;
    }
    scale *= 1.0f + (zoom * scroll->delta);
    global_origin.x += (global_origin.x - sf::Mouse::getPosition(*window).x) * (zoom * scroll->delta);
    global_origin.y += (global_origin.y - sf::Mouse::getPosition(*window).y) * (zoom * scroll->delta);
}

void Illustrator::pan_screen() {
    static sf::Vector2i prev_mouse_position;
    sf::Vector2i curr_mouse_position = sf::Mouse::getPosition(*window);
    sf::Vector2i relative_mouse_motion = curr_mouse_position - prev_mouse_position;
    prev_mouse_position = curr_mouse_position;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Middle)) {
        global_origin.x += relative_mouse_motion.x;
        global_origin.y += relative_mouse_motion.y;
    }
}

void Illustrator::draw_grid() {
    std::vector<sf::Vertex> vertices;
    int point_width = ((float)window->getSize().x / scale) + 2;
    int point_height = ((float)window->getSize().y / scale) + 2;
    for (int i = 0; i < point_width; i++) {
        for (int j = 0; j < point_height; j++) {
            float x = global_origin.x + ((i - ((int)global_origin.x / (int)scale)) * scale);
            float y = global_origin.y + ((j - ((int)global_origin.y / (int)scale)) * scale);
            sf::Vertex vertex;
            vertex.position = sf::Vector2f(x, y);
            vertices.push_back(vertex);
        }
    }
    window->draw(&vertices[0], vertices.size(), sf::PrimitiveType::Points);
}

