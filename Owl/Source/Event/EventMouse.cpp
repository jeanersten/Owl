#include "../Core/Types.hpp"
#include "EventMouse.hpp"
#include <sstream>
#include <string>

Owl::EventMouseMoved::EventMouseMoved(Float32 x, Float32 y)
  : Event()
  , m_x(x)
  , m_y(y)
{}

Owl::EventType Owl::EventMouseMoved::GetEventType() const
{
  return GetStaticType();
}

Owl::EventCategory Owl::EventMouseMoved::GetCategoryFlags() const
{
  return (EventCategory::MOUSE | EventCategory::INPUT);
}

const Owl::Char* Owl::EventMouseMoved::GetName() const
{
  return "(EVENT)MouseMoved";
}

std::string Owl::EventMouseMoved::GetString() const
{
  std::stringstream stream;
  stream << '[' << GetName() << ": " << "X (" << m_x << "), Y (" << m_y << ")]";
  return stream.str();
}



Owl::EventMouseScrolled::EventMouseScrolled(Float32 x_offset, Float32 y_offset)
  : Event()
  , m_x_offset(x_offset)
  , m_y_offset(y_offset)
{}

Owl::EventType Owl::EventMouseScrolled::GetEventType() const
{
  return GetStaticType();
}

Owl::EventCategory Owl::EventMouseScrolled::GetCategoryFlags() const
{
  return (EventCategory::MOUSE | EventCategory::INPUT);
}

const Owl::Char* Owl::EventMouseScrolled::GetName() const
{
  return "(EVENT)MouseScrolled";
}

std::string Owl::EventMouseScrolled::GetString() const
{
  std::stringstream stream;
  stream << '[' << GetName() << ": " << "X Offset (" << m_x_offset << "), Y Offset (" << m_y_offset << ")]";
  return stream.str();
}



Owl::EventMouseButton::EventMouseButton(Int32 button_code)
  : Event()
  , m_button_code(button_code)
{}

Owl::EventCategory Owl::EventMouseButton::GetCategoryFlags() const
{
  return (EventCategory::MOUSE | EventCategory::INPUT);
}



Owl::EventMouseButtonPressed::EventMouseButtonPressed(Int32 button_code)
  : EventMouseButton(button_code)
{}

Owl::EventType Owl::EventMouseButtonPressed::GetEventType() const
{
  return GetStaticType();
}

const Owl::Char* Owl::EventMouseButtonPressed::GetName() const
{
  return "(EVENT)MouseButtonPressed";
}

std::string Owl::EventMouseButtonPressed::GetString() const
{
  std::stringstream stream;
  stream << '[' << GetName() << ": " << "Button Code (" << m_button_code << ")]";
  return stream.str();
}



Owl::EventMouseButtonReleased::EventMouseButtonReleased(Int32 button_code)
  : EventMouseButton(button_code)
{}

Owl::EventType Owl::EventMouseButtonReleased::GetEventType() const
{
  return GetStaticType();
}

const Owl::Char* Owl::EventMouseButtonReleased::GetName() const
{
  return "(EVENT)MouseButtonReleased";
}

std::string Owl::EventMouseButtonReleased::GetString() const
{
  std::stringstream stream;
  stream << '[' << GetName() << ": " << "Button Code (" << m_button_code << ")]";
  return stream.str();
}
