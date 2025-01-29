#pragma once

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Window.hpp>

#include "Gerenciadores/GerenciadorGrafico.h"
#include "Gerenciadores/GerenciadorInput.h"

namespace Entidades::Personagens {
class Jogador;

}  // namespace Entidades::Personagens

namespace Gerenciadores {

class GerenciadorEventos {
 private:
  static GerenciadorEventos *instancia;

  sf::Window *pJanela;
  GerenciadorGrafico *pGG;
  GerenciadorInput *pGI;

 private:
  GerenciadorEventos();
  ~GerenciadorEventos();
  GerenciadorEventos(const GerenciadorEventos &) = delete;
  GerenciadorEventos &operator=(const GerenciadorEventos &) = delete;

 public:
  static GerenciadorEventos *getInstancia();

  void setGG(GerenciadorGrafico *pGG);
  void setGI(GerenciadorInput *pGI);
  void processaEventos();
};

}  // namespace Gerenciadores
