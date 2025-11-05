
#include "illustrator.h"

sf::Vector2f Illustrator::get_mouse_screen_pos() {
	sf::Vector2i mouse_pos = sf::Mouse::getPosition(*window);
	return sf::Vector2f((float)mouse_pos.x, (float)mouse_pos.y);
}

sf::Vector2i Illustrator::get_mouse_world_pos() {
    sf::Vector2f screen_pos = get_mouse_screen_pos();
    int x = (int)((screen_pos.x - global_origin.x + (scale * 0.5f)) / scale);
    int y = (int)((screen_pos.y - global_origin.y + (scale * 0.5f)) / scale);
    return sf::Vector2i(x, y);
}

sf::Vector2f Illustrator::world_to_screen(sf::Vector2i world_pos) {
    sf::Vector2f screen_pos;
    screen_pos.x = global_origin.x + (scale * world_pos.x);
    screen_pos.y = global_origin.y + (scale * world_pos.y);
    return screen_pos;
}

