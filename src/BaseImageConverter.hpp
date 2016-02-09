#ifndef __TR_BASE_IMAGE_CONVERTER_HPP__
#define __TR_BASE_IMAGE_CONVERTER_HPP__

#include <ostream>
#include <string>


namespace tr
{

class Image;

class BaseImageConverter
{
public:
    BaseImageConverter(const Image& image);
    virtual ~BaseImageConverter() = default;
    virtual bool write(std::ostream&) const = 0;
    bool save(const std::string& filename) const;

protected:
    const Image& image_;

};

} // namespace


std::ostream& operator<<(std::ostream& out, const tr::BaseImageConverter& conv);

#endif // __TR_BASE_IMAGE_CONVERTER_HPP__
