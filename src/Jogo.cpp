#include "Jogo.h"

#include <SFML/System/Vector2.hpp>

#include "Gerenciadores/GerenciadorEventos.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include "Gerenciadores/GerenciadorInput.h"
#include <iostream>

Jogo::Jogo() {
  // TODO: Encapsular inicializacao dos gerenciadores em uma funcao
  std::cerr << "Hello World!\n";
  printf("Hello World!\n");
  pGG = Gerenciadores::Gerenciador_Grafico::getInstancia();
  pGE = Gerenciadores::Gerenciador_Eventos::getInstancia();
  pGI = Gerenciadores::Gerenciador_Input::getInstancia();
  Ente::setGerenciadorGrafico(pGG);
  pGE->setGG(pGG);
  pGE->setGI(pGI);
}

Jogo::~Jogo() {}

void Jogo::atualizar() {
  pGE->processaEventos();

  pGG->atualizaDeltaTempo();

  caverna.executar();

  // Sempre deixar display antes de clear
  pGG->display();
  pGG->clear();
}

void Jogo::executar() {
  while (pGG->janelaAberta())
    atualizar();
}
