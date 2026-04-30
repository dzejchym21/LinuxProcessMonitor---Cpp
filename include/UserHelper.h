#ifndef USERHELPER_H
#define USERHELPER_H

#include <string>
#include <fstream>
#include <unordered_map>
#include <sstream>

class UserHelper {
public:
    static std::string getUserName(const int uid) {
        if (userCache.contains(uid)) {
            return userCache[uid];
        }

        refreshCache();
        if (userCache.contains(uid)) {
            return userCache[uid];
        }
        return std::to_string(uid);
    }
private:
    static inline std::unordered_map<int, std::string> userCache;

    static void refreshCache() {
        userCache.clear();
        std::ifstream file("/etc/passwd");
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string name, x, uidStr;
            std::getline(ss, name, ':');
            std::getline(ss, x, ':');
            std::getline(ss, uidStr, ':');
            if (!name.empty() && !uidStr.empty()) {
                userCache[std::stoi(uidStr)] = name;
            }
        }
    }
};

#endif
