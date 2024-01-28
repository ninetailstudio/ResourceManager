#include "Resource.hpp"

template<typename ResourceType>
class MeshResource : Resource<ResourceType> {

    public:
        MeshResource() = default;
        MeshResource(const std::string& path) {
            this->Load(path);
        }
        
        ~MeshResource();

        ResourceType Load(const std::string& path) {
           
        }

        void Unload() {
        
        }

        ResourceType Reload(const std::string& path) {
            return this->Load(path);
        }

        ResourceType getData() {
            return this->data;
        }

    private:
        ResourceType data;

};