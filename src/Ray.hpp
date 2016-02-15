#ifndef __TR_RAY_HPP__
#define __TR_RAY_HPP__

#include "default.hpp"


namespace tr
{

class Ray
{
public:
    Ray() = default;
    /**
     * @param norm If true, direction will be normalized, otherwise
     * copied.
     */
    Ray(const glm::vec4& origin, const glm::vec4& direction, const bool norm = true);
    virtual ~Ray() = default;

    inline const glm::vec4& getOrigin() const
    {
        return origin_;
    }

    inline const glm::vec4& getDirection() const
    {
        return direction_;
    }

private:
    const glm::vec4 origin_;
    const glm::vec4 direction_;
};

} // namespace

#endif // __TR_RAY_HPP__
