#include "Image.hpp"
#include "ImageConverterPPM.hpp"

// TODO
#include <iostream>
#include "OrthographicCamera.hpp"
#include "ShapeSphere.hpp"
#include "Ray.hpp"


int main()
{
    const unsigned WIDTH  = 800u;
    const unsigned HEIGHT = 600u;
    using namespace tr;
    Image image(WIDTH, HEIGHT);
    for (unsigned i = 0; i < WIDTH; i++)
    {
        for (unsigned j = 0; j < HEIGHT; j++)
        {
            image.setColorRGB(i, j, ColorRGB(255u, 0u, 0u, 255u));
        }
    }
    const ImageConverterPPM conv(image);
    conv.save("output.ppm");

    // const glm::vec3 spherePosition(0.0f, 0.5f, -1.0f);
    // const Transform sphereTransform(glm::translate(spherePosition));
    // ShapeSphere sphere(sphereTransform);

    // const glm::vec4 eyePosition(0.0f, 0.0f, 2.0f, 1.0f);
    // const glm::vec4 eyeDirection(0.0f, 0.0f, -1.0f, 0.0f);
    // const Ray eyeRay(eyePosition, eyeDirection, false);

    // sphere.intersect(eyeRay);
    // std::cout << "sizeof(ShapeSphere): " << sizeof(ShapeSphere) << std::endl;

    // auto x = new glm::mat4();
    // auto y = std::make_shared<glm::mat4>();
    // std::cout << glm::to_string(*x) << std::endl;

    // mat4:
    // -x-
    // -y-
    // -z-
    // -t-
    // const float x1 = 1.0f / 800.0f;
    // const float y1 = 1.0f / 600.0f;
    // const glm::mat4 rasterToNdc(
    //       x1, 0.0f, 0.0f, 0.0f,
    //     0.0f,   y1, 0.0f, 0.0f,
    //     0.0f, 0.0f, 1.0f, 0.0f,
    //     0.0f, 0.0f, 0.0f, 1.0f
    // );

    const float right  =  5.0f;
    const float left   = -5.0f;
    const float top    =  5.0f;
    const float bottom = -5.0f;
    // const float near   =  0.0f;
    // const float far    = 10.0f;
    const float x2     = (right - left);
    const float y2     = (top - bottom);
    const glm::mat4 ndcToWorld(
          x2, 0.0f, 0.0f, 0.0f,
        0.0f,   y2, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    );

    std::cout << ndcToWorld * glm::vec4() << std::endl;

    // for (float x = 0.5f; x <= 799.5f; x += 1.0f)
    // {
    //     for (float y = 0.5f; y <= 599.5f; y += 1.0f)
    //     {
    //         const glm::vec4 pixel(x, y, 0.0f, 1.0f);
    //         std::cout << "pixel=[" << x << ", " << y << "], "
    //                   << "multed=" << glm::to_string(ndcToWorld * rasterToNdc * pixel)
    //                   << std::endl;
    //     }
    // }

    return 0;
}
