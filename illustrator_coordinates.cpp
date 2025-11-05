
#include "illustrator.h"

sf::Vector2f Illustrator::get_screen_pos_mouse() {
	sf::Vector2i mouse_pos = sf::Mouse::getPosition(*window);
	return sf::Vector2f((float)mouse_pos.x, (float)mouse_pos.y);
}

sf::Vector2f Illustrator::world_to_screen(sf::Vector2i world_pos) {
    sf::Vector2f screen_pos;
    screen_pos.x = global_origin.x + (scale * world_pos.x);
    screen_pos.y = global_origin.y + (scale * world_pos.y);
    return screen_pos;
}

sf::Vector2i Illustrator::screen_to_world(sf::Vector2f screen_pos) {
    return sf::Vector2i();
}

