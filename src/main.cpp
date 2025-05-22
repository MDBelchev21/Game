#include <thread>

#include "../include/App.hpp"
#include "../include/FileWatcher.h"

int main()
{
    Utils::FileWatcher fileWatcher("../../src/game");
    std::atomic<bool> needsReload(false);

    fileWatcher.onFileChanged.Attach([]() {
        std::cout << "File changed, reloading..." << std::endl;
    });

    std::jthread watcherThread([&fileWatcher, &needsReload](const std::stop_token& stoken) {
        fileWatcher.watch(stoken, needsReload);
    });

    auto app = new App();

    app->onUpdate.Attach([](State*& state) {
        std::cout << "Updating..." << std::endl;
        state->renderObjects[0]->move(state->deltaTime * 100.f * sf::Vector2f(1,0));
    });

    app->onDisplay.Attach([](State*& state) {
        std::cout << "Drawing..." << std::endl;
        state->window->clear(sf::Color::Blue);
        for (auto& obj : state->renderObjects) {
            obj->draw(*state->window);
        }
        state->window->display();
    });
    app->Run();

    watcherThread.request_stop();
    watcherThread.join();
}
