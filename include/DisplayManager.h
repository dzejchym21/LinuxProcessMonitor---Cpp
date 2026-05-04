#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H
#include <ncurses.h>
#include <vector>

#include "ProcessManager.h"

class DisplayManager {
public:
    DisplayManager();
    ~DisplayManager();
    void drawHeader();
    void render(const std::vector<Process>& processes);
};



#endif //DISPLAYMANAGER_H
