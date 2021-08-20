#include "window.hpp"
#include <stdexcept>

namespace engine
{
Window::Window(std::uint32_t width, std::uint32_t height, char const* title)
    : window_(nullptr, glfwDestroyWindow)
{
    if (!glfwInit())
    {
        throw std::runtime_error("glfwInit() failed");
    }

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    // Create the main window
    window_.reset(glfwCreateWindow(width, height, title, nullptr, nullptr));

    if (!window_.get())
    {
        throw std::runtime_error("Failed to create GLFW window!");
    }

    glfwMakeContextCurrent(window_.get());

}

Window::~Window()
{

}

void Window::PollEvents()
{
    glfwPollEvents();
}

bool Window::ShouldClose() const
{
    return glfwWindowShouldClose(window_.get());
}


} // namespace engine
