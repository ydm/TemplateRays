#ifndef __TR_PRECOMPILED_HPP__
#define __TR_PRECOMPILED_HPP__

// Standard C
#include <cassert>
#include <cmath>
#include <cstddef>

// Standard C++
#include <iostream>
#include <memory>

// GLM
#pragma GCC diagnostic push
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  include <glm/glm.hpp>
#  include <glm/ext.hpp>
#pragma GCC diagnostic pop

// TR
namespace tr
{

typedef glm::uvec4                 Color;
typedef std::shared_ptr<glm::mat4> SharedMat4;
// typedef glm::vec4                  Point;
// typedef glm::vec3                  Vector;

} // namespace

#endif // __TR_PRECOMPILED_HPP__
