#ifndef __TR_CAMERA_SAMPLE_HPP__
#define __TR_CAMERA_SAMPLE_HPP__

#include "default.hpp"


namespace tr
{

class CameraSample
{
public:
    CameraSample(const glm::vec2 pos,
                 const glm::vec2 lens,
                 const float time);
    ~CameraSample() = default;

    const glm::vec2 pos;
    const glm::vec2 lens;
    const float time;
};

} // namespace

#endif // __TR_CAMERA_SAMPLE_HPP__
