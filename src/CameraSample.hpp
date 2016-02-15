#ifndef __TR_CAMERA_SAMPLE_HPP__
#define __TR_CAMERA_SAMPLE_HPP__

#include "default.hpp"


namespace tr
{

class CameraSample
{
public:
    CameraSample(const glm::vec2 coords, const float time);
    ~CameraSample() = default;

    inline const glm::vec2& getCoords() const
    {
        return coords_;
    }

    // inline const glm::vec2& getLens() const
    // {
    //     return lens_;
    // }

    inline float getTime() const
    {
        return time_;
    }

private:
    /**
     * NDC coordinates, right?
     */
    const glm::vec2 coords_;
    // const glm::vec2 lens_;
    const float time_;
};

} // namespace

#endif // __TR_CAMERA_SAMPLE_HPP__
