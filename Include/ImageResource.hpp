#include "Resource.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

template <typename ResourceType>
class ImageResource : public Resource<ResourceType> {
    public:

        ImageResource() = default;
        ImageResource(const std::string& path) {
            this->data = Load(path);
        }

        ~ImageResource() {
            Unload();
        }

        ResourceType Reload(const std::string& path) override {
            return Load(path);    
        }

        ResourceType getData() override {
            if (!data)
                return nullptr;
            else
                return this->data;
            
        }

        ResourceType Load(std::string& path) {
            int width, height, nrChannels;
            stbi_set_flip_vertically_on_load(true);
            unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, -1);
            if (!data)
                return nullptr;
            else
                return { data, width, height, nrChannels };
        }

        void Unload() override {
            stbi_image_free(this->data.data);
        }

    private:
        ResourceType data;


};
