#pragma once
#include <vector>
#include <string>

class Package {
    std::string name, version, path;
    bool resolved;
    std::vector<Package> dependencies;
public:
    Package(std::string path);
    void resolve();
};