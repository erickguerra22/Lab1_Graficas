#pragma once
#include <iostream>
#include <cstdint>

class Color
{
private:
    uint8_t r;
    uint8_t g;
    uint8_t b;

public:
    Color() {}
    Color(uint8_t blue, uint8_t green, uint8_t red)
        : r(red), g(green), b(blue)
    {
    }

    uint8_t getBlue()
    {
        return b;
    }

    uint8_t getRed()
    {
        return r;
    }
    uint8_t getGreen()
    {
        return g;
    }

    friend std::ostream &operator<<(std::ostream &os, const Color &color)
    {
        os << "\033[1;31mR:" << static_cast<int>(color.r) << "\033[0m, ";
        os << "\033[1;32mG:" << static_cast<int>(color.g) << "\033[0m, ";
        os << "\033[1;34mB:" << static_cast<int>(color.b) << "\033[0m";
        return os;
    };

    Color operator+(const Color &color)
    {
        uint8_t red = r + color.r;
        uint8_t green = g + color.g;
        uint8_t blue = b + color.b;
        return Color(red, green, blue);
    };

    Color operator*(const float &fNumber)
    {
        uint8_t red = r * fNumber;
        uint8_t green = g * fNumber;
        uint8_t blue = b * fNumber;
        return Color(red, green, blue);
    }

    bool operator==(const Color &color)
    {
        if (r == color.r && b == color.b && g == color.g)
            return true;
        return false;
    }
};
