#include "Entidades/Personagens/Jogador.h"

#include <Fases/Fase.h>

#include <iostream>

#include "Fabrica/FabricaProjeteis.h"
#include "Gerenciadores/GerenciadorColisoes.h"

using namespace Entidades::Personagens;

// Flag inicialmente definida como true
bool Jogador::ehPrimeiroJogador = true;

Gerenciadores::GerenciadorInput *Jogador::pGI =
    Gerenciadores::GerenciadorInput::getInstancia();

Fabricas::FabricaProjeteis *Jogador::fabProj =
    Fabricas::FabricaProjeteis::getInstancia();

Jogador::Jogador(const sf::Vector2f &pos)
    : Personagem(ID::IDjogador),
      pContr(nullptr),
      podePular(true),
      pProj(nullptr) {
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
}

Jogador::~Jogador() {
  delete pProj;
  delete pContr;
}

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

  pGC->notificaColisao(this);

  if (!getNoChao()) cair();

  mover();
}

void Jogador::atacar() {
  if (!fabProj) {
    std::cerr << "erro: Jogador::atacar() => fabProj == nullptr\n";
    exit(EXIT_FAILURE);
  }
  if (!pFase) {
    std::cerr << "erro: Jogador::atacar() => pFase == nullptr\n";
    exit(EXIT_FAILURE);
  }

  if (!pProj) {
    pProj = fabProj->criarProjetil(this);
    pFase->adicionarProjetil(pProj);
  }
}

void Jogador::colidir(Entidade *pEnt, sf::Vector2f ds) {
  if (ds.x < 0 && ds.y < 0) {
    if (pEnt->getId() == ID::IDesqueleto || pEnt->getId() == ID::IDmago ||
        pEnt->getId() == ID::IDslime) {
      this->tomarDano(dynamic_cast<Personagem *>(pEnt)->getDano());
    }
  }
}
