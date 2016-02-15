#ifndef __TR_CAMERA_HPP__
#define __TR_CAMERA_HPP__

#include "CameraSample.hpp"
#include "Ray.hpp"
#include "Transform.hpp"


namespace tr
{

class Camera
{
public:
    Camera() = default;
    /**
     * @param w2c -- Camera space to world space transformation.
     */
    Camera(const Transform& c2w);
    virtual ~Camera() = default;

    Ray generateRay(const CameraSample& sample) const;

private:
    /**
     * World to camera space transformation.
     */
    const Transform c2w_;
};

} // namespace

#endif // __TR_CAMERA_HPP__
