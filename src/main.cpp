#include "Image.hpp"
#include "ImageConverterPPM.hpp"

// TODO
#include "ShapeSphere.hpp"
#include "Ray.hpp"


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

    const glm::vec3 spherePosition(0.0f, 0.5f, -1.0f);
    const Transform sphereTransform(glm::translate(spherePosition));
    ShapeSphere sphere(sphereTransform);

    const glm::vec4 eyePosition(0.0f, 0.0f, 2.0f, 1.0f);
    const glm::vec4 eyeDirection(0.0f, 0.0f, -1.0f, 0.0f);
    const Ray eyeRay(eyePosition, eyeDirection, false);
    sphere.intersect(eyeRay);

    // auto x = new glm::mat4();
    // auto y = std::make_shared<glm::mat4>();
    // std::cout << glm::to_string(*x) << std::endl;
    return 0;
}
