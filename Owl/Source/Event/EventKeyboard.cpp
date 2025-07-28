#include "../Core/CorePCH.hpp" // IWYU pragma: keep
#include "../Core/Types.hpp"
#include "EventKeyboard.hpp"

Owl::EventKeyboardKey::EventKeyboardKey(Int32 key_code)
  : Event()
  , m_key_code(key_code)
{}

Owl::EventCategory Owl::EventKeyboardKey::GetCategoryFlags() const
{
  return (EventCategory::Keyboard | EventCategory::Input);
}



Owl::EventKeyboardKeyPressed::EventKeyboardKeyPressed(Int32 key_code, Int32 repeat_count)
  : EventKeyboardKey(key_code)
  , m_repeat_count(repeat_count)
{}

Owl::EventType Owl::EventKeyboardKeyPressed::GetEventType() const
{
  return GetStaticType();
}

const Owl::Char* Owl::EventKeyboardKeyPressed::GetName() const
{
  return "(EVENT)KeyboardKeyPressed";
}

std::string Owl::EventKeyboardKeyPressed::GetString() const
{
  std::stringstream stream;
  stream << '[' << GetName() << ": " << "Key Code (" << m_key_code << ")]";
  return stream.str();
}



Owl::EventKeyboardKeyReleased::EventKeyboardKeyReleased(Int32 key_code)
  : EventKeyboardKey(key_code)
{}

Owl::EventType Owl::EventKeyboardKeyReleased::GetEventType() const
{
  return GetStaticType();
}

const Owl::Char* Owl::EventKeyboardKeyReleased::GetName() const
{
  return "(EVENT)KeyboardKeyReleased";
}

std::string Owl::EventKeyboardKeyReleased::GetString() const
{
  std::stringstream stream;
  stream << '[' << GetName() << ": " << "Key Code (" << m_key_code << ")]";
  return stream.str();
}
