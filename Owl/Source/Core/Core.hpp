#pragma once

#ifdef OWL_PLATFORM_WIN32

  #ifdef OWL_BUILD_LIBRARY

    #define OWL_API __declspec(dllexport)

  #else

    #define OWL_API __declspec(dllexport)

  #endif

#else

  #define OWL_API
  #error [OWL] : "Platform not supported!"

#endif

#define OWL_BIT_FLAGS(RIGHT_INDENT) ((Owl::Uint32)1 << RIGHT_INDENT)
