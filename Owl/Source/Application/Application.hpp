#pragma once

#include "../Window/Window.hpp"
#include "../Core/Core.hpp"
#include <memory>

namespace Owl
{
  class OWL_API Application
  {
  public:
    Application();
    virtual ~Application() = default;

    void Run();

  private:
    Bool m_running;
    std::unique_ptr<Window> m_window;
  };

  Application* CreateApplication();
}
