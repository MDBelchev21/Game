#include "../include/App.hpp"

#include "../include/Circle.h"

App::App() {
    this->state = State();
    this->window = sf::RenderWindow(
        sf::VideoMode({1280, 720}),
        "SFML Game",
        sf::Style::Titlebar | sf::Style::Close
        );

    this->state.renderObjects.push_back(new Circle(50.f));
    this->state.outstream = std::cout.rdbuf();
}

void App::Run() {
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }


        this->state.updateTiming(clock.restart().asSeconds());

        {
            std::lock_guard<std::mutex> lock(this->reloadMutex);
            this->onUpdate.Invoke(&this->state);
        }

        this->onDisplay.Invoke(this->state, window);
    }
}