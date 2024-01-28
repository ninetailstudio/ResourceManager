#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

template <typename ResourceType>
class Resource {
public:

    virtual ~Resource() = default;

    virtual ResourceType Load(const std::string& path) = 0; //Read
    // virtual void Save(); // Write
    virtual void Unload() = 0;
    virtual ResourceType Reload(const std::string& path) = 0;
    virtual ResourceType getData() = 0;

    // Add other virtual functions as needed
    // Will eventually need a write/save function
};