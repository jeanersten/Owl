#pragma once

#include "../../Core/Types.hpp"
#include "../Window.hpp"
#include <GLFW/glfw3.h>
#include <string>

namespace Owl
{
  class Win32Window : public Window
  {
  public:
    Win32Window(const WindowProps& props);
    ~Win32Window() override;

    void OnUpdate() override;
    inline Uint32 GetWidth() const override final { return m_data.width; }
    inline Uint32 GetHeight() const override final { return m_data.height; }
    void SetEventCallback(const EventCallbackFunc& callback) override final;
    void SetVSync(Bool enabled) override final;
    inline Bool IsVSynced() const override final { return m_data.vsync; }

  private:
    struct WindowData
    {
      std::string title;
      Uint32 width, height;
      bool vsync;
      EventCallbackFunc callback;

      WindowData() = default;
      ~WindowData() = default;
    };

    GLFWwindow* m_object;
    WindowData m_data;

    virtual void Setup(const WindowProps& properties);
    virtual void Cleanup();
  };

  static Bool s_glfw_initialized { false };
}
