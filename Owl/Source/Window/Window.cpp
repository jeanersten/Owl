#include "../Core/CorePCH.hpp"   // IWYU pragma: keep
#include "../Core/Types.hpp"
#include "Window.hpp"
#include "Win32/Win32Window.hpp"

Owl::WindowProps::WindowProps(const std::string& title, Uint32 width, Uint32 height)
  : title(title)
  , width(width)
  , height(height)
{}

Owl::Window* Owl::Window::Create(const WindowProps& properties)
{
  return new Win32Window(properties);
}
