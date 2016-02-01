#include "Image.hpp"


namespace tr
{

Image::Image(const unsigned w, const unsigned h)
: pixels_(new Color[w * h]())
, width_(w)
, height_(h)
{
}


Image::~Image()
{
    delete pixels_;
}


unsigned Image::getWidth() const
{
    return width_;
}


unsigned Image::getHeight() const
{
    return height_;
}


const Color& Image::getColor(const unsigned x, const unsigned y) const
{
    return pixels_[x * width_ + y];
}


void Image::setColor(const unsigned x, const unsigned y, const Color& c)
{
    static const Color MIN(   0,    0,    0,    0);
    static const Color MAX(0xFF, 0xFF, 0xFF, 0xFF);
    pixels_[x * width_ + y] = glm::clamp(c, MIN, MAX);
}


size_t Image::byteLength()
{
    return sizeof(Color) * length();
}


size_t Image::length()
{
    return width_ * height_;
}

} // namespace
