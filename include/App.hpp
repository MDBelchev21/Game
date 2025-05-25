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
    sf::RenderWindow window;

public:
    Utils::Event<void, State*> onUpdate;
    Utils::Event<void, State&, sf::RenderWindow&> onDisplay;

    std::mutex reloadMutex;
};
