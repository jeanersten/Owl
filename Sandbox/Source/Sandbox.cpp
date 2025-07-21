#include <Owl/Engine.hpp>

OWL_CALL_MAIN(0);

class Sandbox : public Owl::Application
{
public:
  Sandbox() = default;
  virtual ~Sandbox() override = default;
};

Owl::Application* Owl::CreateApplication()
{
  return new Sandbox();
}
