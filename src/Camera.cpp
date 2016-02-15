#include "Camera.hpp"


namespace tr
{

Camera::Camera(const Transform& c2w)
: c2w_(c2w)
{
}


Ray Camera::generateRay(const CameraSample& /* sample */) const
{
    return Ray();
}

} // namespace
