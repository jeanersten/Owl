cmake_minimum_required (VERSION 3.10...3.15)

project (Owl)

add_library (Owl SHARED
  "Include/Owl/Engine.hpp"

  "Source/Application/Application.cpp"
  "Source/Application/Application.hpp"
  
  "Source/Core/Core.hpp"
  "Source/Core/EntryPoint.hpp"
)

if (WIN32)
  target_compile_definitions (Owl PUBLIC OWL_PLATFORM_WIN32)
endif ()
target_compile_definitions (Owl PRIVATE $<$<CONFIG:Debug>:OWL_CONFIG_DEBUG>)
target_compile_definitions (Owl PRIVATE $<$<CONFIG:Release>:OWL_CONFIG_RELEASE>)
target_compile_definitions (Owl PRIVATE OWL_BUILD_LIBRARY)
target_include_directories (Owl PUBLIC "Include")

set_target_properties (Owl
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out/$<CONFIG>/Owl/lib"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out/$<CONFIG>/Owl/bin"
)
