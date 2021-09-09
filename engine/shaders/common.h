#ifndef SHADER_COMMON_H
#define SHADER_COMMON_H

#ifdef __cplusplus
#include "core/mathlib.hpp"
#endif

struct CameraView
{
    float4x4 view_projection;
    float4x4 view_projection_inverse;
    float4x4 prev_view_projection;
    float4x4 prev_view_projection_inverse;
    float3 origin;
    float z_near;
    float z_far;
};

//struct Vertex
//{
//    float3 position;
//    float3 normal;
//    float2 texcoord;
//};

#endif // SHADER_COMMON_H
