//
// Created by Ivaylo on 22.5.2025 г..
//

#include "../include/FileWatcher.h"

namespace Utils {

FileWatcher::FileWatcher(std::string  dir) : m_dir(std::move(dir)) {}

void FileWatcher::watch(const std::stop_token &stoken, std::atomic<bool> &needsReload) {
    while (!stoken.stop_requested()) {
        for (const auto &entry : std::filesystem::directory_iterator(m_dir)) {
            if (entry.is_regular_file()) {
                auto lastWriteTime = std::filesystem::last_write_time(entry.path());
                if (lastWriteTime > m_lastWriteTime) {
                    m_lastWriteTime = lastWriteTime;
                    onFileChanged.Invoke();
                    needsReload.store(true);
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

} // Utils