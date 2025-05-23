#pragma once
#include "Event.h"
#include "State.h"
#include "../include/precompile.hpp"

class App {
public:
    App();

    void Run();

private:
    sf::RectangleShape background;
    sf::Clock clock;
    State state;

public:
    Utils::Event<void, State&> onUpdate;
    Utils::Event<void, State&> onDisplay;
};
