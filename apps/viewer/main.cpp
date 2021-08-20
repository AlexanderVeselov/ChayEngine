#include "core/application.hpp"
#include <iostream>

class ViewerApp : public engine::Application
{
public:
    void OnInit() override
    {
        CreateWindow(1280, 720, "ViewerApp");
    }
};

int main(int argc, char** argv)
{
    ViewerApp application;

    try
    {
        application.Run();

    }
    catch (std::exception& ex)
    {
        std::cerr << "Caught exception:\n" << ex.what() << std::endl;
        return -1;
    }

    return 0;
}
