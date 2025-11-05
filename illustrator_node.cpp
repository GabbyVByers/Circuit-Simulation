
#include "illustrator.h"

void Illustrator::begin_new_node() {
	if (!node_tool_is_selected) {
		return;
	}
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left())) {
		return;
	}
	currently_drawing_new_node = true;
	new_node_start = get_mouse_world_pos();
}

void Illustrator::manage_new_node() {
	if (!currently_drawing_new_node) {
		return;
	}
	new_node_end = get_mouse_world_pos();

	sf::Vector2f screen_start = world_to_screen(new_node_start);
	sf::Vector2f screen_end   = world_to_screen(new_node_end);

	std::vector<sf::Vertex> wire;
	sf::Vertex vert1; vert1.position = sf::Vector2f(screen_start.x, screen_start.y);
	sf::Vertex vert2; vert2.position = sf::Vector2f(screen_end.x,   screen_end.y);
	wire.push_back(vert1);
	wire.push_back(vert2);
	window->draw(&wire[0], wire.size(), sf::PrimitiveType::LineStrip);
}

void Illustrator::confirm_new_node() {
	if (!currently_drawing_new_node) {
		return;
	}
	currently_drawing_new_node = false;
	if ((new_node_start.x == new_node_end.x) && (new_node_start.y == new_node_end.y)) {
		return;
	}
	ScreenWire wire;
	wire.start = new_node_start;
	wire.end = new_node_end;
	wires.push_back(wire);
}

void Illustrator::draw_wires() {
	for (ScreenWire& screen_wire : wires) {
		std::vector<sf::Vertex> wire;
		sf::Vertex vert1; vert1.position = world_to_screen(screen_wire.start);
		sf::Vertex vert2; vert2.position = world_to_screen(screen_wire.end);
		wire.push_back(vert1);
		wire.push_back(vert2);
		window->draw(&wire[0], wire.size(), sf::PrimitiveType::LineStrip);
	}

	for (ScreenWire& curr_wire : wires) {
		for (ScreenWire& other_wire : wires) {
			if (&curr_wire == &other_wire) {
				continue;
			}
			float ball_rad = 6.0f;
			sf::CircleShape ball(ball_rad);
			if ((curr_wire.start.x == other_wire.start.x) && (curr_wire.start.y == other_wire.start.y)) {
				ball.setPosition(world_to_screen(curr_wire.start) - sf::Vector2f(ball_rad, ball_rad));
				window->draw(ball);
			}
			if ((curr_wire.end.x == other_wire.start.x) && (curr_wire.end.y == other_wire.start.y)) {
				ball.setPosition(world_to_screen(curr_wire.end) - sf::Vector2f(ball_rad, ball_rad));
				window->draw(ball);
			}
			if ((curr_wire.start.x == other_wire.end.x) && (curr_wire.start.y == other_wire.end.y)) {
				ball.setPosition(world_to_screen(curr_wire.start) - sf::Vector2f(ball_rad, ball_rad));
				window->draw(ball);
			}
			if ((curr_wire.end.x == other_wire.end.x) && (curr_wire.end.y == other_wire.end.y)) {
				ball.setPosition(world_to_screen(curr_wire.end) - sf::Vector2f(ball_rad, ball_rad));
				window->draw(ball);
			}
		}
	}
}

