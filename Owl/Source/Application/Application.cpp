#include "../Log/Log.hpp"
#include "../Event/EventApplication.hpp"
#include "../Event/EventKeyboard.hpp"
#include "../Event/EventMouse.hpp"
#include "../Event/EventWindow.hpp"
#include "Application.hpp"

void Owl::Application::Run()
{
  EventApplicationTick eat { };
  OWL_LOG_ENGINE_DEBUG(eat.GetString());

  EventApplicationUpdate eau { };
  OWL_LOG_ENGINE_DEBUG(eau.GetString());

  EventApplicationRender ear { };
  OWL_LOG_ENGINE_DEBUG(ear.GetString());


  EventKeyboardKeyPressed ekkp { 10, 1 };
  OWL_LOG_ENGINE_DEBUG(ekkp.GetString());

  EventKeyboardKeyReleased ekkr { 10 };
  OWL_LOG_ENGINE_DEBUG(ekkr.GetString());


  EventMouseMoved emm { 10, 20 };
  OWL_LOG_ENGINE_DEBUG(emm.GetString());

  EventMouseScrolled ems { 5, 15 };
  OWL_LOG_ENGINE_DEBUG(ems.GetString());
  
  EventMouseButtonPressed embp { 10 };
  OWL_LOG_ENGINE_DEBUG(embp.GetString());

  EventMouseButtonReleased embr { 10 };
  OWL_LOG_ENGINE_DEBUG(embr.GetString());


  EventWindowMoved ewm { 100, 110 };
  OWL_LOG_ENGINE_DEBUG(ewm.GetString());

  EventWindowResized ewr { 640, 480 };
  OWL_LOG_ENGINE_DEBUG(ewr.GetString());

  EventWindowGainedFocus ewgf { };
  OWL_LOG_ENGINE_DEBUG(ewgf.GetString());

  EventWindowLostFocus ewlf { };
  OWL_LOG_ENGINE_DEBUG(ewlf.GetString());

  EventWindowClosed ewc { };
  OWL_LOG_ENGINE_DEBUG(ewc.GetString());
}
