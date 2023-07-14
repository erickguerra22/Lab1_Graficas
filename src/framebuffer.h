#pragma once
#include "color.h"
#include "vertex2.h"
#include <iostream>
#include <vector>
#include <Windows.h>
#include <stack>

const int width = GetSystemMetrics(SM_CXSCREEN);
const int height = GetSystemMetrics(SM_CYSCREEN);
std::vector<Color> framebuffer;
Color clearColor = Color(0, 0, 0);
Color currentColor = Color(255, 255, 255);

void clear()
{
    framebuffer.resize(width * height);
    fill(framebuffer.begin(), framebuffer.end(), clearColor);
}

void setClearColor(Color newColor)
{
    clearColor = newColor;
}

void setCurrentColor(Color newColor)
{
    currentColor = newColor;
}

/*void setSize(int newW, int newH)
{
    width = newW;
    height = newH;
    framebuffer.resize(width * height);
}*/

// Función punto
void point(Vertex2 vertex)
{
    int index = static_cast<int>(vertex.y) * width + static_cast<int>(vertex.x);
    if (index >= 0 && index <= framebuffer.size())
        framebuffer[index] = currentColor;
}

// Función línea
void line(float x0, float y0, float x1, float y1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);

    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;

    int err = dx - dy;

    while (true)
    {
        point(Vertex2{x0, y0});

        if (x0 == x1 && y0 == y1)
            break;

        int e2 = 2 * err;

        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }

        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

Vertex2 center(std::vector<Vertex2> points)
{
    float minX = points[0].x;
    float maxX = points[0].x;
    float minY = points[0].y;
    float maxY = points[0].y;
    for (int i = 0; i < points.size(); i++)
    {
        minX = points[i].x < minX ? points[i].x : minX;
        maxX = points[i].x > maxX ? points[i].x : maxX;
        minY = points[i].y < minY ? points[i].y : minY;
        maxY = points[i].y > maxY ? points[i].y : maxY;
    }
    return Vertex2{(minX + maxX) / 2, (minY + maxY) / 2};
}

void bucketFill(Vertex2 start, Color fillColor)
{
    // Crear una pila para almacenar las coordenadas de los píxeles a procesar
    std::stack<std::pair<int, int>> pixelStack;

    // Agregar las coordenadas iniciales a la pila
    pixelStack.push(std::make_pair(start.x, start.y));

    // Realizar el relleno de cubeta
    while (!pixelStack.empty())
    {
        // Obtener las coordenadas del píxel actual
        int x = pixelStack.top().first;
        int y = pixelStack.top().second;
        pixelStack.pop();

        // Verificar si el píxel actual necesita ser pintado
        if (!(framebuffer[y * width + x] == fillColor) && !(framebuffer[y * width + x] == currentColor))
        {
            // Pintar el píxel actual con el color de relleno
            framebuffer[y * width + x] = fillColor;

            // Agregar los píxeles adyacentes a la pila si cumplen con las condiciones
            if (x > 0)
                pixelStack.push(std::make_pair(x - 1, y)); // Píxel izquierdo
            if (x < width - 1)
                pixelStack.push(std::make_pair(x + 1, y)); // Píxel derecho
            if (y > 0)
                pixelStack.push(std::make_pair(x, y - 1)); // Píxel superior
            if (y < height - 1)
                pixelStack.push(std::make_pair(x, y + 1)); // Píxel inferior
        }
    }
}

void drawPoligon(std::vector<Vertex2> points, Color fillColor = currentColor)
{
    for (int i = 0; i < points.size(); i++)
    {
        if (i == points.size() - 1)
        {
            line(points[i].x, points[i].y, points[0].x, points[0].y);
            continue;
        }
        line(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
    }
    bucketFill(center(points), fillColor);
}
