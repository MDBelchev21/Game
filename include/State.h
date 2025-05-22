// include/State.hpp
#pragma once
#include <SFML/Graphics.hpp>

#include "Circle.h"

class State {
public:
    State() : deltaTime(0.0f), totalTime(0.0f) {}

    float deltaTime;
    float totalTime;

    sf::RenderWindow* window{};
    Circle circle{50.0f};

    std::vector<RenderObject*> renderObjects;

    void updateTiming(float dt) {
        deltaTime = dt;
        totalTime += dt;
    }

};
