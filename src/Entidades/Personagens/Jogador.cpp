#include "Entidades/Personagens/Jogador.h"

#include <Fases/Fase.h>

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
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
    : Personagem(ID::IDjogador), pContr(nullptr), podePular(true),
      pProj(nullptr) {
  std::clog << "Criando novo jogador\n";

  pContr = new Controladores::Controlador_Jogador();
  pContr->setJog(this);

  pGI->inscrever(pContr);
  pGC->incluirJog(this);

  if (ehPrimeiroJogador) {
    setTextura("/assets/Personagens/Ymir.png");
    this->ehPrimeiroJogador = false;
  } else
    setTextura("/assets/Personagens/Helga.png");

  pSprite->setTextureRect({16, 16, 16, 16});
  tamanho = {48, 48};

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
  atualizarKnockback();
  setDanificando(false);
  pContr->controlarJogador();

  setNoChao(false);

  if (!getNoChao())
    cair();

  mover();

  pGC->notificar(this);

  sf::RectangleShape debugShape(tamanho);
  debugShape.setPosition(pSprite->getPosition());
  debugShape.setFillColor(sf::Color::Transparent);
  debugShape.setOutlineColor(sf::Color::Red);
  debugShape.setOutlineThickness(1);
  pGG->getJanela()->draw(debugShape);
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

void Jogador::colidir(Entidade *pEnt) {
  if (ehPlataforma(pEnt->getId())) {
    sf::Vector2f novaPos = this->getPos();
    sf::Vector2f ds = pGC->calcOverlap(this, pEnt);
    if (ds.x < ds.y) {                         // Eixo da colisão
      if (this->getPos().x < pEnt->getPos().x) // Direção da colisao
        novaPos.x -= ds.x;                     // Colisão Esquerda => Direita
      else
        novaPos.x += ds.x; // Colisao Direita => Esquerda
      this->setVelX(0.f);
    }
    if (ds.y < ds.x) {                           // Eixo da colisão
      if (this->getPos().y < pEnt->getPos().y) { // Direção da colisão
        novaPos.y -= ds.y;                       // Caindo
        this->setNoChao(true);
      } else
        novaPos.y += ds.y;
      this->setVelY(0.f);
    }
    this->setPos(novaPos);
  }
}
