#include "../Core/CorePCH.hpp" // IWYU pragma: keep
#include "../Log/Log.hpp"
#include "Init.hpp"

void Owl::Setup()
{
  Log::Setup(OWL_LOG_LEVEL_TRACE);
}
