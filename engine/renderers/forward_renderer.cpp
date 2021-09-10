#include "forward_renderer.hpp"
#include "gpu_device.hpp"
#include "gpu_swapchain.hpp"
#include "gpu_queue.hpp"

namespace engine
{
ForwardRenderer::ForwardRenderer(gpu::Device& device,// ResourceManager& resource_manager,
    void* window_handle, std::uint32_t width, std::uint32_t height)
    : device_(device)
    //, resource_manager_(resource_manager)
{
    swapchain_ = device_.CreateSwapchain(window_handle, width, height);

    gpu::Queue& graphics_queue = device_.GetQueue(gpu::QueueType::kGraphics);

    compute_pipeline_ = device_.CreateComputePipeline("../../engine/shaders/shader.comp");

    auto& swapchain_images = swapchain_->GetImages();
    for (auto i = 0; i < swapchain_images.size(); ++i)
    {
        gpu::CommandBufferPtr cmd_buffer = graphics_queue.CreateCommandBuffer();
        gpu::ImagePtr image = swapchain_images[i];
        cmd_buffer->TransitionBarrier(image, gpu::ImageLayout::kPresent, gpu::ImageLayout::kRenderTarget);
        cmd_buffer->ClearImage(image, 0.5f, 0.5f, 1.0f, 1.0f);
        cmd_buffer->TransitionBarrier(image, gpu::ImageLayout::kRenderTarget, gpu::ImageLayout::kPresent);
        cmd_buffer->Dispatch(compute_pipeline_, 1, 1, 1);
        cmd_buffer->End();
        command_buffers_.push_back(std::move(cmd_buffer));

        fences_.push_back(device_.CreateFence());
    }

}

void ForwardRenderer::RenderView()
{
    gpu::Queue& graphics_queue = device_.GetQueue(gpu::QueueType::kGraphics);

    // Wait for the fence
    fences_[frame_index_]->Wait();
    // Submit the command buffer
    graphics_queue.Submit(command_buffers_[frame_index_], fences_[frame_index_]);
    // Present
    swapchain_->Present();

    frame_index_ = (frame_index_ + 1) % command_buffers_.size();
}

} // namespace engine
