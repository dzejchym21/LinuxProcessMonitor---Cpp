#include <iostream>
#include <thread>
#include <chrono>

#include "Process.h"
#include "UserHelper.h"
#include "ProcessManager.h"

void wypiszProces(const Process& proc) {
    std::cout << proc.getPid() << " " << proc.getPpid() << " " << proc.getName() << " " << proc.getUser() << " " << proc.getState() << " " << proc.getMemoryUsage() << " " << proc.getCpuUsage() << std::endl;
}

int main() {
    ProcessManager procMan;
    procMan.refresh();
    for (auto& [key, val]: procMan.getProcesses()) {
        wypiszProces(val);
    }
    std::cout << "======================================================================\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    procMan.refresh();
    for (auto& [key, val]: procMan.getProcesses()) {
        wypiszProces(val);
    }
}