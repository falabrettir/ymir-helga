#pragma once

#include "Gerenciadores/GerenciadorGrafico.h"
#include "Gerenciadores/GerenciadorInput.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Window.hpp>

namespace Entidades::Personagens {
class Jogador;

} // namespace Personagens

namespace Gerenciadores {

class Gerenciador_Eventos {
private:
  static Gerenciador_Eventos *instancia;

  sf::Window *pJanela;
  Gerenciador_Grafico *pGG;
  Gerenciador_Input *pGI;

private:
  Gerenciador_Eventos();
  ~Gerenciador_Eventos();
  Gerenciador_Eventos(const Gerenciador_Eventos &) = delete;
  Gerenciador_Eventos &operator=(const Gerenciador_Eventos &) = delete;

public:
  static Gerenciador_Eventos *getInstancia();

  void setGG(Gerenciador_Grafico *pGG);
  void setGI(Gerenciador_Input *pGI);
  void processaEventos();
};

} // namespace Gerenciadores
