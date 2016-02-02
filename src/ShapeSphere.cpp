#include "ShapeSphere.hpp"
#include "Ray.hpp"
#include "utilities.hpp"


namespace tr
{

ShapeSphere::ShapeSphere(const Transform& o2w, const float radius)
: Shape(o2w)
, radius_(radius)
{
}


bool ShapeSphere::intersect(const Ray& ray) const
{
    // Sphere origin in world space 
    const glm::vec4& sphereOrigin = o2w_[3];
    std::cout << "sphereOrigin=" << glm::to_string(sphereOrigin) << "\n";
    const glm::vec4& v = ray.getOrigin() - sphereOrigin;
    assert(v.w == 0.0f && "v.w should be zero");
    const float b = 2 * glm::dot(v, ray.getDirection());
    const float c = glm::dot(v, v) - radius_ * radius_;
    float x1 = -1.0f;
    float x2 = -1.0f;
    const int numRoots = quadraticRoots(1.0f, b, c, x1, x2);
    if (numRoots <= 0)
    {
        return false;
    }
    else if (numRoots == 1)
    {
        std::cout << "x1=" << x1 << std::endl;
        return true;
    }
    else if (numRoots == 2)
    {
        std::cout << "x1=" << x1 << ", " << "x2=" << x2 << std::endl;
        return true;
    }
}


float ShapeSphere::getRadius() const
{
    return radius_;
}

} // namespace
