#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H
#include "Process.h"
#include <unordered_map>
#include <vector>


class ProcessManager {
private:
    std::unordered_map<int, Process> processes;
public:
    void refresh();
    std::unordered_map<int, Process> getProcesses() const;
    std::vector<Process> getProcessesSnapshot();
};



#endif
