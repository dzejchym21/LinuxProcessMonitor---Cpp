#include "../include/ProcessManager.h"

#include <algorithm>
#include <unordered_set>
#include <vector>
#include <ranges>
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

std::vector<Process> ProcessManager::getProcessesSnapshot(SortCategory sortCat) {
    std::vector<Process> vec;
    vec.reserve(processes.size());

    for (auto const& [pid, proc] : processes) {
        vec.push_back(proc);
    }

    switch (sortCat) {
        case SortCategory::CPU:
            std::ranges::sort(vec, std::ranges::greater{}, &Process::getCpuUsage);
            break;
        case SortCategory::MEM:
            std::ranges::sort(vec, std::ranges::greater{}, &Process::getMemoryUsage);
            break;
        case SortCategory::PID:
            std::ranges::sort(vec, std::ranges::less{}, &Process::getPid);
            break;
        case SortCategory::NAME:
            std::ranges::sort(vec, [](const Process&a, const Process&b) {
                std::string_view s1 = a.getName();
                std::string_view s2 = b.getName();

                return std::ranges::lexicographical_compare(s1, s2, [](unsigned char c1, unsigned char c2) {
                    return std::tolower(c1) < std::tolower(c2);
                });
            });
            break;
        default:
            break;
    }

    return vec;
}
