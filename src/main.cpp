#include "Image.hpp"
#include "ImageConverterPPM.hpp"

int main()
{
    using namespace tr;
    Image image(512, 512);
    for (unsigned i = 0; i < 512; i++)
    {
        for (unsigned j = 0; j < 512; j++)
        {
            image.setColor(i, j, Color(255, 0, 0, 255));
        }
    }
    const ImageConverterPPM conv(image);
    conv.save("output.ppm");
    return 0;
}
