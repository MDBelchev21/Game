#include "../include/App.hpp"

App::App() {
    auto window = sf::RenderWindow(sf::VideoMode({1920, 1080}), "CMake SFML Project", sf::State::Windowed);
    window.setFramerateLimit(144);

    background = sf::RectangleShape({1920.f,1080.f});
    background.setFillColor(sf::Color::Black);

    update(window);
}

void App::update(sf::RenderWindow& window) {
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        display(window);
    }
}

void App::display(sf::RenderWindow& window) {
    window.clear();
    window.draw(background);
    window.display();
}

