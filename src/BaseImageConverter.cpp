#include "BaseImageConverter.hpp"
#include <fstream>


namespace tr
{

BaseImageConverter::BaseImageConverter(const Image& image)
: image_(image)
{
}

bool BaseImageConverter::save(const std::string& filename) const
{
    std::fstream f(filename, std::ios::binary | std::ios::out);
    return write(f);
}

} // namespace


std::ostream& operator<<(std::ostream& out, const tr::BaseImageConverter& conv)
{
    conv.write(out);
    return out;
}
