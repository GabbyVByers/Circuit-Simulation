#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <vector>

class Node {
public:
    double voltage;
};

class VoltageSource {
public:
    int dir;
    sf::Vector2i world_position;
    double voltage;
    double current;
    Node* positive_node = nullptr;
    Node* negative_node = nullptr;

    void tick() {
        if (positive_node == nullptr)
            return;
        if (negative_node == nullptr)
            return;
    }
};

class Resistor {
public:
    int dir;
    sf::Vector2i world_position;
    double resistance;
    double current;
    Node* top_node  = nullptr;
    Node* bttm_node = nullptr;

    void tick() {
        if (top_node  == nullptr)
            return;
        if (bttm_node == nullptr)
            return;
    }
};

struct ScreenWire {
    sf::Vector2i start;
    sf::Vector2i end;
};