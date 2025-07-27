#pragma once

#include "../Core/Types.hpp"
#include "Event.hpp"
#include <string>

namespace Owl
{
  class OWL_API EventMouseMoved : public Event
  {
  public:
    EventMouseMoved(Float32 x, Float32 y);
    ~EventMouseMoved() override = default;

    inline Float32          GetX() const { return m_x; }
    inline Float32          GetY() const { return m_y; }
    inline static EventType GetStaticType() { return EventType::MOUSE_MOVED; }
    EventType               GetEventType() const override final;
    EventCategory           GetCategoryFlags() const override final;
    const Char*             GetName() const override final;
    std::string             GetString() const override;

  private:
    Float32 m_x;
    Float32 m_y;
  };


  class OWL_API EventMouseScrolled : public Event
  {
  public:
    EventMouseScrolled(Float32 x_offset, Float32 y_offset);
    ~EventMouseScrolled() override = default;

    inline Float32          GetXOffset() const { return m_x_offset; }
    inline Float32          GetYOffset() const { return m_y_offset; }
    inline static EventType GetStaticType() { return EventType::MOUSE_SCROLLED; }
    EventType               GetEventType() const override final;
    EventCategory           GetCategoryFlags() const override final;
    const Char*             GetName() const override final;
    std::string             GetString() const override;

  private:
    Float32 m_x_offset;
    Float32 m_y_offset;
  };


  class OWL_API EventMouseButton : public Event
  {
  public:
    inline Int32            GetMouseButtonCode() const { return m_button_code; }
    EventCategory           GetCategoryFlags() const override final;

  protected:
    EventMouseButton(Int32 button_code);
    virtual ~EventMouseButton() override = default;

    Int32 m_button_code;
  };


  class OWL_API EventMouseButtonPressed : public EventMouseButton
  {
  public:
    EventMouseButtonPressed(Int32 button_code);
    ~EventMouseButtonPressed() override = default;

    inline static EventType GetStaticType() { return EventType::MOUSE_BUTTON_PRESSED; }
    EventType               GetEventType() const override final;
    const Char*             GetName() const override final;
    std::string             GetString() const override;
  };


  class OWL_API EventMouseButtonReleased : public EventMouseButton
  {
  public:
    EventMouseButtonReleased(Int32 button_code);
    ~EventMouseButtonReleased() override = default;

    inline static EventType GetStaticType() { return EventType::MOUSE_BUTTON_RELEASED; }
    EventType               GetEventType() const override final;
    const Char*             GetName() const override final;
    std::string             GetString() const override;
  };
}
