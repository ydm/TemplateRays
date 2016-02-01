#ifndef __TR_IMAGE_CONVERTER_PPM_HPP__
#define __TR_IMAGE_CONVERTER_PPM_HPP__

#include "BaseImageConverter.hpp"


namespace tr
{

class ImageConverterPPM : public BaseImageConverter
{
public:
    ImageConverterPPM(const Image& image);
    virtual ~ImageConverterPPM();
    virtual bool write(std::ostream&) const;
};

} // namespace

#endif // __TR_IMAGE_CONVERTER_PPM_HPP__
