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
     * @param w2c -- World space to camera space transformation.
     */
    Camera(const Transform& w2c);
    virtual ~Camera() = default;

    Ray generateRay(const CameraSample& sample) const;

private:
    /**
     * World to camera space transformation.
     */
    const Transform w2c_;
};

} // namespace

#endif // __TR_CAMERA_HPP__
