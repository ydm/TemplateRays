#ifndef __TR_SHAPE_HPP__
#define __TR_SHAPE_HPP__

#include "Transform.hpp"


namespace tr
{

class Shape
{
public:
    /**
     * @param transform Object to world transformation
     */
    Shape(const Transform& o2w);
    virtual ~Shape() = default;

    virtual bool intersect(const Ray& ray) const = 0;

protected:
    const Transform o2w_;
};

} // namespace

#endif // __TR_SHAPE_HPP__
