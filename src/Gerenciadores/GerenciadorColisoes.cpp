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

void GerenciadorColisoes::executar() { verificarColisoes(); }

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

float GerenciadorColisoes::calcOverlapVert(
    const Entidades::Entidade *e1, const Entidades::Entidade *e2) const {
  if (e1 && e2) {
    float distY = std::abs((e1->getPos().y + e1->getTamanho().y / 2.f) -
                           (e2->getPos().y + e2->getTamanho().y / 2.f));
    float distColisaoY =
        (e1->getTamanho().y / 2.f) + (e2->getTamanho().y / 2.f);

    return distColisaoY - distY;

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

    return distColisaoX - distX;

  } else {
    std::cerr << "erro: GerenciadorColisoes::calcOverlapHor(...)\n";
    exit(EXIT_FAILURE);
  }
}

bool GerenciadorColisoes::colidiuVertical(const Entidades::Entidade *e1,
                                          const Entidades::Entidade *e2) const {
  return calcOverlapVert(e1, e2) > 0;
}

bool GerenciadorColisoes::colidiuHorizontal(
    const Entidades::Entidade *e1, const Entidades::Entidade *e2) const {
  return calcOverlapHor(e1, e2) > 0;
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
            std::clog << "Colidiu" << std::endl;
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
            std::clog << "Colidiu" << std::endl;
            resolverColisao(*jogIt, *obstIt);
          }
        }
      }
    }
  }
}

// TODO: mudar pra void
void GerenciadorColisoes::resolverColisao(Entidade *e1, Entidade *e2) {
  ID id1 = e1->getId();
  ID id2 = e2->getId();

  // nao imnporta a direcao da colisao
  if (ehProjetil(id1)) {
    if (ehObstaculo(id2)) {
      // Apagar projetil
    } else if (ehInimigo(id2)) {
      // Danificar inimigo e apagar projetil
    } else {
      // Danificar jogador e apagar projetil
    }
  } else if (ehInimigo(id1)) {
    if (ehObstaculo(id2)) {
    } else {
    }
  } else {
    // Colisao entre jogador(e1) e obstaculo(e2)

    sf::Vector2f novaPos = e1->getPos();
    float dx = calcOverlapHor(e1, e2);
    float dy = calcOverlapVert(e1, e2);

    // Descobrir eixo da colisao
    if (dx < dy) {
      // Descobrir direcao da colisao
      if (e1->getPos().x < e2->getPos().x) {
        // Jogador colidiu da esquerda para direita
        novaPos.x -= dx;
      } else {
        // Jogador colidiu da direita para esquerda
        novaPos.x += dx;
      }
      e1->setVelX(0);
    }

    if (dy <= dx) {
      // Descobrir direcao da colisao
      if (e1->getPos().y < e2->getPos().y) {
        // Jogador caindo
        novaPos.y -= dy;
        e1->setNoChao(true);
      } else {
        // Jogador dando cabecada
        novaPos.y += dy;
      }
      e1->setVelY(0);
    }

    e1->setPos(novaPos);
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

void GerenciadorColisoes::limparEntidades() {
  jogadores.clear();
  inimigos.clear();
  obstaculos.clear();
  projeteis.clear();
}
}  // namespace Gerenciadores
