// include/State.hpp
#pragma once
#include <iostream>
#include <mutex>
#include <SFML/Graphics.hpp>

#include "Circle.h"

class State {
public:
    // CTOR
    State() {
        totalTime = 0.f, deltaTime = 0.f;
    }

    State(const State& state) {
        deltaTime = state.deltaTime;
        totalTime = state.totalTime;

        // Deep copy
        renderObjects.clear();
        for (auto* obj : state.renderObjects) {
            renderObjects.push_back(obj);
        }


        outstream = state.outstream;
    }

    float deltaTime;
    float totalTime;

    std::vector<RenderObject*> renderObjects;

    std::streambuf* outstream = nullptr;

    void updateTiming(float dt) {
        deltaTime = dt;
        totalTime += dt;
    }
};
