#ifndef __TR_IMAGE_HPP__
#define __TR_IMAGE_HPP__

#include "default.hpp"


namespace tr
{

class Image
{
public:
    Image(const unsigned w, const unsigned h);
    virtual ~Image();

    /**
     * Get image width.
     */
    unsigned getWidth() const;
    /**
     * Get image height.
     */
    unsigned getHeight() const;
    /**
     * Return black if (x, y) is out of bounds.
     */
    const ColorRGB& getColorRGB(const unsigned x, const unsigned y) const;
    /**
     * Set color of pixel at (x, y).
     */
    void setColorRGB(const unsigned x, const unsigned y, const ColorRGB& c);

private:
    // size_t byteLength();
    // size_t length();

    const std::unique_ptr<ColorRGB[]> pixels_;
    const unsigned width_;
    const unsigned height_;
};

} // namespace

#endif // __TR_IMAGE_HPP__
