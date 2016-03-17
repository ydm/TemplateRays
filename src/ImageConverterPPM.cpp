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
    for (unsigned row = 0; row < image_.getHeight(); row++)
    {
        for (unsigned col = 0; col < image_.getWidth(); col++)
        {
            const ColorRGB& pixel = image_.getColorRGB(row, col);
            for (unsigned k = 0; k < 3; k++)
            {
                out << pixel[k];
            }
        }
    }
    // for (unsigned i = 0; i < image_.getWidth(); i++)
    // {
    //     for (unsigned j = 0; j < image_.getHeight(); j++)
    //     {
    //         const ColorRGB& pixel = image_.getColorRGB(i, j);
    //         for (unsigned k = 0; k < 3; k++)
    //         {
    //             out << pixel[k];
    //         }
    //     }
    // }
    return out.good();
}

} // namespace
