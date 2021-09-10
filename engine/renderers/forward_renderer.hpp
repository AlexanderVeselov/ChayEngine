#pragma once

#include "core/renderer.hpp"
#include "gpu_types.hpp"
#include "gpu_swapchain.hpp"
#include "gpu_command_buffer.hpp"
#include "gpu_sync.hpp"
#include "gpu_pipeline.hpp"
#include "entities/camera.hpp"
#include <memory>


namespace engine
{
class ResourceManager;

class ForwardRenderer : public Renderer
{
public:
    ForwardRenderer(gpu::Device& device, //ResourceManager& resource_manager,
        void* window_handle, std::uint32_t width, std::uint32_t height);
    void RenderView() override;

private:
    gpu::Device& device_;
    //ResourceManager& resource_manager_;
    gpu::SwapchainPtr swapchain_;
    std::vector<gpu::CommandBufferPtr> command_buffers_;
    std::vector<gpu::FencePtr> fences_;
    std::uint32_t frame_index_ = 0;
    gpu::ComputePipelinePtr compute_pipeline_;

};

} // namespace engine
