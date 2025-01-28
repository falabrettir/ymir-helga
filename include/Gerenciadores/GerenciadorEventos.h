#pragma once

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Window.hpp>

#include "Gerenciadores/GerenciadorGrafico.h"
#include "Gerenciadores/GerenciadorInput.h"

namespace Entidades::Personagens {
class Jogador;

}  // namespace Entidades::Personagens

namespace Gerenciadores {

class Gerenciador_Eventos {
 private:
  static Gerenciador_Eventos *instancia;

  sf::Window *pJanela;
  GerenciadorGrafico *pGG;
  Gerenciador_Input *pGI;

 private:
  Gerenciador_Eventos();
  ~Gerenciador_Eventos();
  Gerenciador_Eventos(const Gerenciador_Eventos &) = delete;
  Gerenciador_Eventos &operator=(const Gerenciador_Eventos &) = delete;

 public:
  static Gerenciador_Eventos *getInstancia();

  void setGG(GerenciadorGrafico *pGG);
  void setGI(Gerenciador_Input *pGI);
  void processaEventos();
};

}  // namespace Gerenciadores
