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
    Camera(const Transform& t);
    virtual ~Camera() = default;

    Ray generateRay(const CameraSample& sample) const;

private:
    const Transform transform_;
};

} // namespace

#endif // __TR_CAMERA_HPP__
