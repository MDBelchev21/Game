#include <thread>

#include "../include/App.hpp"
#include "../include/FileWatcher.h"
#include "../include/SharedLibrary.h"

#define DLLPATH "../../src/game/build/bin/Debug/game.dll"

int main()
{
    using OnUpdateType = std::function<void(State*)>;

    Utils::FileWatcher fileWatcher("../../src/game");
    OnUpdateType onUpdate;

    Utils::SharedLibrary sharedLibrary(DLLPATH);

    auto app = new App();

    fileWatcher.onFileChanged.Attach([&sharedLibrary, &onUpdate, &app]() {
        // Unload the current shared library and clear the function pointer
        std::lock_guard<std::mutex> lock(app->reloadMutex);

        onUpdate = nullptr;
        app->onUpdate.DetachAll();
        sharedLibrary.unload();

        // Rebuild and reload the shared library
        system("cmake --build ../../src/game/build");
        sharedLibrary.load(DLLPATH);
        onUpdate = OnUpdateType(sharedLibrary.loadSymbol<void(*)(State*)>("onUpdate"));
        app->onUpdate.Attach(onUpdate);
    });

    std::jthread watcherThread([&fileWatcher](const std::stop_token& stoken) {
        fileWatcher.watch(stoken);
    });

    app->onDisplay.Attach([](State& state, sf::RenderWindow& window) {
        window.clear(sf::Color::Blue);
        for (auto* obj : state.renderObjects) {
            obj->draw(window);
        }
        window.display();
    });
    app->Run();

    watcherThread.request_stop();
    watcherThread.join();
}