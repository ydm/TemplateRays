#include "CameraSample.hpp"


namespace tr
{

CameraSample::CameraSample(const glm::vec2 pos,
                           const glm::vec2 lens,
                           const float time)
: pos(pos)
, lens(lens)
, time(time)
{
}

} // namespace
