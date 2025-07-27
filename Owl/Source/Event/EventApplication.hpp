#pragma once

#include "../Core/Types.hpp"
#include "Event.hpp"
#include <string>

namespace Owl
{
  class OWL_API EventApplicationTick : public Event
  {
  public:
    EventApplicationTick();
    ~EventApplicationTick() override = default;

    inline static EventType GetStaticType() { return EventType::APPLICATION_TICK; }
    EventType               GetEventType() const override final;
    EventCategory           GetCategoryFlags() const override final;
    const Char*             GetName() const override final;
    std::string             GetString() const override;
  };


  class OWL_API EventApplicationUpdate : public Event
  {
  public:
    EventApplicationUpdate();
    ~EventApplicationUpdate() override = default;

    inline static EventType GetStaticType() { return EventType::APPLICATION_UPDATE; }
    EventType               GetEventType() const override final;
    EventCategory           GetCategoryFlags() const override final;
    const Char*             GetName() const override final;
    std::string             GetString() const override final;
  };


  class OWL_API EventApplicationRender : public Event
  {
  public:
    EventApplicationRender();
    ~EventApplicationRender() override = default;

    inline static EventType GetStaticType() { return EventType::APPLICATION_RENDER; }
    EventType               GetEventType() const override final;
    EventCategory           GetCategoryFlags() const override final;
    const Char*             GetName() const override final;
    std::string             GetString() const override final;
  };
}
