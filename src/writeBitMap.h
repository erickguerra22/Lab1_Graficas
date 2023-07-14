#pragma once
#include <vector>
#include "framebuffer.h" // Incluir el archivo de encabezado del framebuffer

#include <fstream>

void renderBuffer()
{
    std::ofstream file("out.bmp", std::ios::binary);

    // Encabezado del archivo BMP
    uint32_t fileSize = 54 + (width * height * 3);
    uint32_t reserved = 0;
    uint32_t dataOffset = 54;
    uint32_t headerSize = 40;
    uint32_t imageWidth = width;
    uint32_t imageHeight = height;
    uint16_t colorPlanes = 1;
    uint16_t bitsPerPixel = 24;
    uint32_t compression = 0;
    uint32_t dataSize = (width * height * 3);
    uint32_t horizontalResolution = 2835; // 72 dpi
    uint32_t verticalResolution = 2835;   // 72 dpi
    uint32_t colorsInPalette = 0;
    uint32_t importantColors = 0;

    file.write("BM", 2); // Identificador del archivo BMP
    file.write(reinterpret_cast<char *>(&fileSize), sizeof(fileSize));
    file.write(reinterpret_cast<char *>(&reserved), sizeof(reserved));
    file.write(reinterpret_cast<char *>(&dataOffset), sizeof(dataOffset));
    file.write(reinterpret_cast<char *>(&headerSize), sizeof(headerSize));
    file.write(reinterpret_cast<char *>(&imageWidth), sizeof(imageWidth));
    file.write(reinterpret_cast<char *>(&imageHeight), sizeof(imageHeight));
    file.write(reinterpret_cast<char *>(&colorPlanes), sizeof(colorPlanes));
    file.write(reinterpret_cast<char *>(&bitsPerPixel), sizeof(bitsPerPixel));
    file.write(reinterpret_cast<char *>(&compression), sizeof(compression));
    file.write(reinterpret_cast<char *>(&dataSize), sizeof(dataSize));
    file.write(reinterpret_cast<char *>(&horizontalResolution), sizeof(horizontalResolution));
    file.write(reinterpret_cast<char *>(&verticalResolution), sizeof(verticalResolution));
    file.write(reinterpret_cast<char *>(&colorsInPalette), sizeof(colorsInPalette));
    file.write(reinterpret_cast<char *>(&importantColors), sizeof(importantColors));

    // Rellenar fila con píxeles
    int paddingSize = (4 - (width * 3) % 4) % 4; // Relleno para asegurar que cada fila sea múltiplo de 4 bytes
    char paddingBytes[3] = {0, 0, 0};            // Bytes de relleno
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            int index = y * width + x;
            Color color = framebuffer[index];
            file.write(reinterpret_cast<char *>(&color), sizeof(color));
        }
        file.write(paddingBytes, paddingSize); // Escribir bytes de relleno al final de cada fila
    }

    file.close();
}
