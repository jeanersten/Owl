cmake_minimum_required (VERSION 3.20...3.30)

project (Owl)

add_executable (Sandbox
  "source/Sandbox.cpp"
)

target_link_libraries (Sandbox PRIVATE Owl)

set_target_properties (Sandbox
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out/$<CONFIG>/Sandbox/lib"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out/$<CONFIG>/Sandbox/bin"
)

if (WIN32)
  add_custom_command (
    TARGET Sandbox POST_BUILD
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different $<TARGET_FILE:Owl> $<TARGET_FILE_DIR:Sandbox>
  )
endif ()
