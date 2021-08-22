#pragma once

#include "window.hpp"
#include "gpu_types.hpp"
#include "gpu_api.hpp"
#include "gpu_device.hpp"
#include "renderer.hpp"
#include <memory>

namespace engine
{

class Application
{
public:
    virtual void OnInit();
    virtual void OnUpdate();
    virtual void OnRender();
    virtual void OnGUI();
    virtual void OnExit();

    void CreateWindow(std::uint32_t width, std::uint32_t height, char const* title);
    template <class T> void CreateRenderer()
    {
        renderer_ = std::make_unique<T>(*render_device_, window_->GetNativeHandle(),
            window_->GetWidth(), window_->GetHeight());
    }

    void Run();
    bool GetKey() const;

private:
    void CreateRenderDevice();

    std::unique_ptr<Window> window_;
    std::unique_ptr<gpu::Api> render_api_;
    std::unique_ptr<gpu::Device> render_device_;
    std::unique_ptr<Renderer> renderer_;
};

} // namespace engine
