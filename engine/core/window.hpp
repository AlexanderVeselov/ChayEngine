#pragma once

#include <GLFW/glfw3.h>
#include <cstdint>
#include <memory>

namespace engine
{
class Window
{
public:
    Window(std::uint32_t width, std::uint32_t height, char const* title);
    ~Window();

    void PollEvents();
    bool ShouldClose() const;

private:
    std::unique_ptr<GLFWwindow, void(*)(GLFWwindow*)> window_;
};

} // namespace engine
