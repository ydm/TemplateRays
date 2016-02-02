#ifndef __TR_SHAPE_SPHERE_HPP__
#define __TR_SHAPE_SPHERE_HPP__

#include "Shape.hpp"


namespace tr
{

class ShapeSphere : public Shape
{
public:
    ShapeSphere(const Transform& transform, const float radius = 1.0f);
    virtual ~ShapeSphere() = default;

    virtual bool intersect(const Ray& ray) const override;
    float getRadius() const;

private:
    const float radius_;
};

} // namespace


#endif // __TR_SHAPE_SPHERE_HPP__
