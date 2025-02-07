#include "Gerenciadores/GerenciadorColisoes.h"

#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>

#include "Entidades/Entidade.h"
#include "Entidades/Obstaculos/Obstaculo.h"
#include "Entidades/Personagens/Inimigo.h"
#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Projetil.h"
#include "IDs.h"

using namespace Entidades;

namespace Gerenciadores {

// ============================================================================
// Construtora, Destrutora e Singleton
// ============================================================================

GerenciadorColisoes *GerenciadorColisoes::instancia = nullptr;

GerenciadorColisoes::GerenciadorColisoes()
    : jogadores(), inimigos(), obstaculos(), projeteis() {
  limparEntidades();
}

GerenciadorColisoes::~GerenciadorColisoes() { limparEntidades(); }

GerenciadorColisoes *GerenciadorColisoes::getInstancia() {
  if (!instancia) {
    instancia = new GerenciadorColisoes();
  }
  return instancia;
}

// ============================================================================
// Funcoes auxiliares
// ============================================================================

float GerenciadorColisoes::calcOverlapVert(
    const Entidades::Entidade *e1, const Entidades::Entidade *e2) const {
  if (e1 && e2) {
    float distY = std::abs((e1->getPos().y + e1->getTamanho().y / 2.f) -
                           (e2->getPos().y + e2->getTamanho().y / 2.f));
    float distColisaoY =
        (e1->getTamanho().y / 2.f) + (e2->getTamanho().y / 2.f);

    if (distColisaoY - distY > 0)
      return distColisaoY - distY;
    return 0;

  } else {
    std::cerr << "erro: GerenciadorColisoes::calcOverlapVert(...)\n";
    exit(EXIT_FAILURE);
  }
}

float GerenciadorColisoes::calcOverlapHor(const Entidades::Entidade *e1,
                                          const Entidades::Entidade *e2) const {
  if (e1 && e2) {
    float distX = std::abs((e1->getPos().x + e1->getTamanho().x / 2.f) -
                           (e2->getPos().x + e2->getTamanho().x / 2.f));
    float distColisaoX =
        (e1->getTamanho().x / 2.f) + (e2->getTamanho().x / 2.f);

    if (distColisaoX - distX > 0)
      return distColisaoX - distX;
    return 0;

  } else {
    std::cerr << "erro: GerenciadorColisoes::calcOverlapHor(...)\n";
    exit(EXIT_FAILURE);
  }
}

sf::Vector2f
GerenciadorColisoes::calcOverlap(const Entidades::Entidade *e1,
                                 const Entidades::Entidade *e2) const {
  return sf::Vector2f(calcOverlapHor(e1, e2), calcOverlapVert(e1, e2));
}

bool GerenciadorColisoes::colidiuVertical(const Entidades::Entidade *e1,
                                          const Entidades::Entidade *e2) const {
  return calcOverlapVert(e1, e2) != 0;
}

bool GerenciadorColisoes::colidiuHorizontal(
    const Entidades::Entidade *e1, const Entidades::Entidade *e2) const {
  return calcOverlapHor(e1, e2) != 0;
}

bool GerenciadorColisoes::colidiu(const Entidade *e1,
                                  const Entidade *e2) const {
  if (e1 && e2)
    return (colidiuHorizontal(e1, e2) && colidiuVertical(e1, e2));
  else {
    std::cerr << "erro: GerenciadorColisoes::colidiu(...)\n";
    exit(EXIT_FAILURE);
  }
}

// ============================================================================
// Funcao do padrao de projeto Mediator
// ============================================================================

void GerenciadorColisoes::notificar(Entidade *sender) {
  if (sender == nullptr) {
    std::cerr << "erro: GerenciadorColisoes::notificar(...)\n";
    exit(EXIT_FAILURE);
  }

  ID id = sender->getId();

  if (ehProjetil(id))
    verificarProj(sender);

  else if (ehInimigo(id))
    verificarInim(sender);

  else if (ehJogador(id))
    verificarJog(sender);
}

// ============================================================================
// Funcao para verificar se projetil colidiu com jogador, inimigo ou obstaculo
// ============================================================================

void GerenciadorColisoes::verificarProj(Entidades::Entidade *pEnt) {
  if (pEnt == nullptr) {
    std::clog << "erro: GerenciadorColisoes::verificarProj(...)\n";
    exit(EXIT_FAILURE);
  }

  std::set<Entidades::Personagens::Jogador *>::iterator jogIt;
  std::set<Entidades::Personagens::Inimigos::Inimigo *>::iterator inimIt;
  std::list<Entidades::Obstaculos::Obstaculo *>::iterator obstIt;

  // Detectar colisao projetil-jogador
  for (jogIt = jogadores.begin(); jogIt != jogadores.end(); jogIt++) {
    if (*jogIt) {
      if (colidiu(pEnt, *jogIt)) {
        (*jogIt)->colidir(pEnt);
        pEnt->colidir();
      }
    } else {
      std::clog << "erro: GerenciadorColisoes::verificarProj(...)\n";
      exit(EXIT_FAILURE);
    }
  }

  // Detectar colisao projetil-inimigo
  for (inimIt = inimigos.begin(); inimIt != inimigos.end(); inimIt++) {
    if (*inimIt) {
      if (colidiu(pEnt, *inimIt)) {
        (*inimIt)->colidir(pEnt);
        pEnt->colidir();
      }
    } else {
      std::clog << "erro: GerenciadorColisoes::verificarProj(...)\n";
      exit(EXIT_FAILURE);
    }
  }

  // Detectar colisao projetil-obstaculo
  for (obstIt = obstaculos.begin(); obstIt != obstaculos.end(); obstIt++) {
    if (*obstIt) {
      if (colidiu(pEnt, *obstIt)) {
        pEnt->colidir();
      }
    } else {
      std::clog << "erro: GerenciadorColisoes::verificarProj(...)\n";
      exit(EXIT_FAILURE);
    }
  }
}

// ============================================================================
// Funcao para verificar se inimigo colidiu com jogador ou obstaculo
// ============================================================================

void GerenciadorColisoes::verificarInim(Entidades::Entidade *pEnt) {
  if (pEnt == nullptr) {
    std::cerr << "erro: GerenciadorColisoes::verificarInim(...) => inimigo == "
                 "nullptr\n";
    exit(EXIT_FAILURE);
  }

  std::set<Entidades::Personagens::Jogador *>::iterator jogIt;
  std::list<Entidades::Obstaculos::Obstaculo *>::iterator obstIt;

  // Detectar colisao inimigo-jogador
  for (jogIt = jogadores.begin(); jogIt != jogadores.end(); jogIt++) {
    if (*jogIt) {
      if (colidiu(pEnt, *jogIt)) {
        (pEnt)->colidir(*jogIt);
      }
    } else {
      std::cerr << "erro: GerenciadorColisoes::verificarInim(...) jogador == "
                   "nullptr\n";
      exit(EXIT_FAILURE);
    }
  }

  // Detectar colisao inimigo-obstaculo
  for (obstIt = obstaculos.begin(); obstIt != obstaculos.end(); obstIt++) {
    if (*obstIt) {
      if (colidiu(pEnt, *obstIt)) {
        pEnt->colidir(*obstIt);
      }
    } else {
      std::cerr << "erro: GerenciadorColisoes::verificarInim(...) obstaculo == "
                   "nullptr\n";
      exit(EXIT_FAILURE);
    }
  }
}

// ============================================================================
// Funcao para verificar se jogador colidiu com algum obstaculo
// ============================================================================

void GerenciadorColisoes::verificarJog(Entidades::Entidade *pEnt) {
  if (pEnt == nullptr) {
    std::clog << "erro: GerenciadorColisoes::verificarJog(...)\n";
    exit(EXIT_FAILURE);
  }

  std::list<Entidades::Obstaculos::Obstaculo *>::iterator obstIt;

  for (obstIt = obstaculos.begin(); obstIt != obstaculos.end(); obstIt++) {
    if (*obstIt) {
      if (colidiu(pEnt, *obstIt)) {
        // Jogador colide com obstaculo
        pEnt->colidir(*obstIt);
      }
    } else {
      std::clog << "erro: GerenciadorColisoes::verificarJog(...)\n";
      exit(EXIT_FAILURE);
    }
  }
}

// ============================================================================
// Funcoes para gerenciar os conjuntos de entidades
// ============================================================================

void GerenciadorColisoes::incluirJog(Personagens::Jogador *pJog) {
  std::clog << "Incluindo jogador no gerenciador de colisoes" << std::endl;
  if (pJog)
    jogadores.insert(pJog);
}

void GerenciadorColisoes::incluirInim(Personagens::Inimigos::Inimigo *pInim) {
  std::clog << "Incluindo inimigo no gerenciador de colisoes" << std::endl;
  if (pInim)
    inimigos.insert(pInim);
}

void GerenciadorColisoes::incluirObst(Obstaculos::Obstaculo *pObst) {
  std::clog << "Incluindo obstaculo no gerenciador de colisoes" << std::endl;
  if (pObst)
    obstaculos.push_back(pObst);
}

void GerenciadorColisoes::incluirProj(Projetil *pProj) {
  std::clog << "Incluindo projetil no gerenciador de colisoes" << std::endl;
  if (pProj)
    projeteis.insert(pProj);
}

void GerenciadorColisoes::limparEntidades() {
  jogadores.clear();
  inimigos.clear();
  obstaculos.clear();
  projeteis.clear();
}

void GerenciadorColisoes::removerEnt(Entidade *pEnt) {
  ID id = pEnt->getId();

  if (ehInimigo(id)) {
    Personagens::Inimigos::Inimigo *aux =
        dynamic_cast<Personagens::Inimigos::Inimigo *>(pEnt);

    inimigos.erase(aux);

  } else if (ehJogador(id)) {
    Personagens::Jogador *aux = dynamic_cast<Personagens::Jogador *>(pEnt);
    jogadores.erase(aux);
  }

  else if (ehProjetil(id)) {
    Projetil *aux = dynamic_cast<Projetil *>(pEnt);
    projeteis.erase(aux);
  }
}

} // namespace Gerenciadores
