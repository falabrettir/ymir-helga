/*
 * Código adaptado do monitor Daniel Zagroba, disponível em:
 * https://github.com/danzagroba/ROBOT_plus_plus
 */
#include "Gerenciadores/GerenciadorColisoes.h"

#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <iostream>
#include <list>

#include "Entidades/Entidade.h"
#include "Entidades/Obstaculos/Obstaculo.h"
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
// Funcoes de deteccao de colisao e calculo de overlap
// ============================================================================

float GerenciadorColisoes::calcOverlapVert(
    const Entidades::Entidade *e1, const Entidades::Entidade *e2) const {
  if (e1 && e2) {
    float distY = (e1->getPos().y + e1->getTamanho().y / 2.f) -
                  (e2->getPos().y + e2->getTamanho().y / 2.f);
    float distColisaoY =
        (e1->getTamanho().y / 2.f) + (e2->getTamanho().y / 2.f);

    if (distY - distColisaoY < 0) return distY - distColisaoY;
    return 0.f;

  } else {
    std::cerr << "erro: GerenciadorColisoes::calcOverlapVert(...)\n";
    exit(EXIT_FAILURE);
  }
}

float GerenciadorColisoes::calcOverlapHor(const Entidades::Entidade *e1,
                                          const Entidades::Entidade *e2) const {
  if (e1 && e2) {
    float distX = (e1->getPos().x + e1->getTamanho().x / 2.f) -
                  (e2->getPos().x + e2->getTamanho().x / 2.f);
    float distColisaoX =
        (e1->getTamanho().x / 2.f) + (e2->getTamanho().x / 2.f);

    if (distX - distColisaoX < 0) return distX - distColisaoX;
    return 0.f;

  } else {
    std::cerr << "erro: GerenciadorColisoes::calcOverlapHor(...)\n";
    exit(EXIT_FAILURE);
  }
}

bool GerenciadorColisoes::colidiuVertical(const Entidades::Entidade *e1,
                                          const Entidades::Entidade *e2) const {
  return calcOverlapVert(e1, e2);
}

bool GerenciadorColisoes::colidiuHorizontal(
    const Entidades::Entidade *e1, const Entidades::Entidade *e2) const {
  return calcOverlapHor(e1, e2);
}

bool GerenciadorColisoes::colidiu(const Entidade *e1,
                                  const Entidade *e2) const {
  if (e1 && e2)
    return (colidiuHorizontal(e1, e2) || colidiuVertical(e1, e2));
  else {
    std::cerr << "erro: GerenciadorColisoes::colidiu(...)\n";
    exit(EXIT_FAILURE);
  }
}

// ============================================================================
// Funcoes principais do GerenciadorColisoes
// ============================================================================

void GerenciadorColisoes::verificarColisoes() {
  // Percorrer todas as entidades verificando se colidiram
  std::set<Entidades::Projetil *>::iterator projIt;
  std::vector<Entidades::Personagens::Jogador *>::iterator jogIt;
  std::vector<Entidades::Personagens::Inimigos::Inimigo *>::iterator inimIt;
  std::list<Entidades::Obstaculos::Obstaculo *>::iterator obstIt;

  // ============================= PROJETEIS ================================
  // Projeteis colidem com obstaculos e com personagens

  for (projIt = projeteis.begin(); projIt != projeteis.end(); projIt++) {
    if (*projIt) {
      // Detectar colisao projetil-jogador
      for (jogIt = jogadores.begin(); jogIt != jogadores.end(); jogIt++) {
        if (*jogIt) {
          if (colidiu(*projIt, *jogIt)) {
            resolverColisao(*projIt, *jogIt);
          }
        }
      }

      // Detectar colisao projetil-inimigo
      for (inimIt = inimigos.begin(); inimIt != inimigos.end(); inimIt++) {
        if (*inimIt) {
          if (colidiu(*projIt, *inimIt)) {
            resolverColisao(*projIt, *inimIt);
          }
        }
      }

      // Detectar colisao projetil-obstaculo
      for (obstIt = obstaculos.begin(); obstIt != obstaculos.end(); obstIt++) {
        if (*obstIt) {
          if (colidiu(*projIt, *obstIt)) {
            resolverColisao(*projIt, *obstIt);
          }
        }
      }
    }
  }

  // ============================= INIMIGOS ================================
  // Inimigos colidem com as obstaculos e com os jogadores

  for (inimIt = inimigos.begin(); inimIt != inimigos.end(); inimIt++) {
    if (*inimIt) {
      // Detectar colisao inimigo-jogador
      for (jogIt = jogadores.begin(); jogIt != jogadores.end(); jogIt++) {
        if (*jogIt) {
          if (colidiu(*inimIt, *jogIt)) {
            resolverColisao(*inimIt, *jogIt);
          }
        }
      }

      // Detectar colisao inimigo-obstaculo
      for (obstIt = obstaculos.begin(); obstIt != obstaculos.end(); obstIt++) {
        if (*obstIt) {
          if (colidiu(*inimIt, *obstIt)) {
            resolverColisao(*inimIt, *obstIt);
          }
        }
      }
    }
  }

  // ============================= JOGADORES ================================
  // Jogadores colidem com as obstaculos

  for (jogIt = jogadores.begin(); jogIt != jogadores.end(); jogIt++) {
    if (*jogIt) {
      // Detectar colisao jogadores-obstaculos
      for (obstIt = obstaculos.begin(); obstIt != obstaculos.end(); obstIt++) {
        if (*obstIt) {
          if (colidiu(*jogIt, *obstIt)) {
            resolverColisao(*jogIt, *obstIt);
          }
        }
      }
    }
  }
}

// TODO: ????
sf::Vector2f GerenciadorColisoes::resolverColisao(Entidade *e1, Entidade *e2) {
  ID id1 = e1->getId();
  ID id2 = e2->getId();

  if (ehProjetil(id1)) {
    if (ehObstaculo(id2)) {
      // fodeu
    } else if (ehInimigo(id2)) {
      // danificar inimigo
    } else {
      // jog
    }
  } else if (ehInimigo(id1)) {
    if (ehObstaculo(id2)) {
      // ababa
    } else {
      // jog
    }
  } else {
    // jog
  }
}

void GerenciadorColisoes::notificar(Entidade *sender) {}

// ============================================================================
// Funcoes para incluir entidades no GerenciadorColisoes
// ============================================================================

void GerenciadorColisoes::incluirJog(Personagens::Jogador *pJog) {
  if (pJog) jogadores.push_back(pJog);
}

void GerenciadorColisoes::incluirInim(Personagens::Inimigos::Inimigo *pInim) {
  if (pInim) inimigos.push_back(pInim);
}

void GerenciadorColisoes::incluirObst(Obstaculos::Obstaculo *pObst) {
  if (pObst) obstaculos.push_back(pObst);
}

void GerenciadorColisoes::incluirProj(Projetil *pProj) {
  if (pProj) projeteis.insert(pProj);
}

}  // namespace Gerenciadores
