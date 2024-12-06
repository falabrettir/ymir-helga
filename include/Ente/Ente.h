#pragma once
#include "../gerenciadores/gerenciador-grafico.h"
#include <SFML/System/Vector2.hpp>

namespace Entes {
class Ente {
protected:
  int id;
  static Gerenciadores::Gerenciador_Grafico *pGG;
  static int cont;

public:
  Ente();
  ~Ente();
  void setGerenciadorGrafico(Gerenciadores::Gerenciador_Grafico *pGG);
  virtual void desenhar() = 0;
  virtual void executar() = 0;
};
} // namespace Entes
