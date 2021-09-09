#pragma once

#include "mathlib.hpp"
#include <string>

namespace engine
{
class Entity
{
public:
    void SetTransform(float4x4 transform);

protected:
    float4x4 transform;
};

} // namespace engine