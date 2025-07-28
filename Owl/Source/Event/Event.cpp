#include "../Core/CorePCH.hpp" // IWYU pragma: keep
#include "Event.hpp"

Owl::Event::Event()
  : m_handled(false)
{}

Owl::EventDispatcher::EventDispatcher(Event& event)
  : m_event(event)
{}
