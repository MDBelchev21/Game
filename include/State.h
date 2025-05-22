// include/State.hpp
#pragma once
#include <SFML/Graphics.hpp>

class State {
public:
    State() : deltaTime(0.0f), totalTime(0.0f) {}

    float deltaTime;
    float totalTime;

    sf::RenderWindow window;

    void updateTiming(float dt) {
        deltaTime = dt;
        totalTime += dt;
    }

};