
#include "Illustrator.h"

Illustrator::Illustrator(sf::RenderWindow* window, float scale) {
    this->window = window;
    this->scale = scale;
    globalx = scale * 0.5f;
    globaly = scale * 0.5f;
    font = new sf::Font("arial.ttf");
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
    globalx += (globalx - sf::Mouse::getPosition(*window).x) * (zoom * scroll->delta);
    globaly += (globaly - sf::Mouse::getPosition(*window).y) * (zoom * scroll->delta);
}

void Illustrator::pan_screen() {
    static sf::Vector2i prev_mouse_position;
    sf::Vector2i curr_mouse_position = sf::Mouse::getPosition(*window);
    sf::Vector2i relative_mouse_motion = curr_mouse_position - prev_mouse_position;
    prev_mouse_position = curr_mouse_position;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Middle)) {
        globalx += relative_mouse_motion.x;
        globaly += relative_mouse_motion.y;
    }
}

void Illustrator::draw_grid() {
    sf::CircleShape point(1.0f);
    int point_width = ((float)window->getSize().x / scale) + 2;
    int point_height = ((float)window->getSize().y / scale) + 2;
    for (int i = 0; i < point_width; i++) {
        for (int j = 0; j < point_height; j++) {
            float x = globalx + ((i - ((int)globalx / (int)scale)) * scale);
            float y = globaly + ((j - ((int)globaly / (int)scale)) * scale);
            point.setPosition(sf::Vector2f(x, y));
            window->draw(point);
        }
    }
}

