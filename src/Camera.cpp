#include "Camera.hpp"


namespace tr
{

Camera::Camera(const Transform& w2c)
: w2c_(w2c)
{
}


Ray Camera::generateRay(const CameraSample& /* sample */) const
{
    return Ray();
}

} // namespace
