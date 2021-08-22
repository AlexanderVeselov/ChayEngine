#include "application.hpp"
#include "window.hpp"
#include "renderers/forward_renderer.hpp"

namespace engine
{
void Application::OnInit()
{
}

void Application::OnUpdate()
{
}

void Application::OnRender()
{
}

void Application::OnGUI()
{
}

void Application::OnExit()
{
}

void Application::CreateWindow(std::uint32_t width, std::uint32_t height, char const* title)
{
    window_ = std::make_unique<Window>(1280, 720, "Test");
}

bool Application::GetKey() const
{
    return true;
}

void Application::CreateRenderDevice()
{
    render_api_.reset(gpu::Api::CreateD3D12Api());
    render_device_ = render_api_->CreateDevice();
}

void Application::Run()
{
    CreateRenderDevice();
    OnInit();

    while (window_ && !window_->ShouldClose())
    {
        window_->PollEvents();

        OnUpdate();
        OnRender();
        OnGUI();
    }

    OnExit();
}

} // namespace engine
