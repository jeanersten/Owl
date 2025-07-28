#include "../Core/CorePCH.hpp" // IWYU pragma: keep
#include "../Core/Types.hpp"
#include "EventWindow.hpp"

Owl::EventWindowMoved::EventWindowMoved(Float32 x, Float32 y)
  : Event()
  , m_x(x)
  , m_y(y)
{}

Owl::EventType Owl::EventWindowMoved::GetEventType() const
{
  return GetStaticType();
}

Owl::EventCategory Owl::EventWindowMoved::GetCategoryFlags() const
{
  return (EventCategory::Window | EventCategory::Application);
}

const Owl::Char* Owl::EventWindowMoved::GetName() const
{
  return "(EVENT)WindowMoved";
}

std::string Owl::EventWindowMoved::GetString() const
{
  std::stringstream stream;
  stream << '[' << GetName() << ": " << "X (" << m_x << "), " << "Y (" << m_y << ")]";
  return stream.str();
}



Owl::EventWindowResized::EventWindowResized(Uint32 width, Uint32 height)
  : Event()
  , m_width(width)
  , m_height(height)
{}

Owl::EventType Owl::EventWindowResized::GetEventType() const
{
  return GetStaticType();
}

Owl::EventCategory Owl::EventWindowResized::GetCategoryFlags() const
{
  return (EventCategory::Window | EventCategory::Application);
}

const Owl::Char* Owl::EventWindowResized::GetName() const
{
  return "(EVENT)WindowResized";
}

std::string Owl::EventWindowResized::GetString() const
{
  std::stringstream stream;
  stream << '[' << GetName() << ": " << "Width (" << m_width << "), " << "Height (" << m_height << ")]";
  return stream.str();
}



Owl::EventWindowGainedFocus::EventWindowGainedFocus()
  : Event()
{}

Owl::EventType Owl::EventWindowGainedFocus::GetEventType() const
{
  return GetStaticType();
}

Owl::EventCategory Owl::EventWindowGainedFocus::GetCategoryFlags() const
{
  return (EventCategory::Window | EventCategory::Application);
}

const Owl::Char* Owl::EventWindowGainedFocus::GetName() const
{
  return "(EVENT)WindowGainedFocus";
}

std::string Owl::EventWindowGainedFocus::GetString() const
{
  std::stringstream stream;
  stream << '[' << GetName() << ": " << "Default!]";
  return stream.str();
}



Owl::EventWindowLostFocus::EventWindowLostFocus()
  : Event()
{}

Owl::EventType Owl::EventWindowLostFocus::GetEventType() const
{
  return GetStaticType();
}

Owl::EventCategory Owl::EventWindowLostFocus::GetCategoryFlags() const
{
  return (EventCategory::Window | EventCategory::Application);
}

const Owl::Char* Owl::EventWindowLostFocus::GetName() const
{
  return "(EVENT)WindowLostFocus";
}

std::string Owl::EventWindowLostFocus::GetString() const
{
  std::stringstream stream;
  stream << '[' << GetName() << ": " << "Default!]";
  return stream.str();
}



Owl::EventWindowClosed::EventWindowClosed()
  : Event()
{}

Owl::EventType Owl::EventWindowClosed::GetEventType() const
{
  return GetStaticType();
}

Owl::EventCategory Owl::EventWindowClosed::GetCategoryFlags() const
{
  return (EventCategory::Window | EventCategory::Application);
}

const Owl::Char* Owl::EventWindowClosed::GetName() const
{
  return "(EVENT)WindowClosed";
}

std::string Owl::EventWindowClosed::GetString() const
{
  std::stringstream stream;
  stream << '[' << GetName() << ": " << "Default!]";
  return stream.str();
}
