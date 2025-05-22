#ifndef FILEWATCHER_H
#define FILEWATCHER_H
#include "Event.h"

namespace Utils {

class FileWatcher {
public:
    Event<void> onFileChanged;
};

} // Utils

#endif //FILEWATCHER_H
