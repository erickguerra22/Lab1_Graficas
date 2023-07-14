#pragma once
#include "framebuffer.h"
#include "writeBitMap.h"
#include <iostream>

void render()
{
    setClearColor(Color(27, 27, 27));
    clear();

    // Figura 4
    std::vector<Vertex2> polygon4 = {
        {413, 177},
        {448, 159},
        {502, 88},
        {553, 53},
        {535, 36},
        {676, 37},
        {660, 52},
        {750, 145},
        {761, 179},
        {672, 192},
        {659, 214},
        {615, 214},
        {632, 230},
        {580, 230},
        {597, 215},
        {552, 214},
        {517, 144},
        {466, 180}};
    std::vector<Vertex2> polygon5 = {
        {682, 175},
        {708, 120},
        {735, 148},
        {739, 170}};

    drawPoligon(polygon4, Color(0, 255, 0));
    drawPoligon(polygon5, clearColor);
    renderBuffer();
}
