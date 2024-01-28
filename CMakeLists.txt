cmake_minimum_required(VERSION 3.10)
project(ResourceManager)

set(CMAKE_CXX_STANDARD 11)

# Define the library
add_library(ResourceManager SHARED
    Source/Resource.cpp
    Include/ImageResource.hpp
    Include/ShaderResource.hpp
    Include/MeshResource.hpp
    Include/Resource.hpp
    Include/Types/PNG.h
    Include/Types/STBImage.h
)

# Include the dependencies folder for stb_image
target_include_directories(ResourceManager PRIVATE ${CMAKE_SOURCE_DIR}/Include)
target_include_directories(ResourceManager PRIVATE ${CMAKE_SOURCE_DIR}/Dependencies)

# Set the library output directory (where the .so or .dll file will be placed)
set_target_properties(ResourceManager PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
