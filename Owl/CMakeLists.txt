cmake_minimum_required (VERSION 3.10...3.15)

project (Owl)

add_subdirectory ("Vendor/spdlog-01.15.03")

add_library (Owl SHARED
  "Include/Owl/Engine.hpp"

  "Source/Application/Application.cpp"
  "Source/Application/Application.hpp"
  
  "Source/Core/Core.hpp"
  "Source/Core/EntryPoint.hpp"
  "Source/Core/Init.cpp"
  "Source/Core/Init.hpp"
  "Source/Core/Types.hpp"

  "Source/Event/Event.cpp"
  "Source/Event/Event.hpp"
  "Source/Event/EventApplication.cpp"
  "Source/Event/EventApplication.hpp"
  "Source/Event/EventKeyboard.cpp"
  "Source/Event/EventKeyboard.hpp"
  "Source/Event/EventMouse.cpp"
  "Source/Event/EventMouse.hpp"
  "Source/Event/EventWindow.cpp"
  "Source/Event/EventWindow.hpp"

  "Source/Log/Log.cpp"
  "Source/Log/Log.hpp"
)

target_link_libraries (Owl PUBLIC spdlog::spdlog)

if (WIN32)
  target_compile_definitions (Owl PUBLIC OWL_PLATFORM_WIN32)
endif ()
target_compile_definitions (Owl PUBLIC $<$<CONFIG:Debug>:OWL_CONFIG_DEBUG>)
target_compile_definitions (Owl PUBLIC $<$<CONFIG:Release>:OWL_CONFIG_RELEASE>)
target_compile_definitions (Owl PRIVATE OWL_BUILD_LIBRARY)
target_include_directories (Owl PUBLIC "Include")

set_target_properties (Owl
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out/$<CONFIG>/Owl/lib"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out/$<CONFIG>/Owl/bin"
)
