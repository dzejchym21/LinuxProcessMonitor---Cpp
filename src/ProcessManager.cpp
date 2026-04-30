#include "../include/ProcessManager.h"
#include <unordered_set>
#include <vector>
#include "ProcParser.h"

void ProcessManager::refresh() {
    std::vector<int> currentPids = ProcParser::getAllPids();

    std::unordered_set<int> alivePids(currentPids.begin(), currentPids.end());
    for (int pid: currentPids) {
        if (processes.contains(pid)) {
            ProcessData dynamicData;
            ProcParser::fillDynamicData(pid, dynamicData);
            processes.at(pid).update(dynamicData);
        } else {
            processes.emplace(pid, ProcParser::buildProcess(pid));
        }
    }

    for (auto it = processes.begin(); it != processes.end(); ) {
        if (alivePids.find(it->first) == alivePids.end()) {
            it = processes.erase(it);
        } else {
            ++it;
        }
    }
}

std::unordered_map<int, Process> ProcessManager::getProcesses() const {
    return processes;
}
