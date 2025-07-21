#pragma once

#include "../Core/Core.hpp"

namespace Owl
{
  class OWL_API Application
  {
  public:
    Application() = default;
    virtual ~Application() = default;

    void Run();
  };

  Application* CreateApplication();
}
