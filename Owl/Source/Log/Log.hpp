#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <memory>

namespace Owl
{
  class Log
  {
  public:
    Log() = delete;
    ~Log() = delete;

    static void Setup(spdlog::level::level_enum log_level);
    static std::shared_ptr<spdlog::logger>& GetEngineLogger();
    static std::shared_ptr<spdlog::logger>& GetClientLogger();

  private:
    static std::shared_ptr<spdlog::sinks::stderr_color_sink_mt> s_stderr_console_sink;
    static std::shared_ptr<spdlog::logger> s_engine_logger;
    static std::shared_ptr<spdlog::logger> s_client_logger;
  };
}

#define OWL_LOG_LEVEL_TRACE    spdlog::level::trace
#define OWL_LOG_LEVEL_DEBUG    spdlog::level::debug
#define OWL_LOG_LEVEL_INFO     spdlog::level::info
#define OWL_LOG_LEVEL_WARN     spdlog::level::warn
#define OWL_LOG_LEVEL_ERROR    spdlog::level::err
#define OWL_LOG_LEVEL_CRITICAL spdlog::level::critical

#ifdef OWL_PLATFORM_WIN32

  #ifdef OWL_ENABLE_ASSERT

    #define OWL_ASSERT_ENGINE(RET_VAL, ...) { if(!(RET_VAL)) { OWL_LOG_ENGINE_ERROR("Assertion failed: {0} ({1}:{2})", __VA_ARGS__, __FILE__, __LINE__); __debugbreak(); } }
    #define OWL_ASSERT_CLIENT(RET_VAL, ...) { if(!(RET_VAL)) { OWL_LOG_CLIENT_ERROR("Assertion failed: {0} ({1}:{2})", __VA_ARGS__, __FILE__, __LINE__); __debugbreak(); } }

  #else

    #define OWL_ASSERT_ENGINE(RET_VAL, ...)
    #define OWL_ASSERT_CLIENT(RET_VAL, ...)

  #endif

  #define OWL_LOG_ENGINE_TRACE(...)    Owl::Log::GetEngineLogger()->trace(__VA_ARGS__)
  #define OWL_LOG_ENGINE_DEBUG(...)    Owl::Log::GetEngineLogger()->debug(__VA_ARGS__)
  #define OWL_LOG_ENGINE_INFO(...)     Owl::Log::GetEngineLogger()->info(__VA_ARGS__)
  #define OWL_LOG_ENGINE_WARN(...)     Owl::Log::GetEngineLogger()->warn(__VA_ARGS__)
  #define OWL_LOG_ENGINE_ERROR(...)    Owl::Log::GetEngineLogger()->error(__VA_ARGS__)
  #define OWL_LOG_ENGINE_CRITICAL(...) Owl::Log::GetEngineLogger()->critical(__VA_ARGS__)

  #define OWL_LOG_CLIENT_TRACE(...)    Owl::Log::GetClientLogger()->trace(__VA_ARGS__)
  #define OWL_LOG_CLIENT_DEBUG(...)    Owl::Log::GetClientLogger()->debug(__VA_ARGS__)
  #define OWL_LOG_CLIENT_INFO(...)     Owl::Log::GetClientLogger()->info(__VA_ARGS__)
  #define OWL_LOG_CLIENT_WARN(...)     Owl::Log::GetClientLogger()->warn(__VA_ARGS__)
  #define OWL_LOG_CLIENT_ERROR(...)    Owl::Log::GetClientLogger()->error(__VA_ARGS__)
  #define OWL_LOG_CLIENT_CRITICAL(...) Owl::Log::GetClientLogger()->critical(__VA_ARGS__)

#else

  #ifdef OWL_ENABLE_ASSERT

    #define OWL_ASSERT_ENGINE(RET_VAL, ...)
    #define OWL_ASSERT_CLIENT(RET_VAL, ...)

  #endif

  #define OWL_LOG_ENGINE_TRACE(...)
  #define OWL_LOG_ENGINE_DEBUG(...)
  #define OWL_LOG_ENGINE_INFO(...)
  #define OWL_LOG_ENGINE_WARN(...)
  #define OWL_LOG_ENGINE_ERROR(...)
  #define OWL_LOG_ENGINE_CRITICAL(...)

  #define OWL_LOG_CLIENT_TRACE(...)
  #define OWL_LOG_CLIENT_DEBUG(...)
  #define OWL_LOG_CLIENT_INFO(...)
  #define OWL_LOG_CLIENT_WARN(...)
  #define OWL_LOG_CLIENT_ERROR(...)
  #define OWL_LOG_CLIENT_CRITICAL(...)

#endif
