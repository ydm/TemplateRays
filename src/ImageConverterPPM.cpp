#include "ImageConverterPPM.hpp"
#include "Image.hpp"


namespace tr
{

ImageConverterPPM::ImageConverterPPM(const Image& image)
: BaseImageConverter(image)
{
}


ImageConverterPPM::~ImageConverterPPM()
{
    // NOOP
}


bool ImageConverterPPM::write(std::ostream& out) const
{
    out << "P6 "
        << image_.getWidth() << " "
        << image_.getHeight() << " "
        << "255 ";
    for (unsigned i = 0; i < image_.getWidth(); i++)
    {
        for (unsigned j = 0; j < image_.getHeight(); j++)
        {
            const Color& pixel = image_.getColor(i, j);
            for (unsigned k = 0; k < 3; k++)
            {
                out << static_cast<char>(pixel[k]);
            }
        }
    }
    return out.good();
}

} // namespace
