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
  sf::Vector2 p1 = e1->getPos();
  sf::Vector2 p2 = e2->getPos();

  sf::Vector2 t1 = e1->getTamanho();
  sf::Vector2 t2 = e2->getTamanho();

  // Distancia entre os centros dos retangulos
  // Se a componente X for negativa, e2 esta mais para a direita
  // Se a componente Y for negativa, e2 esta mais para baixo
  sf::Vector2f dc(std::fabs((p1.x + t1.x / 2.0f) - (p2.x + t2.x / 2.0f)),
                  std::fabs((p1.y + t1.y / 2.0f) - (p2.y + t2.y / 2.0f)));

  // Distancia maxima entre o centro dos retangulos antes de haver interseccao
  sf::Vector2f metadeRect(t1.x / 2.0f + t2.x / 2.0f, t1.y / 2.0f + t2.y / 2.0f);

  // Vetor de deslocamento
  // Negativo se houver interseccao
  sf::Vector2f ds(dc.x - metadeRect.x, dc.y - metadeRect.y);

  return ds;
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
