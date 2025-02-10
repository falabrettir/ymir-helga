#include "Entidades/Personagens/Jogador.h"

#include <Fases/Fase.h>

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>

#include "Entidades/Personagens/Personagem.h"
#include "Entidades/Projetil.h"
#include "Fabrica/FabricaProjeteis.h"
#include "Gerenciadores/GerenciadorColisoes.h"
#include "IDs.h"

using namespace Entidades::Personagens;

// Flag inicialmente definida como true
bool Jogador::ehPrimeiroJogador = true;

Gerenciadores::GerenciadorInput* Jogador::pGI = Gerenciadores::GerenciadorInput::getInstancia();

Fabricas::FabricaProjeteis* Jogador::fabProj = Fabricas::FabricaProjeteis::getInstancia();

Jogador::Jogador(const sf::Vector2f& pos) : Personagem(ID::IDjogador), pContr(nullptr) {
  pContr = new Controladores::Controlador_Jogador();
  pContr->setJog(this);

  pGI->inscrever(pContr);
  pGC->incluirJog(this);

  if (ehPrimeiroJogador) {
    setTextura("/assets/Personagens/Ymir.png");
    this->ehPrimeiroJogador = false;
  } else
    setTextura("/assets/Personagens/Helga.png");

  setPos(pos);
}

Jogador::~Jogador() {
  std::clog << "Deletando jog" << std::endl;
  delete pContr;
  pContr = nullptr;
}

const bool Jogador::getPrimeiroJog() const { return ehPrimeiroJogador; }

void Jogador::resetJog() { ehPrimeiroJogador = true; }

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
  if (vivo && pGC) {
    atualizarKnockback();
    setDanificando(false);
    pContr->controlarJogador();

    setNoChao(false);

    mover();

    pGC->notificar(this);
  }
  Personagem::executar();
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

  if (podeAtacar) {
    podeAtacar = false;
    pFase->adicionarProjetil(fabProj->criarProjetil(this));
  }
}

void Jogador::colidir(Entidade* pEnt) {
  if (ehProjetil(pEnt->getId())) {
    if (ehInimigo(dynamic_cast<Entidades::Projetil*>(pEnt)->getDono()->getId())) {
      tomarDano(dynamic_cast<Entidades::Projetil*>(pEnt)->getDano(), pEnt->getOlhandoEsquerda());
    }
  }
}
