/*
 * Código adaptado do então monitor Giovane Salvi, disponível em:
 * github.com/Giovanenero/JogoPlataforma2D-Jungle
 */

#include "Gerenciadores/GerenciadorColisoes.h"

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <iostream>
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
  sf::Vector2f pos1 = e1->getPos();
  sf::Vector2f pos2 = e2->getPos();

  sf::Vector2f tam1 = e1->getSize();
  sf::Vector2f tam2 = e2->getSize();

  sf::Vector2f distanciaEntreCentros(
      fabs((pos1.x + tam1.x / 2.0f) - (pos2.x + tam2.x / 2.0f)),
      fabs((pos1.y + tam1.y / 2.0f) - (pos2.y + tam2.y / 2.0f)));
  sf::Vector2f somaMetadeRectangulo(tam1.x / 2.0f + tam2.x / 2.0f,
                                    tam1.y / 2.0f + tam2.y / 2.0f);
  return sf::Vector2f(distanciaEntreCentros.x - somaMetadeRectangulo.x,
                      distanciaEntreCentros.y - somaMetadeRectangulo.y);
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
  // ==========================================================================
  // Checar colisao de projeteis com todos os outros tipos de entidades
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

    // ==========================================================================
    // Checar colisao de obstaculos com personagens
  } else if (ehObstaculo(sender->getId())) {
    // colisao obstaculos-personagens
    std::vector<Entidades::Personagens::Personagem *>::iterator itPers;
    for (itPers = vecPers.begin(); itPers != vecPers.end(); ++itPers) {
      sender->colidir(*itPers, resolverColisao(sender, *itPers));
    }

  } else {
    // ==========================================================================
    // Checar colisao de personagens com personagens
    // Colisao Personagem-Personagem
    std::vector<Entidades::Personagens::Personagem *>::iterator itPers;
    for (itPers = vecPers.begin(); itPers != vecPers.end(); ++itPers) {
      sender->colidir(*itPers, resolverColisao(sender, *itPers));
    }
  }
}

}  // namespace Gerenciadores
