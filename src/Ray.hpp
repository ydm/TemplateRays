#ifndef __TR_RAY_HPP__
#define __TR_RAY_HPP__

#include "default.hpp"


namespace tr
{

class Ray
{
public:
    Ray();
    Ray(const glm::vec3& origin, const glm::vec3& direction);
    ~Ray() = default;

    const glm::vec3& getOrigin() const;
    const glm::vec3& getDirection() const;

private:
    const glm::vec3 origin_;
    const glm::vec3 direction_;
};

} // namespace


#endif // __TR_RAY_HPP__
