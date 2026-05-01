#include "DisplayManager.h"
#include <ncursesw/ncurses.h>

DisplayManager::DisplayManager() {
    initscr();
    keypad(stdscr, true);
    noecho();
    curs_set(0);
    cbreak();
    timeout(100);
}

DisplayManager::~DisplayManager() {
    endwin();
}

void DisplayManager::render(const ProcessManager& pm) {
    erase();
    printw("There will be processes...");
    refresh();
}