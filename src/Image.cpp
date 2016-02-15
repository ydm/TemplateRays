#include "Image.hpp"


namespace tr
{

Image::Image(const unsigned w, const unsigned h)
: pixels_(new ColorRGB [w * h] ())
, width_(w)
, height_(h)
{
}


Image::~Image()
{
    // NOOP
}


unsigned Image::getWidth() const
{
    return width_;
}


unsigned Image::getHeight() const
{
    return height_;
}


const ColorRGB& Image::getColorRGB(const unsigned x, const unsigned y) const
{
    return pixels_[x * width_ + y];
}


void Image::setColorRGB(const unsigned x, const unsigned y, const ColorRGB& c)
{
    static const ColorRGB MIN(   0u,    0u,    0u,    0u);
    static const ColorRGB MAX(0xFFu, 0xFFu, 0xFFu, 0xFFu);
    pixels_[x * width_ + y] = c.clamp(MIN, MAX);
}


// size_t Image::byteLength()
// {
//     return sizeof(Color) * length();
// }


// size_t Image::length()
// {
//     return width_ * height_;
// }

} // namespace
