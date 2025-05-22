#ifndef SHAREDLIBRARY_H
#define SHAREDLIBRARY_H
#include <string>
#include <Windows.h>
#include <sstream>
#include <iostream>

namespace Utils {

class SharedLibrary {
public:
    explicit SharedLibrary(const std::string& path) {
        handle = LoadLibraryA(path.c_str());
        if (!handle) {
            std::stringstream ss;
            ss << "Failed to load library: " << path << ", Error: " << GetLastError();
            throw std::runtime_error(ss.str());
        }
        std::cout << "Loaded library: " << path << std::endl;
    }

    ~SharedLibrary() {
        if (handle) {
            FreeLibrary(static_cast<HMODULE>(handle));
            std::cout << "Unloaded library" << std::endl;
        }
    }

    template<typename T>
    T loadSymbol(const std::string& name) {
        FARPROC symbol = GetProcAddress(static_cast<HMODULE>(handle), name.c_str());
        if (!symbol) {
            std::stringstream ss;
            ss << "Failed to load symbol: " << name << ", Error: " << GetLastError();
            throw std::runtime_error(ss.str());
        }
        return reinterpret_cast<T>(symbol);
    }

private:
    void* handle;
};

} // Utils

#endif //SHAREDLIBRARY_H
