#ifndef __TR_TRANSFORM_HPP__
#define __TR_TRANSFORM_HPP__

#include "default.hpp"


namespace tr
{

class Ray;


class Transform
{
public:
    Transform() = default;
    Transform(const glm::mat4& m);
    Transform(const glm::mat4& m, const glm::mat4& inv);
    Transform(const SharedMat4& m);
    Transform(const SharedMat4& m, const SharedMat4& inv);
    Transform(const Transform& t);

    virtual ~Transform() = default;

    Transform operator*(const Transform& other) const;
    Ray       operator*(const Ray& ray) const;
    glm::vec4 operator*(const glm::vec4& v) const;

    const glm::vec4& operator[](const int index) const;

private:
    const SharedMat4 m_;
    // TODO: Make this mutable, null it, inverse and cache once the
    // user asks for it.
    const SharedMat4 inv_;
};

} // namespace

#endif // __TR_TRANSFORM_HPP__
