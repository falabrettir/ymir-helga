#pragma once

#include "Gerenciadores/GerenciadorGrafico.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Window.hpp>

namespace Entidades {
namespace Personagens {

class Jogador;

}
} // namespace Entidades

namespace Gerenciadores {

class Gerenciador_Eventos {
private:
  static Gerenciador_Grafico *pGG;
  static Gerenciador_Eventos *instancia;

private:
  Gerenciador_Eventos();
  ~Gerenciador_Eventos();
  Gerenciador_Eventos(const Gerenciador_Eventos &) = delete;
  Gerenciador_Eventos &operator=(const Gerenciador_Eventos &) = delete;

public:
  static Gerenciador_Eventos *getInstancia();
  static void setGG(Gerenciador_Grafico *ppGG);
  void processaEventos();
  void processaInput(Entidades::Personagens::Jogador *pJog);
};

} // namespace Gerenciadores
