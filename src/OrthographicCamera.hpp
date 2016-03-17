#ifndef __TR_ORTHOGRAPHIC_CAMERA_HPP__
#define __TR_ORTHOGRAPHIC_CAMERA_HPP__

#include "Camera.hpp"


namespace tr
{

class OrthographicCamera /* : public Camera */
{
public:
    OrthographicCamera(float /* left   */,
                       float /* right  */,
                       float /* bottom */,
                       float /* top    */,
                       float /* near   */,
                       float /* far    */) {}

    virtual ~OrthographicCamera() {}

    inline glm::mat4 worldToCamera(float /* left   */,
                                   float /* right  */,
                                   float /* bottom */,
                                   float /* top    */,
                                   float /* near   */,
                                   float /* far    */) const
    {
        // TODO: REMOVE
        // const float x =  2 / (right - left);
        // const float y =  2 / (top - bottom);
        // const float z = -2 / (far - near);
        // const float tx = - (right + left) / (right - left);
        // const float ty = - (top + bottom) / (top - bottom);
        // const float tz = - (far + near)   / (far - near);
        // return glm::mat4(
        //        x, 0.0f, 0.0f, 0.0f,
        //     0.0f,    y, 0.0f, 0.0f,
        //     0.0f, 0.0f,    z, 0.0f,
        //       tx,   ty,   tz, 1.0f
        // );
        return glm::mat4();
    }

private:
    glm::mat4 qwe;
};

} // namespace

#endif // __TR_ORTHOGRAPHIC_CAMERA_HPP__
