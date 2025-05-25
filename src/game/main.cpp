//
// Created by Ivaylo on 23.5.2025 г..
//

#define EXPORT extern "C" __declspec(dllexport)
#include <iostream>

#include "../../include/State.h"

EXPORT void onUpdate(State* state) {
    if (!state->renderObjects.empty() && state->renderObjects[0] != nullptr) {
        state->renderObjects[0]->move(state->deltaTime * 100.f * sf::Vector2f(1,1));
    }
}