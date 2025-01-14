#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Personagens/Personagem.h"
#include <SFML/System/Vector2.hpp>

using namespace Entidades::Personagens;

Jogador::Jogador() : Personagem(), pContr(nullptr), podePular(true) {}

Jogador::~Jogador() {}

void Jogador::andarDireita() { setVelX(VEL); }

void Jogador::andarEsquerda() { setVelX(-VEL); }

void Jogador::naoAndar() { setVelX(0); }

void Jogador::pular() {
  if (podePular)
    setVelY(-VEL);
}

void Jogador::mover() {
  sf::Vector2f novaPos = getPos() + getVel() * pGG->getDeltaTempo();
  setPos(novaPos);
  pSprite->setPosition(novaPos);
}

Controladores::Controlador_Jogador *Jogador::getControlador() const {
  return pContr;
}

void Jogador::executar() {

  pContr->controlarJogador();

  cair();

  mover();
}
