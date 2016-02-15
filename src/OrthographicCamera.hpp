#ifndef __TR_ORTHOGRAPHIC_CAMERA_HPP__
#define __TR_ORTHOGRAPHIC_CAMERA_HPP__

#include "Camera.hpp"


namespace tr
{

class OrthographicCamera /* : public Camera */
{
public:
    OrthographicCamera(const float left,
                       const float right,
                       const float bottom,
                       const float top,
                       const float near,
                       const float far) {}
    virtual ~OrthographicCamera() {}

    inline glm::mat4 worldToCamera(const float left,
                                    const float right,
                                    const float bottom,
                                    const float top,
                                    const float near,
                                    const float far) const
    {
        // TODO: REMOVE
        const float x =  2 / (right - left);
        const float y =  2 / (top - bottom);
        const float z = -2 / (far - near);
        const float tx = - (right + left) / (right - left);
        const float ty = - (top + bottom) / (top - bottom);
        const float tz = - (far + near)   / (far - near);
        return glm::mat4(
               x, 0.0f, 0.0f, 0.0f,
            0.0f,    y, 0.0f, 0.0f,
            0.0f, 0.0f,    z, 0.0f,
              tx,   ty,   tz, 1.0f
        );
    }

private:
    glm::mat4 qwe;
};

} // namespace

#endif // __TR_ORTHOGRAPHIC_CAMERA_HPP__
