#pragma once
#include "framebuffer.h"
#include "writeBitMap.h"
#include <iostream>

void render()
{
    setClearColor(Color(27, 27, 27));
    clear();
    renderBuffer();
}
