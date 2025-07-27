#include "../Core/Types.hpp"
#include "Event.hpp"

namespace Owl
{
  class OWL_API EventWindowMoved : public Event
  {
  public:
    EventWindowMoved(Float32 x, Float32 y);
    ~EventWindowMoved() override = default;

    inline Float32          GetX() const { return m_x; }
    inline Float32          GetY() const { return m_y; }
    inline static EventType GetStaticType() { return EventType::WINDOW_MOVED; }
    EventType               GetEventType() const override final;
    EventCategory           GetCategoryFlags() const override final;
    const Char*             GetName() const override final;
    std::string             GetString() const override;

  private:
    Float32 m_x;
    Float32 m_y;
  };


  class OWL_API EventWindowResized : public Event
  {
  public:
    EventWindowResized(Uint32 width, Uint32 heigth);
    ~EventWindowResized() = default;

    inline Uint32           GetWidth() const { return m_width; }
    inline Uint32           GetHeight() const { return m_height; }
    inline static EventType GetStaticType() { return EventType::WINDOW_RESIZED; }
    EventType               GetEventType() const override final;
    EventCategory           GetCategoryFlags() const override final;
    const Char*             GetName() const override final;
    std::string             GetString() const override;

  private:
    Uint32 m_width;
    Uint32 m_height;
  };


  class OWL_API EventWindowGainedFocus : public Event
  {
  public:
    EventWindowGainedFocus();
    ~EventWindowGainedFocus() override = default;

    inline static EventType GetStaticType() { return EventType::WINDOW_GAINED_FOCUS; }
    EventType               GetEventType() const override final;
    EventCategory           GetCategoryFlags() const override final;
    const Char*             GetName() const override final;
    std::string             GetString() const override;
  };


  class OWL_API EventWindowLostFocus : public Event
  {
  public:
    EventWindowLostFocus();
    ~EventWindowLostFocus() override = default;

    inline static EventType GetStaticType() { return EventType::WINDOW_LOST_FOCUS; }
    EventType               GetEventType() const override final;
    EventCategory           GetCategoryFlags() const override final;
    const Char*             GetName() const override final;
    std::string             GetString() const override;
  };


  class OWL_API EventWindowClosed : public Event
  {
  public:
    EventWindowClosed();
    ~EventWindowClosed() override = default;

    inline static EventType GetStaticType() { return EventType::APPLICATION_TICK; }
    EventType               GetEventType() const override final;
    EventCategory           GetCategoryFlags() const override final;
    const Char*             GetName() const override final;
    std::string             GetString() const override;
  };
}
