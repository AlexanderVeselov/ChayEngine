#pragma once

#include "window.hpp"
#include "engine.hpp"
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
    void Run();
    bool GetKey();

private:
    std::unique_ptr<Window> window_;
    Engine engine_;
};

} // namespace engine
