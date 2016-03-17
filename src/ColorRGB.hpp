#ifndef __TR_COLOR_HPP__
#define __TR_COLOR_HPP__

#include <cstddef>
#include <ostream>


namespace tr
{

class ColorRGB
{
public:
    static ColorRGB fromFloat(const float red   = 0.0f,
                              const float green = 0.0f,
                              const float blue  = 0.0f,
                              const float alpha = 0.0f);

    ColorRGB(const unsigned char red   = 0u,
             const unsigned char green = 0u,
             const unsigned char blue  = 0u,
             const unsigned char alpha = 0u);
    // ColorRGB(const float red   = 0.0f,
    //          const float green = 0.0f,
    //          const float blue  = 0.0f,
    //          const float alpha = 0.0f);
    ~ColorRGB() = default;


    // Accessors
    // ---------

    inline unsigned char getRed  () const { return channels_[0]; }
    inline unsigned char getGreen() const { return channels_[1]; }
    inline unsigned char getBlue () const { return channels_[2]; }
    inline unsigned char getAlpha() const { return channels_[3]; }

    inline unsigned char operator[](const std::size_t i) const
    {
        return channels_[i];
    }

    inline unsigned char& operator[](const std::size_t i)
    {
        return channels_[i];
    }


    // Static methods
    // --------------

    static ColorRGB clamp(const ColorRGB& x, const ColorRGB& min, const ColorRGB& max);


    // Const methods
    // -------------

    inline ColorRGB clamp(const ColorRGB& min, const ColorRGB& max) const
    {
        return clamp(*this, min, max);
    }


    // Modifier methods
    // ----------------

    void clamp(const ColorRGB& min, const ColorRGB& max);

private:
    unsigned char channels_[4];
};

} // namespace


std::ostream& operator<<(std::ostream& out, const tr::ColorRGB& color);


#endif // __TR_COLOR_HPP__
