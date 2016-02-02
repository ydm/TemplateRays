#ifndef __TR_UTILITIES_HPP__
#define __TR_UTILITIES_HPP__

#include "default.hpp"


namespace tr
{

/**
 * Return the number of roots found or -1 in case `a` is zero.
 */
int quadraticRoots(const float a, const float b, const float c,
                   float& x1, float& x2);

} // namespace

#endif // __TR_UTILITIES_HPP__
