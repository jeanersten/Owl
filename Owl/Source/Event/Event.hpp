#pragma once

#include "../Core/Core.hpp"
#include "../Core/Types.hpp"
#include <string>
#include <functional>

namespace Owl
{
  enum class EventType : Uint32
  {
    None = 0,
    ApplicationTick, ApplicationUpdate, ApplicationRender,
    KeyboardKeyPressed, KeyboardKeyReleased,
    MouseMoved, MouseScrolled, MouseButtonPressed, MouseButtonReleased,
    WindowMoved, WindowResized, WindowGainedFocus, WindowLostFocus, WindowClosed
  };


  enum class EventCategory : Uint32
  {
    None = 0,
    Application = OWL_BIT_FLAGS(0),
    Window      = OWL_BIT_FLAGS(1),
    Input       = OWL_BIT_FLAGS(2),
    Keyboard    = OWL_BIT_FLAGS(3),
    Mouse       = OWL_BIT_FLAGS(4),
  };

  inline EventCategory operator|(EventCategory lhs, EventCategory rhs) { return static_cast<EventCategory>(static_cast<Uint32>(lhs) | static_cast<Uint32>(rhs)); }
  inline EventCategory operator&(EventCategory lhs, EventCategory rhs) { return static_cast<EventCategory>(static_cast<Uint32>(lhs) & static_cast<Uint32>(rhs)); }


  class OWL_API Event
  {
    friend class EventDispatcher;

  public:
    virtual EventType     GetEventType() const = 0;
    virtual EventCategory GetCategoryFlags() const = 0;
    virtual const Char*   GetName() const = 0;
    virtual std::string   GetString() const = 0;
    inline Bool IsInCategory(EventCategory category) const { return static_cast<Bool>(GetCategoryFlags() & category); }

  protected:
    Event();
    virtual ~Event() = default;

    Bool m_handled;
  };


  class EventDispatcher
  {
    template<typename T>
    using EventFunc = std::function<Bool(T&)>;

  public:
    EventDispatcher(Event& event);
    ~EventDispatcher() = default;

    template<typename T>
    Bool Dispatch(EventFunc<T> func)
    {
      if (m_event.GetEventType() == T::GetStaticType())
      {
        m_event.m_handled = func(*(T*)&m_event);
        return true;
      }

      return false;
    }
    
  private:
    Event& m_event;
  };
}
