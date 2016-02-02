#include "Camera.hpp"


namespace tr
{

Camera::Camera(const Transform& t)
: transform_(t)
{
}


Ray Camera::generateRay(const CameraSample& sample) const
{
}

} // namespace
