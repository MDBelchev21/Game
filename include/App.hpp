#pragma once
#include "../include/precompile.hpp"

class App {
public:
    App();
private:
    void display(sf::RenderWindow& window);
    void update(sf::RenderWindow& window);

    sf::RectangleShape background;
};
