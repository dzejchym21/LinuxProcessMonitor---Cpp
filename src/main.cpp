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

    pm.refresh();

    while (running) {
        auto currentTime = std::chrono::steady_clock::now();

        if (currentTime - lastRefreshTime >= refreshInterval) {
            pm.refresh();
            lastRefreshTime = currentTime;
            needsRedraw = true;
        }

        int ch = getch();
        if (ch == 'q') {
            running = false;
        }

        if (needsRedraw && running) {
            dm.render(pm.getProcessesSnapshot());
            needsRedraw = false;
        }
    }
}