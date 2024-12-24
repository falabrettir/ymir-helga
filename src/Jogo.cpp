#include "Jogo.h"
#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Personagens/Slime.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include <SFML/System/Vector2.hpp>

Jogo::Jogo() {
  pGG = Gerenciadores::Gerenciador_Grafico::getInstancia();

  pGE = Gerenciadores::Gerenciador_Eventos::getInstancia();
  Ente::setGerenciadorGrafico(pGG);
}

Jogo::~Jogo() {}

void Jogo::executar() {
  while (pGG->janelaAberta()) {
    pGG->clear();

    pGE->processaEventos(pGG);

    pGG->atualizaDeltaTempo();

    pGE->processaInput(pJog);

    pSl->desenhar();

    pJog->desenhar();

    pSl->persegue();

    pGG->display();
  }
}
