/*
 * Código adaptado do então monitor Giovane Salvi, disponível em:
 * github.com/Giovanenero/JogoPlataforma2D-Jungle
 */

#include "Gerenciadores/GerenciadorColisoes.h"

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <list>

#include "Entidades/Obstaculos/Obstaculo.h"
#include "Entidades/Personagens/Personagem.h"
#include "Entidades/Projetil.h"
#include "IDs.h"

namespace Gerenciadores {

GerenciadorColisoes *GerenciadorColisoes::instancia = nullptr;

GerenciadorColisoes::GerenciadorColisoes() : vecPers(), listObst(), setProj() {
  vecPers.clear();
  listObst.clear();
  setProj.clear();
}

GerenciadorColisoes::~GerenciadorColisoes() {}

GerenciadorColisoes *GerenciadorColisoes::getInstancia() {
  if (!instancia) {
    instancia = new GerenciadorColisoes();
  }
  return instancia;
}

sf::Vector2f GerenciadorColisoes::resolverColisao(Entidades::Entidade *e1,
                                                  Entidades::Entidade *e2) {
  sf::IntRect h1 = e1->getHitbox();
  sf::IntRect h2 = e2->getHitbox();
  sf::IntRect interseccao;

  if (h1.intersects(h2, interseccao)) {
    sf::Vector2f ds(interseccao.width, interseccao.height);

    return ds;
  }

  return {0, 0};
}

void GerenciadorColisoes::incluirPers(
    Entidades::Personagens::Personagem *pPers) {
  if (pPers) vecPers.push_back(pPers);
}

void GerenciadorColisoes::incluirObst(Entidades::Obstaculos::Obstaculo *pObst) {
  if (pObst) listObst.push_back(pObst);
}

void GerenciadorColisoes::incluirProj(Entidades::Projetil *pProj) {
  if (pProj) setProj.insert(pProj);
}

void GerenciadorColisoes::notificarColisao(Entidades::Entidade *sender) {
  if (ehProjetil(sender->getId())) {
    // colisao projeteis-personagens
    std::vector<Entidades::Personagens::Personagem *>::iterator itPers;
    for (itPers = vecPers.begin(); itPers != vecPers.end(); ++itPers) {
      sender->colidir(*itPers, resolverColisao(sender, *itPers));
    }

    // colisao projeteis-obstaculos
    std::list<Entidades::Obstaculos::Obstaculo *>::iterator itObst;
    for (itObst = listObst.begin(); itObst != listObst.end(); ++itObst) {
      sender->colidir(*itObst, resolverColisao(sender, *itObst));
    }

  } else if (ehObstaculo(sender->getId())) {
    // colisao obstaculos-personagens
    std::vector<Entidades::Personagens::Personagem *>::iterator itPers;
    for (itPers = vecPers.begin(); itPers != vecPers.end(); ++itPers) {
      sender->colidir(*itPers, resolverColisao(sender, *itPers));
    }

  } else {
    // Colisao Personagem-Personagem
    std::vector<Entidades::Personagens::Personagem *>::iterator itPers;
    for (itPers = vecPers.begin(); itPers != vecPers.end(); ++itPers) {
      sender->colidir(*itPers, resolverColisao(sender, *itPers));
    }
  }
}

}  // namespace Gerenciadores
