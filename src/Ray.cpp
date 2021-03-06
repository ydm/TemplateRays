#include "Ray.hpp"


namespace tr
{

Ray::Ray(const glm::vec4& origin, const glm::vec4& direction, const bool norm)
: origin_(origin)
, direction_(norm ? glm::fastNormalize(direction) : direction)
{
}

} // namespace
