#pragma once

#include "core/renderer.hpp"
#include "gpu_types.hpp"
#include "gpu_swapchain.hpp"

#include <memory>


namespace engine
{
class ResourceManager;

class ForwardRenderer : public Renderer
{
public:
    ForwardRenderer(gpu::Device& device, //ResourceManager& resource_manager,
        void* window_handle, std::uint32_t width, std::uint32_t height);
    void RenderFrame() override;

private:
    gpu::Device& device_;
    //ResourceManager& resource_manager_;
    gpu::SwapchainPtr swapchain_;

};

} // namespace engine
