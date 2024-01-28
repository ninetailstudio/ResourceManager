struct PNG {
    unsigned char* data;            // Pointer to the raw pixel data
    int width;                      // Width of the image
    int height;                     // Height of the image
    int colorDepth;                 // Color depth (e.g., 32 bits for RGBA)
    int bitDepth;                   // Bit depth (e.g., 8, 16 per channel)
    unsigned char colorType;        // Color type (e.g., RGB, RGBA, Grayscale)
    unsigned char* palette;         // Palette for indexed color images
    unsigned int paletteSize;       // Size of the palette
    unsigned char* transparency;    // Transparency 
};