#include "utilities.hpp"


namespace
{

inline float quadraticDiscriminant(const float a, const float b, const float c)
{
    return (b * b) - (4 * a * c);
}

} // namespace


namespace tr
{

int quadraticRoots(const float a, const float b, const float c,
                   float& x1, float& x2)
{
    if (a == 0.0f)
    {
        x1 = -c / b;
        return 1;
    }
    const float discriminant = quadraticDiscriminant(a, b, c);
    if (discriminant < 0.0f)
    {
        return 0;
    }
    else if (discriminant == 0.0f)
    {
        x1 = -b / (2 * a);
        return 1;
    }
    else
    {
        const float sr = std::sqrt(discriminant);
        const float a2 = a * 2;
        x1 = (-b + sr) / a2;
        x2 = (-b - sr) / a2;
        return 2;
    }
}


int numQuadraticRoots(const float a, const float b, const float c)
{
    const float d = quadraticDiscriminant(a, b, c);
    if (d < 0.0f)
    {
        return 0;
    }
    else if (d == 0.0f)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

} // namespace
