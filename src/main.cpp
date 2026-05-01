#include <iostream>
#include <ncursesw/ncurses.h>
#include <chrono>

#include "Process.h"
#include "UserHelper.h"
#include "DisplayManager.h"

void wypiszProces(const Process& proc) {
    std::cout << proc.getPid() << " " << proc.getPpid() << " " << proc.getName() << " " << proc.getUser() << " " << proc.getState() << " " << proc.getMemoryUsage() << " " << proc.getCpuUsage() << std::endl;
}

int main() {
    DisplayManager dm;
    ProcessManager pm;

    while (true) {
        dm.render(pm);
    }
}