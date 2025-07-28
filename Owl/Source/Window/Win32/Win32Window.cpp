#include "../../Core/CorePCH.hpp" // IWYU pragma: keep
#include "../../Log/Log.hpp"
#include "Win32Window.hpp"
#include <GLFW/glfw3.h>

Owl::Win32Window::Win32Window(const WindowProps& properties)
  : m_object(nullptr)
  , m_data()
{
  Setup(properties);
}

Owl::Win32Window::~Win32Window()
{
  Cleanup();
}

void Owl::Win32Window::Setup(const WindowProps& properties)
{
  m_data.title = properties.title;
  m_data.width = properties.width;
  m_data.height = properties.height;

  OWL_LOG_ENGINE_INFO("Creating window: \"{0}\" with {1}x{2} size", properties.title, properties.width, properties.height);

  if (!s_glfw_initialized)
  {
    Int32 status { glfwInit() };
    OWL_ASSERT_ENGINE(status, "Could not initialize GLFW!");
    s_glfw_initialized = true;
  }

  m_object = glfwCreateWindow((Int32)m_data.width, (Int32)m_data.height, m_data.title.c_str(), nullptr, nullptr);
  glfwMakeContextCurrent(m_object);
  glfwSetWindowUserPointer(m_object, &m_data);
  SetVSync(true);
}

void Owl::Win32Window::Cleanup()
{
  glfwDestroyWindow(m_object);
  glfwTerminate();
}

void Owl::Win32Window::SetEventCallback(const EventCallbackFunc& callback)
{
  m_data.callback = callback;
}

void Owl::Win32Window::SetVSync(Bool enabled)
{
  glfwSwapInterval(enabled ? 1 : 0);
  m_data.vsync = enabled;
}

void Owl::Win32Window::OnUpdate()
{
  glfwPollEvents();
  glfwSwapBuffers(m_object);
}
