cmake_minimum_required (VERSION 3.20...3.30)

project (Owl)

add_subdirectory ("Vendor/glfw-03.04.00")
add_subdirectory ("Vendor/spdlog-01.15.03")

add_library (Owl SHARED
  "Include/Owl/Engine.hpp"

  "Source/Application/Application.cpp"
  "Source/Application/Application.hpp"
  
  "Source/Core/Core.hpp"
  "Source/Core/CorePCH.hpp"
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

  "Source/Window/Win32/Win32Window.cpp"
  "Source/Window/Win32/Win32Window.hpp"
  "Source/Window/Window.cpp"
  "Source/Window/Window.hpp"
)

target_link_libraries (Owl PUBLIC glfw spdlog::spdlog)

if (WIN32)
  target_compile_definitions (Owl PUBLIC OWL_PLATFORM_WIN32)
  target_link_libraries (Owl PUBLIC opengl32)
endif ()
target_compile_definitions (Owl PUBLIC $<$<CONFIG:Debug>:OWL_CONFIG_DEBUG>)
target_compile_definitions (Owl PUBLIC $<$<CONFIG:Release>:OWL_CONFIG_RELEASE>)
target_compile_definitions (Owl PRIVATE OWL_BUILD_LIBRARY)
target_include_directories (Owl PUBLIC "Include")

target_precompile_headers (Owl PRIVATE "Source/Core/CorePCH.hpp")

set_target_properties (Owl
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out/$<CONFIG>/Owl/lib"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out/$<CONFIG>/Owl/bin"
)
