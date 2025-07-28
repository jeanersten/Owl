#pragma once

#include "../Core/Types.hpp"
#include "Event.hpp"
#include <string>

namespace Owl
{
  class OWL_API EventKeyboardKey : public Event
  {
  public:
    inline Int32  GetKeyCode() const { return m_key_code; }
    EventCategory GetCategoryFlags() const override final;

  protected:
    EventKeyboardKey(Int32 key_code);
    ~EventKeyboardKey() override = default;

    Int32 m_key_code;
  };


  class OWL_API EventKeyboardKeyPressed : public EventKeyboardKey
  {
  public:
    EventKeyboardKeyPressed(Int32 key_code, Int32 repeat_count);
    ~EventKeyboardKeyPressed() override = default;

    inline Int32            GetRepeatCount() const { return m_repeat_count; }
    inline static EventType GetStaticType() { return EventType::KeyboardKeyPressed; }
    EventType               GetEventType() const override final;
    const Char*             GetName() const override final;
    std::string             GetString() const override final;

  private:
    Int32 m_repeat_count;
  };


  class OWL_API EventKeyboardKeyReleased : public EventKeyboardKey
  {
  public:
    EventKeyboardKeyReleased(Int32 key_code);
    ~EventKeyboardKeyReleased() override = default;

    inline static EventType GetStaticType() { return EventType::KeyboardKeyReleased; }
    EventType               GetEventType() const override final;
    const Char*             GetName() const override final;
    std::string             GetString() const override final;
  };
}
