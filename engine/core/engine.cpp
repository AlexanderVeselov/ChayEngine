#include "engine.hpp"
#include "scene.hpp"
#include <chrono>
#include <iostream>

namespace engine
{
Engine::Engine()
{
    //render_ = std::make_unique<ForwardRender>();
    //scene_ = std::make_unique<Scene>();
}

void Engine::RunFrame()
{
    auto current_time_point = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double>(current_time_point.time_since_epoch()).count();
    //scene_->Update(dt);
    //render_->RenderFrame();
}

} // namespace engine
