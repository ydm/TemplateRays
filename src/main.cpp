#include "Image.hpp"
#include "ImageConverterPPM.hpp"

// TODO
#include <iostream>
#include "OrthographicCamera.hpp"
#include "ShapeSphere.hpp"
#include "Ray.hpp"
#include <cmath>


namespace
{

tr::ColorRGB nedy1(float x, float y)
{
    // (x, y)
    // distance to .5 .5
    x = x * 2 + 0.5f;
    y = y * 2 + 0.5f;
    float a = x - 0.5f;
    float b = y - 0.5f;
    float distance = std::sqrt(a*a + b*b);
    
    float c = x + 0.25f;
    float d = y + 0.25f;
    float distanceG = std::sqrt(c*c + d*d);
    // 1:  0.707106781187
    return tr::ColorRGB::fromFloat(
        0.0f,
        distanceG,
        0.707106781187 - distance,
        1.0f
    );
}

tr::ColorRGB f(float x, float y)
{
    using namespace std;
    
    //x = x * 2;
    y = y * 2;
    int z = sqrt(x*x + y*y);
    
    float c = x + 0.25f;
    float d = y + 0.25f;
    float distanceG = sqrt(c*c + d*d);
    
    return tr::ColorRGB::fromFloat(
        x,
        sin(distanceG),
        abs(cos(z)),
        1.0f
    );
}

} // namespace


int main()
{
    using namespace tr;

    const unsigned WIDTH  = 600u;
    const unsigned HEIGHT = 600u;

    const glm::mat4 rasterToNdc(
        
    );

    Image image(WIDTH, HEIGHT);
    for (unsigned row = 0; row < HEIGHT; row++)
    {
        for (unsigned col = 0; col < WIDTH; col++)
        {
            const float ndcx = static_cast<float>(col) / (WIDTH  - 1);
            const float ndcy = static_cast<float>(row) / (HEIGHT - 1);
            image.setColorRGB(row, col, f(ndcx, ndcy));
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
    // const float x2     = (right - left);
    // const float y2     = (top - bottom);
    // const glm::mat4 ndcToWorld(
    //       x2, 0.0f, 0.0f, 0.0f,
    //     0.0f,   y2, 0.0f, 0.0f,
    //     0.0f, 0.0f, 1.0f, 0.0f,
    //     0.0f, 0.0f, 0.0f, 1.0f
    // );

    // std::cout << ndcToWorld * glm::vec4() << std::endl;
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
