#include "Color.hpp"
#include <algorithm>
#include <functional>


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
Color Color::clamp(const Color& x, const Color& min, const Color& max)
{
    return Color(
        clampChannel(x[0], min[0], max[0]),
        clampChannel(x[1], min[1], max[1]),
        clampChannel(x[2], min[2], max[2]),
        clampChannel(x[3], min[3], max[3])
    );
}


// Constructor
Color::Color(const unsigned char red,
             const unsigned char green,
             const unsigned char blue,
             const unsigned char alpha)
: channels_{red, green, blue, alpha}
{
}


// Modifier methods
void Color::clamp(const Color& min, const Color& max)
{
    for (unsigned i = 0; i < 4; i++)
    {
        channels_[i] = clampChannel(channels_[i], min[i], max[i]);
    }
}

} // namespace


std::ostream& operator<<(std::ostream& out, const tr::Color& color)
{
    for (unsigned i = 0; i < 4; i++)
    {
        out << color[i];
    }
    return out;
    return out;
}
