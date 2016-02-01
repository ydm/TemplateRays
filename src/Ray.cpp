#include "Ray.hpp"


namespace tr
{

Ray::Ray()
: origin_()
, direction_()
{
}


Ray::Ray(const glm::vec3& origin, const glm::vec3& direction)
: origin_(origin)
, direction_(direction)
{
}

const glm::vec3& Ray::getOrigin() const
{
    return origin_;
}


const glm::vec3& Ray::getDirection() const
{
    return direction_;
}

} // namespace
