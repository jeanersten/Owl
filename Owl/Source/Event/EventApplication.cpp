#include "../Core/CorePCH.hpp"  // IWYU pragma: keep
#include "../Core/Types.hpp"
#include "EventApplication.hpp"

Owl::EventApplicationTick::EventApplicationTick()
  : Event()
{}

Owl::EventType Owl::EventApplicationTick::GetEventType() const
{
  return GetStaticType();
}

Owl::EventCategory Owl::EventApplicationTick::GetCategoryFlags() const
{
  return EventCategory::Application;
}

const Owl::Char* Owl::EventApplicationTick::GetName() const
{
  return "(EVENT)ApplicationTick";
}

std::string Owl::EventApplicationTick::GetString() const
{
  std::stringstream stream;
  stream << '[' << GetName() << ": " << "Default!]";
  return stream.str();
}



Owl::EventApplicationUpdate::EventApplicationUpdate()
  : Event()
{}

Owl::EventType Owl::EventApplicationUpdate::GetEventType() const
{
  return GetStaticType();
}

Owl::EventCategory Owl::EventApplicationUpdate::GetCategoryFlags() const
{
  return EventCategory::Application;
}

const Owl::Char* Owl::EventApplicationUpdate::GetName() const
{
  return "(EVENT)ApplicationUpdate";
}

std::string Owl::EventApplicationUpdate::GetString() const
{
  std::stringstream stream;
  stream << '[' << GetName() << ": " << "Default!]";
  return stream.str();
}



Owl::EventApplicationRender::EventApplicationRender()
  : Event()
{}

Owl::EventType Owl::EventApplicationRender::GetEventType() const
{
  return GetStaticType();
}

Owl::EventCategory Owl::EventApplicationRender::GetCategoryFlags() const
{
  return EventCategory::Application;
}

const Owl::Char* Owl::EventApplicationRender::GetName() const
{
  return "(EVENT)ApplicationRender";
}

std::string Owl::EventApplicationRender::GetString() const
{
  std::stringstream stream;
  stream << '[' << GetName() << ": " << "Default!]";
  return stream.str();
}
