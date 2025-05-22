#pragma once
#include "../include/precompile.hpp"

class App {
public:
    App();
private:
    void update(sf::RenderWindow& window);
    void display(sf::RenderWindow& window);

    sf::RectangleShape background;
};
