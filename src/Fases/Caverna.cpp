#include "Fases/Caverna.h"

#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <iostream>
#include <limits>
#include "ObserverFase.h"

#include "Fabrica/FabricaEntidadesCaverna.h"

using namespace Entidades;

namespace Fases {

int Caverna::contSlimes(0);
int Caverna::contEsq(0);
int Caverna::contEsp(0);
int Caverna::contPlat(0);

Caverna::Caverna(bool mp)
    : Fase(ID::IDcaverna, mp), minEsq(3), minSlimes(3), minEsp(3), minPlat(3) {

  setTextura("/assets/Fundos/caverna.png");
  pSprite->setScale(1, 1);

  pFE = Fabricas::FabEntCaverna::getInstancia();
  dynamic_cast<Fabricas::FabEntCaverna*>(pFE)->setFase(this);

  criarMapa("/assets/Mapas/caverna.txt");
}

Caverna::~Caverna() {
  delete pFE;
  pFE = nullptr;
}

void Caverna::executar() {
  if (pGG == nullptr) {
    std::cerr << "erro: Caverna::executar() => pGG == nullptr" << std::endl;
    exit(EXIT_FAILURE);
  }

  // Desenha o fundo
  pGG->getJanela()->draw(getSprite());

  listaProjeteis.executar();
  listaInimigos.executar();
  listaJogadores.executar();
  listaObstaculos.executar();
  thisObs->executar();

  if (listaInimigos.getSize() == 0) {
    listaJogadores.limpar();
    Personagens::Inimigos::Inimigo::resetJogs();
    thisObs->notificarFim();
  }

  if (listaJogadores.getSize() == 0 && listaInimigos.getSize() > 0) {
    thisObs->notificarJogadorMorreu();
  }
}

const int Caverna::getMinEsq() const {
  return minEsq;
}

const int Caverna::getMinSli() const {
  return minSlimes;
}

const int Caverna::getMinEsp() const {
  return minEsp;
}

const int Caverna::getMinPlat() const {
  return minPlat;
}

const int Caverna::getCont(char tipoEnt) {
  switch (tipoEnt) {
    case 'E':
      return contEsq;
      break;
    case 'S':
      return contSlimes;
      break;
    case 'G':
      return contEsp;
      break;
    case 'M':
      return contPlat;
      break;
    default:
      return std::numeric_limits<int>::max();
      break;
  }
}

void Caverna::incrementaContadores(char tipoEnt) {
  switch (tipoEnt) {
    case 'E':
      contEsq++;
      break;
    case 'S':
      contSlimes++;
      break;
    case 'G':
      contEsp++;
      break;
    case 'M':
      contPlat++;
      break;
  }
}

};  // namespace Fases
