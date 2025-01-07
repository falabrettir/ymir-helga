#include "Jogo.h"
#include "Entidades/Personagens/Jogador.h"
#include "Gerenciadores/GerenciadorEventos.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include "Gerenciadores/GerenciadorInput.h"
#include <SFML/System/Vector2.hpp>

Jogo::Jogo() {
  pGG = Gerenciadores::Gerenciador_Grafico::getInstancia();

  Ente::setGerenciadorGrafico(pGG);

  pJog1 = new Entidades::Personagens::Jogador();
}

Jogo::~Jogo() {}

void Jogo::executar() {}
