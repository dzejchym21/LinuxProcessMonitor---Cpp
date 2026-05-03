#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H
#include <ncurses.h>
#include "ProcessManager.h"

class DisplayManager {
public:
    DisplayManager();
    ~DisplayManager();
    void drawHeader();
    void render(const ProcessManager& manager);
};



#endif //DISPLAYMANAGER_H
