#include "../Core/CorePCH.hpp"               // IWYU pragma: keep
#include "Log.hpp"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

std::shared_ptr<spdlog::sinks::stderr_color_sink_mt> Owl::Log::s_stderr_console_sink { nullptr };
std::shared_ptr<spdlog::logger> Owl::Log::s_engine_logger { nullptr };
std::shared_ptr<spdlog::logger> Owl::Log::s_client_logger { nullptr };

void Owl::Log::Setup(spdlog::level::level_enum log_level)
{
  s_stderr_console_sink = std::make_shared<spdlog::sinks::stderr_color_sink_mt>();
  s_stderr_console_sink->set_pattern("[%r]--[ <OWL-%n> ]--[ %^%L%$ ]: %v");
  s_stderr_console_sink->set_level(log_level);

  s_engine_logger = std::make_shared<spdlog::logger>("ENGINE", s_stderr_console_sink);
  s_engine_logger->set_level(spdlog::level::trace);

  s_client_logger = std::make_shared<spdlog::logger>("CLIENT", s_stderr_console_sink);
  s_client_logger->set_level(spdlog::level::trace);
}

std::shared_ptr<spdlog::logger>& Owl::Log::GetEngineLogger()
{
  return s_engine_logger;
}

std::shared_ptr<spdlog::logger>& Owl::Log::GetClientLogger()
{
  return s_client_logger;
}
