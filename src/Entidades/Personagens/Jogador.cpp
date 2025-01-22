#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Personagens/Personagem.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

using namespace Entidades::Personagens;

Jogador::Jogador(const bool ehPrimeiroJogador)
    : Personagem(), pContr(nullptr), podePular(true),
      ehPrimeiroJogador(ehPrimeiroJogador) {

  pContr = new Controladores::Controlador_Jogador();
  pContr->setJog(this);
  if (ehPrimeiroJogador)
    setTexture("/assets/Characters(100x100)/Archer/Archer/Archer-Idle.png");
  else
    setTexture("/assets/Characters(100x100)/Archer/Archer/Player2.png");
  sf::Vector2f posInicial(400, 400);
  setPos(posInicial);
  pSprite->setPosition(posInicial);
  sf::FloatRect hitbox({0, 0, 18.f, 17.f});
  pSprite->setTextureRect({40, 40, 27, 20});
  setHitbox(hitbox);

  sf::Vector2f velInicial(0.f, 0.f);
  setVel(velInicial);
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
  if (podePular) {
    setVelY(-2 * VEL);
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
void Jogador::atacar() { std::cout << "ataquei" << '\n'; }
