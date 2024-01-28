#include "Resource.hpp"

template<typename ResourceType>
class ShaderResource : Resource<ResourceType> {

    public:
        ShaderResource() = default;
        ShaderResource(const std::string& path) {
            this->Load(path);
        }

        ~ShaderResource() {
            
        }

        ResourceType Load(const std::string& path) {
            std::string shaderCode;
            std::ifstream shaderFile;

            shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

            try {
                shaderFile.open(vertexPath);
                std::stringstream shaderStream;

                shaderStream << shaderFile.rdbuf();

                shaderFile.close();

                vertexCode = shaderStream.str();
            }

            catch (std::ifstream::failure& e) {
                std::cerr << "Error: Failed to read shader files." << std::endl;
            }

            return (this->data = shaderCode);
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