#include "Transform.hpp"
#include "Ray.hpp"


namespace
{

tr::SharedMat4 shared(const glm::mat4& m)
{
    return std::make_shared<glm::mat4>(m);
}

tr::SharedMat4 inverse(const glm::mat4& m)
{
    const glm::mat4& inv = glm::inverse(m);
    return shared(inv);
}


tr::SharedMat4 inverse(const tr::SharedMat4& m)
{
    return inverse(*m);
}

} // namespace


namespace tr
{

Transform::Transform(const glm::mat4& m)
: m_(shared(m))
, inv_(inverse(m))
{
}


Transform::Transform(const glm::mat4& m, const glm::mat4& inv)
: m_(shared(m))
, inv_(shared(inv))
{
}


Transform::Transform(const SharedMat4& m)
: m_(m)
, inv_(inverse(m))
{
}


Transform::Transform(const SharedMat4& m, const SharedMat4& inv)
: m_(m)
, inv_(inv)
{
}


Transform::Transform(const Transform& t)
: m_(t.m_)
, inv_(t.inv_)
{
}


Transform Transform::operator*(const Transform& other) const
{
    return Transform(
        (*this->m_)   * (*other.m_),
        (*other.inv_) * (*this->inv_)
    );
}


Ray Transform::operator*(const Ray& ray) const
{
    return Ray(
        (*m_) * ray.getOrigin(),
        (*m_) * ray.getDirection()
    );
}


glm::vec4 Transform::operator*(const glm::vec4& v) const
{
    return *m_ * v;
}


const glm::vec4& Transform::operator[](const std::size_t index) const
{
    return (*m_)[index];
}

} // namespace
