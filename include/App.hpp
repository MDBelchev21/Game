#pragma once
#include "Event.h"
#include "State.h"
#include "../include/precompile.hpp"

class App {
public:
    App();
private:
    void Run();

    sf::RectangleShape background;
    sf::Clock clock;
    State state;

public:
    Utils::Event<void, State&> onUpdate;
    Utils::Event<void, State&> onDisplay;
};
