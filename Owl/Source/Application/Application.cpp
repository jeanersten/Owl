#include "../Core/CorePCH.hpp"  // IWYU pragma: keep
#include "../Window/Window.hpp"
#include "Application.hpp"
#include <GL/GL.h>

Owl::Application::Application()
  : m_running(true)
  , m_window(std::unique_ptr<Window>(Window::Create()))
{}

void Owl::Application::Run()
{
  glClearColor(0.38f, 0.53f, 0.52f, 1.0f);

  while (m_running)
  {
    glClear(GL_COLOR_BUFFER_BIT);
    m_window->OnUpdate();
  }
}
