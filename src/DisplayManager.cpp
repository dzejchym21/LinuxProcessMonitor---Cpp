#include "DisplayManager.h"
#include <curses.h>

DisplayManager::DisplayManager() {
    initscr();
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    keypad(stdscr, true);
    noecho();
    curs_set(0);
    cbreak();
    timeout(100);
}

DisplayManager::~DisplayManager() {
    endwin();
}

void DisplayManager::drawHeader() {
    attron(COLOR_PAIR(1) | A_BOLD);

    for (int x = 0; x < COLS; x++) {
        mvaddch(0, x, ' ');
    }

    mvprintw(0, 0, " %-8s %-8s %-20s %-10s %-12s %-5s",
            "PID", "PPID", "COMMAND", "USER", "RES (kB)", "%CPU");

    attroff(COLOR_PAIR(1) | A_BOLD);
}


void DisplayManager::render(const ProcessManager& pm) {
    erase();
    drawHeader();

    refresh();
}