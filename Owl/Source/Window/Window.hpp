#pragma once

#include "../Core/Core.hpp"
#include "../Core/Types.hpp"
#include "../Event/Event.hpp"
#include <functional>
#include <string>

namespace Owl
{
  struct WindowProps
  {
    std::string title;
    Uint32 width;
    Uint32 height;

    WindowProps(const std::string& title = "Owl!", Uint32 width = 640, Uint32 height = 480);
    ~WindowProps() = default;
  };

  class OWL_API Window
  {
  public:
    using EventCallbackFunc = std::function<void(Event&)>;

    Window() = default;
    virtual ~Window() = default;

    virtual void OnUpdate() = 0;
    inline virtual Uint32 GetWidth() const = 0;
    inline virtual Uint32 GetHeight() const = 0;
    virtual void SetEventCallback(const EventCallbackFunc& callback) = 0;
    virtual void SetVSync(Bool enabled) = 0; 
    inline virtual bool IsVSynced() const = 0;

    static Window* Create(const WindowProps& properties = WindowProps());
  };
}
