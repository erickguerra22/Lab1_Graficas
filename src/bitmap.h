#pragma once
#include "framebuffer.h"
#include "writeBitMap.h"
#include <iostream>

void render()
{
    setClearColor(Color(27, 27, 27));
    clear();

    // Figura 1
    setCurrentColor(Color(255, 255, 255));
    std::vector<Vertex2> polygon1 = {
        {165, 380},
        {185, 360},
        {180, 330},
        {207, 345},
        {233, 330},
        {230, 360},
        {250, 380},
        {220, 385},
        {205, 410},
        {193, 383}};

    drawPoligon(polygon1, Color(255, 255, 0));

    // Figura 2
    setCurrentColor(Color(255, 255, 255));
    std::vector<Vertex2> polygon2 = {
        {321, 335},
        {288, 286},
        {339, 251},
        {374, 302}};

    drawPoligon(polygon2, Color(0, 0, 255));
    renderBuffer();
}
