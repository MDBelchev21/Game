#include "../include/App.hpp"

#include "../include/Circle.h"

App::App() {
    this->state = new State();
    this->state->window = new sf::RenderWindow;
    this->state->window->create(
        sf::VideoMode::getDesktopMode(),
        "SFML Game",
        sf::State::Fullscreen
    );

    this->state->renderObjects.push_back(new Circle(50.f));
}

void App::Run() {
    auto& window = this->state->window;

    while (window->isOpen())
    {
        while (const std::optional event = window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window->close();
            }
        }

        this->state->updateTiming(clock.restart().asSeconds());
        this->onUpdate.Invoke(this->state);
        this->onDisplay.Invoke(this->state);
    }
}