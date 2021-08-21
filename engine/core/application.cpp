#include "application.hpp"
#include "window.hpp"

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

bool Application::GetKey()
{
    return true;
}

void Application::Run()
{
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
