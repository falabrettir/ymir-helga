#include "jogo.h"
#include "gerenciadores/gerenciador-eventos.h"
#include "gerenciadores/gerenciador-grafico.h"
#include <SFML/Graphics/Color.hpp>

Jogo::Jogo()
    : pGG(new Gerenciadores::Gerenciador_Grafico()),
      pGE(new Gerenciadores::Gerenciador_Eventos()) {}

Jogo::~Jogo() {}

void Jogo::executar() {

  while (pGG->janelaAberta()) {
    while (pGG->pollEvent(pGE->))
      pGG->clear();
    pGG->display();
  }
}
