#ifndef FILEWATCHER_H
#define FILEWATCHER_H
#include <atomic>
#include <stop_token>
#include <string>
#include <filesystem>

#include "Event.h"

namespace Utils {

class FileWatcher {
public:
    explicit FileWatcher(std::string  dir);
    ~FileWatcher() = default;

    void watch(const std::stop_token &stoken, std::atomic<bool>& needsReload);

private:
    std::string m_dir;
    std::filesystem::file_time_type m_lastWriteTime;

public:
    Event<void> onFileChanged;
};

} // Utils

#endif //FILEWATCHER_H
