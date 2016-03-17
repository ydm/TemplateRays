#include "ColorRGB.hpp"
#include <algorithm>
#include <functional>

// TODO
#include <iostream>


namespace
{

template<typename T>
T clampChannel(const T& x, const T& min, const T& max)
{
    return std::min(max, std::max(min, x));
}

} // namespace


namespace tr
{

// Static methods
ColorRGB ColorRGB::clamp(const ColorRGB& x, const ColorRGB& min, const ColorRGB& max)
{
    return ColorRGB(
        clampChannel(x[0], min[0], max[0]),
        clampChannel(x[1], min[1], max[1]),
        clampChannel(x[2], min[2], max[2]),
        clampChannel(x[3], min[3], max[3])
    );
}


// Static methods
ColorRGB ColorRGB::fromFloat(const float red,
                             const float green,
                             const float blue,
                             const float alpha)
{
    if (0 > red   || red > 1.0f ||
        0 > green || green > 1.0f ||
        0 > blue  || blue > 1.0f ||
        0 > alpha || alpha > 1.0f)
    {
        std::cout << "NEDI E PEDALCHE: " << red << ", " << green << ", " << blue << ", " << alpha << "\n";
    }
        
    return ColorRGB(static_cast<unsigned char>(red * 255),
                    static_cast<unsigned char>(green * 255),
                    static_cast<unsigned char>(blue * 255),
                    static_cast<unsigned char>(alpha * 255));
}


// Constructor
ColorRGB::ColorRGB(const unsigned char red,
                   const unsigned char green,
                   const unsigned char blue,
                   const unsigned char alpha)
: channels_{red, green, blue, alpha}
{
}

// Modifier methods
void ColorRGB::clamp(const ColorRGB& min, const ColorRGB& max)
{
    for (unsigned i = 0; i < 4; i++)
    {
        channels_[i] = clampChannel(channels_[i], min[i], max[i]);
    }
}

} // namespace tr


std::ostream& operator<<(std::ostream& out, const tr::ColorRGB& color)
{
    for (unsigned i = 0; i < 4; i++)
    {
        out << color[i];
    }
    return out;
}
