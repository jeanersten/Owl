#include "../Log/Log.hpp"
#include "Init.hpp"

namespace Owl
{
  void Setup()
  {
    Log::Setup(OWL_LOG_LEVEL_TRACE);
  }
}
