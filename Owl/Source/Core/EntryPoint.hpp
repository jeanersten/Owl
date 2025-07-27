#pragma once

#ifdef OWL_PLATFORM_WIN32

  #define OWL_CALL_MAIN(RETURN_VAL) extern Owl::Application* Owl::CreateApplication();  \
                                    extern void Owl::Setup();                           \
                                                                                        \
                                    int main(int argc, const char* argv[])              \
                                    {                                                   \
                                      Owl::Setup();                                     \
                                                                                        \
                                      auto app = Owl::CreateApplication();              \
                                      app->Run();                                       \
                                      delete app;                                       \
                                                                                        \
                                      return RETURN_VAL;                                \
                                    }

#endif
