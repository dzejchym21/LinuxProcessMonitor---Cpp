#include "DisplayManager.h"
#include <curses.h>
#include <vector>

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

    mvprintw(0, 0, " %8s %8s %-20s %-16s %8s %-12s %-5s",
            "PID", "PPID", "COMMAND", "USER", "NICE", "RES (kB)", "%CPU");

    attroff(COLOR_PAIR(1) | A_BOLD);
}


void DisplayManager::render(const std::vector<Process>& processes) {
    erase();
    drawHeader();

    int row = 1;
    for (const auto& proc : processes) {
        mvprintw(row, 0, " %8d %8d %-20s %-16s %8d %-12ld %-5.2f",
            proc.getPid(),
            proc.getPpid(),
            proc.getName().c_str(),
            proc.getUser().c_str(),
            proc.getNice(),
            proc.getMemoryUsage(),
            proc.getCpuUsage());

        row++;
    }
    refresh();
}