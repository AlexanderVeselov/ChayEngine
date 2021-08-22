#include "forward_renderer.hpp"
#include "gpu_device.hpp"
#include "gpu_swapchain.hpp"

namespace engine
{
ForwardRenderer::ForwardRenderer(gpu::Device& device,// ResourceManager& resource_manager,
    void* window_handle, std::uint32_t width, std::uint32_t height)
    : device_(device)
    //, resource_manager_(resource_manager)
{
    swapchain_ = device_.CreateSwapchain(window_handle, width, height);
}

void ForwardRenderer::RenderFrame()
{
    swapchain_->GetImages();
}

} // namespace engine
