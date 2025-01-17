#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Personagens/Personagem.h"
#include <SFML/System/Vector2.hpp>

using namespace Entidades::Personagens;

Jogador::Jogador()
    : Personagem(), pContr(nullptr), podePular(true), ehPrimeiroJogador(true) {

  pContr = new Controladores::Controlador_Jogador();
}

Jogador::~Jogador() {}

void Jogador::setPrimeiroJog(bool ehPrimeiroJogador) {
  this->ehPrimeiroJogador = ehPrimeiroJogador;
}

bool Jogador::getPrimeiroJog() const { return ehPrimeiroJogador; }

void Jogador::andarDireita() { setVelX(VEL); }

void Jogador::andarEsquerda() { setVelX(-VEL); }

void Jogador::naoAndar() { setVelX(0); }

void Jogador::pular() {
  if (getNoChao()) {
    setVelY(-5 * VEL);
    setNoChao(false);
  }
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

  if (!getNoChao())
    cair();

  mover();
}
