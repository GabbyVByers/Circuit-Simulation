
#include "illustrator.h"

void Illustrator::draw_currently_selected_component() {
	if (voltage_source_is_selected) {
		VoltageSource voltage_source;
		voltage_source.voltage = 5.0;
		voltage_source.world_position = get_mouse_world_pos();
		voltage_source.dir = curr_voltage_source_direction;
		draw_voltage_source(voltage_source);
	}
	if (resistor_is_selected) {
		Resistor resistor;
		resistor.resistance = 10.0;
		resistor.world_position = get_mouse_world_pos();
		resistor.dir = curr_resistor_direction;
		draw_resistor(resistor);
	}
}

void Illustrator::rotate_currently_selected_component() {
	if (voltage_source_is_selected) {
		curr_voltage_source_direction += 1;
		if (curr_voltage_source_direction > 3) {
			curr_voltage_source_direction = 0;
		}
	}
	if (resistor_is_selected) {
		curr_resistor_direction += 1;
		if (curr_resistor_direction > 1) {
			curr_resistor_direction = 0;
		}
	}
}

void Illustrator::place_currently_selected_component() {
	sf::Vector2f mouse_screen_pos = get_mouse_screen_pos();
	if (mouse_screen_pos.y < 50.0f * 3.0f) {
		return;
	}
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		return;
	}

	if (voltage_source_is_selected) {
		VoltageSource voltage_source;
		voltage_source.voltage = 5.0;
		voltage_source.world_position = get_mouse_world_pos();
		voltage_source.dir = curr_voltage_source_direction;
		bool space_is_free = true;
		for (VoltageSource& other_voltage_source : voltage_sources) {
			if ((voltage_source.world_position.x == other_voltage_source.world_position.x) &&
				(voltage_source.world_position.y == other_voltage_source.world_position.y)) {
				space_is_free = false;
			}
		}
		if (space_is_free) {
			voltage_sources.push_back(voltage_source);
		}
	}
	if (resistor_is_selected) {
		Resistor resistor;
		resistor.resistance = 10.0;
		resistor.world_position = get_mouse_world_pos();
		resistor.dir = curr_resistor_direction;
		resistors.push_back(resistor);
	}
}

void Illustrator::draw_all_placed_components() {
	for (VoltageSource& voltage_source : voltage_sources) {
		draw_voltage_source(voltage_source);
	}
	for (Resistor& resistor : resistors) {
		draw_resistor(resistor);
	}
}

