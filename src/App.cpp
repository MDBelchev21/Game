#include "../include/App.hpp"

App::App() {
    this->state.window = sf::RenderWindow(sf::VideoMode({1920, 1080}), "CMake SFML Project", sf::State::Windowed);
    this->state.window.setFramerateLimit(144);

    Run();
}

void App::Run() {
    auto& window = this->state.window;

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
        this->onUpdate.Invoke(this->state);
        this->onDisplay.Invoke(this->state);
    }
}