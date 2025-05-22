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

    std::jthread watcherThread([&fileWatcher, &needsReload](std::stop_token stoken) {
        fileWatcher.watch(stoken, needsReload);
    });

    auto app = new App();

    watcherThread.request_stop();
    watcherThread.join();
}
