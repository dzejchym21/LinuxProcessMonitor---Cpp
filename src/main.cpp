#include <iostream>
#include <curses.h>
#include <chrono>
#include <thread>
#include "DisplayManager.h"

int main() {
    DisplayManager dm;
    ProcessManager pm;

    bool running = true;
    bool needsRedraw = true;

    auto lastRefreshTime = std::chrono::steady_clock::now();
    const auto refreshInterval = std::chrono::seconds(1);
    SortCategory currentSort = SortCategory::CPU;

    pm.refresh();

    while (running) {
        auto currentTime = std::chrono::steady_clock::now();

        if (currentTime - lastRefreshTime >= refreshInterval) {
            pm.refresh();
            lastRefreshTime = currentTime;
            needsRedraw = true;
        }

        int ch = getch();
        switch (ch) {
            case 'q':
                running = false;
                break;
            case 'm':
                currentSort = SortCategory::MEM;
                break;
            case 'c':
                currentSort = SortCategory::CPU;
                break;
        }

        if (needsRedraw && running) {
            dm.render(pm.getProcessesSnapshot(currentSort));
            needsRedraw = false;
        }
    }
}