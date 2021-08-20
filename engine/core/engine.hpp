#pragma once

#include <memory>

namespace engine
{
class Render;
class Scene;

class Engine
{
public:
    Engine();
    void RunFrame();
    float GetCurtime() const;

private:
    //std::unique_ptr<Render> render_;
    //std::unique_ptr<Scene> scene_;
    float curtime_ = 0.0f;

};

} // namespace engine
