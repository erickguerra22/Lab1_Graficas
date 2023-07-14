#pragma once
#include "framebuffer.h"
#include "writeBitMap.h"
#include <iostream>

void render()
{
    setClearColor(Color(27, 27, 27));
    clear();

    // Figura 3
    setCurrentColor(Color(255, 255, 255));
    std::vector<Vertex2> polygon3 = {
        {377, 249},
        {411, 197},
        {436, 249}};
    drawPoligon(polygon3, Color(255, 0, 0));
    renderBuffer();
}
