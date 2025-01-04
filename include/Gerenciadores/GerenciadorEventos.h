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

/*
 * Gerenciador Eventos nao precisa de ponteiro para sf::Window
 * apenas o Gerenciador de input.
 *
 * Passar um ponteiro para janela no metodo processaEventos
 */
class Gerenciador_Eventos {
private:
  bool janelaFechada;
  static Gerenciador_Eventos *instancia; // Singleton
  Gerenciador_Eventos();

public:
  ~Gerenciador_Eventos();
  static Gerenciador_Eventos *getInstancia();

  void processaEventos(Gerenciador_Grafico *pGG);
  bool getJanelaFechada();
};

} // namespace Gerenciadores
