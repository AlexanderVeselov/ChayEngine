#pragma once

#include "core/renderer.hpp"

#include <memory>

#include "gpu_types.hpp"

namespace engine
{
class ResourceManager;

class ForwardRenderer : public Renderer
{
public:
    ForwardRenderer(gpu::Device& device, ResourceManager& resource_manager);
    void RenderFrame() override;

private:
    gpu::Device& device_;
    ResourceManager& resource_manager_;

};

} // namespace engine
