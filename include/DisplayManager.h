#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H
#include <ncurses.h>
#include <vector>

#include "ProcessManager.h"

class DisplayManager {
public:
    DisplayManager();
    ~DisplayManager();
    void drawHeader(SortCategory currentSort);
    void render(const std::vector<Process>& processes, SortCategory currentSort);
};



#endif //DISPLAYMANAGER_H
