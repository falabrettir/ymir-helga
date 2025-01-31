#include "Entidades/Personagens/Jogador.h"

#include <iostream>

#include "Fabrica/FabricaFlechas.h"
#include "Gerenciadores/GerenciadorColisoes.h"

using namespace Entidades::Personagens;

// Flag inicialmente definida como true
bool Jogador::ehPrimeiroJogador = true;

Gerenciadores::GerenciadorInput *Jogador::pGI =
    Gerenciadores::GerenciadorInput::getInstancia();

Fabricas::FabricaProjeteis *Jogador::fabProj =
    Fabricas::FabricaFlechas::getInstancia();

Jogador::Jogador(const sf::Vector2f &pos)
    : Personagem(ID::IDjogador), pContr(nullptr), podePular(true) {
  std::clog << "Criando novo jogador\n";

  pContr = new Controladores::Controlador_Jogador();
  pContr->setJog(this);

  pGI->inscrever(pContr);

  if (ehPrimeiroJogador) {
    setTextura("/assets/Personagens/Ymir.png");
    this->ehPrimeiroJogador = false;
  } else
    setTextura("/assets/Personagens/Helga.png");

  setPos(pos);
  pSprite->setPosition(pos);

  // TODO: Mudar a hitbox para a classe entidade
  sf::FloatRect hitbox({16, 16, 16.f, 16.f});
  setHitbox(hitbox);
}

Jogador::~Jogador() {}

bool Jogador::getPrimeiroJog() const { return ehPrimeiroJogador; }

// TODO: Recozer movimentos, o jogador ta meio devagaroso lesmo
void Jogador::andarDireita() {
  if (getVel().x < MAXVEL) {
    sf::Vector2f vel = getVel();
    vel.x += ACEL;
    setVel(vel);
  } else {
    setVelX(MAXVEL);
  }
}

void Jogador::andarEsquerda() {
  if (getVel().x > -MAXVEL) {
    sf::Vector2f vel = getVel();
    vel.x -= ACEL;
    setVel(vel);
  } else {
    setVelX(-MAXVEL);
  }
}

void Jogador::naoAndar() { setVelX(0); }

void Jogador::pular() {
  if (getNoChao()) {
    setVelY(-2 * MAXVEL);
    setNoChao(false);
  }
}

void Jogador::aplicaLentidao(float viscosidade) {
  sf::Vector2f vel = getVel();
  vel *= viscosidade;
  setVel(vel);
}

void Jogador::executar() {
  pContr->controlarJogador();

  // FIX: Arrumar
  if (!getNoChao()) cair();

  pGC->notificaColisao(this);

  mover();
}

void Jogador::atacar() {
  if (fabProj) {
    std::clog << "Atacando\n";
  } else
    exit(EXIT_FAILURE);
}

void Jogador::colidir(Entidade *pEnt, sf::Vector2f ds) {
  if (ds.x < 0 && ds.y < 0) {
    if (pEnt->getId() == ID::IDesqueleto || pEnt->getId() == ID::IDmago ||
        pEnt->getId() == ID::IDslime) {
      this->tomarDano(dynamic_cast<Personagem *>(pEnt)->getDano());
    }
  }
}
