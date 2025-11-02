#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <vector>

class Pos2i {
public:
	int x = 0;
	int y = 0;

	Pos2i() {
		x = 0;
		y = 0;
	}

	Pos2i(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

class Node {
public:
    double voltage;
};

class VoltageSource {
public:
    int dir;
    Pos2i position;
    double voltage;
    Node* positive_node = nullptr;
    Node* negative_node = nullptr;

    void tick() {
        if (positive_node == nullptr)
            return;
        if (negative_node == nullptr)
            return;
        positive_node->voltage = negative_node->voltage + voltage;
    }
};

class Resistor {
public:
    int dir;
    Pos2i position;
    double resistance;
    Node* top_node  = nullptr;
    Node* bttm_node = nullptr;

    void tick() {
        if (top_node  == nullptr)
            return;
        if (bttm_node == nullptr)
            return;
    }
};

