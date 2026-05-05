#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H
#include "Process.h"
#include <unordered_map>
#include <vector>

enum class SortCategory {
    CPU,
    MEM,
    PID,
    NAME
};


class ProcessManager {
private:
    std::unordered_map<int, Process> processes;
public:
    void refresh();
    std::unordered_map<int, Process> getProcesses() const;
    std::vector<Process> getProcessesSnapshot(SortCategory sortCat);
};



#endif
