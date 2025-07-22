#include "../Log/Log.hpp"
#include "Application.hpp"

void Owl::Application::Run()
{
  OWL_LOG_ENGINE_INFO("Test!");
  OWL_LOG_CLIENT_INFO("Test!");
}
