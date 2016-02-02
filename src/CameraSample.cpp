#include "CameraSample.hpp"


namespace tr
{

CameraSample::CameraSample(const glm::vec2 coords,
                           const glm::vec2 lens,
                           const float time)
: coords(coords)
, lens(lens)
, time(time)
{
}

} // namespace
