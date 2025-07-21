#pragma once

#ifdef OWL_PLATFORM_WIN32

  #define OWL_CALL_MAIN(RETURN_VAL)                   \
                                                      \
  extern Owl::Application* Owl::CreateApplication();  \
                                                      \
  int main(int argc, const char* argv[])              \
  {                                                   \
    auto app = Owl::CreateApplication();              \
    app->Run();                                       \
    delete app;                                       \
                                                      \
    return RETURN_VAL;                                \
  }                                                   \

#endif
