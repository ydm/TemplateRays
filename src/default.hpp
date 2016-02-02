#ifndef __TR_DEFAULT_HPP__
#define __TR_DEFAULT_HPP__

// Standard C
#include <cassert>
#include <cmath>
#include <cstddef>

// Standard C++
#include <iostream>
#include <memory>

// GLM
#include <glm/glm.hpp>
#include <glm/ext.hpp>

// TR
typedef glm::uvec4 Color;
// typedef glm::vec4 Point;
typedef std::shared_ptr<glm::mat4> SharedMat4;

#endif // __TR_DEFAULT_HPP__
