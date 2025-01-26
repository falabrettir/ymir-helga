/*
 * Código adaptado do então monitor Giovane Nero, disponível em:
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

namespace Gerenciadores {

Gerenciador_Colisoes *Gerenciador_Colisoes::instancia = nullptr;

Gerenciador_Colisoes::Gerenciador_Colisoes() : vecPers(), listObst(), setProj() {
  vecPers.clear();
  listObst.clear();
  setProj.clear();
}

Gerenciador_Colisoes::~Gerenciador_Colisoes() {}

Gerenciador_Colisoes *Gerenciador_Colisoes::getInstancia() {
  if (!instancia) {
    instancia = new Gerenciador_Colisoes();
  }
  return instancia;
}

sf::Vector2f Gerenciador_Colisoes::verificaColisao(Entidades::Entidade *e1,
                                                   Entidades::Entidade *e2) {
  sf::Vector2f p1 = e1->getHitbox().getPosition();
  sf::Vector2f p2 = e2->getHitbox().getPosition();

  sf::Vector2f t1 = e1->getHitbox().getSize();
  sf::Vector2f t2 = e2->getHitbox().getSize();

  // Distancia entre os centros dos retangulos
  sf::Vector2f dc(std::fabs((p1.x + t1.x / 2.0f) - (p2.x + t2.x / 2.0f)),
                  std::fabs((p1.y + t1.y / 2.0f) - (p2.y + t2.y / 2.0f)));

  // Distancia entre as arestas
  sf::Vector2f metadeRect(t1.x / 2.0f + t2.x / 2.0f, t1.y / 2.0f + t2.y / 2.0f);

  // Vetor de deslocamento
  sf::Vector2f ds(dc.x - metadeRect.x, dc.y - metadeRect.y);

  return ds;
}

void Gerenciador_Colisoes::incluirPers(Entidades::Personagens::Personagem *pPers) {
  if (pPers) vecPers.push_back(pPers);
}

void Gerenciador_Colisoes::incluirObst(Entidades::Obstaculos::Obstaculo *pObst) {
  if (pObst) listObst.push_back(pObst);
}

void Gerenciador_Colisoes::incluirProj(Entidades::Projetil *pProj) {
  if (pProj) setProj.insert(pProj);
}

void Gerenciador_Colisoes::executar() {
  std::vector<Entidades::Personagens::Personagem *>::iterator itPers;
  std::list<Entidades::Obstaculos::Obstaculo *>::iterator itObst;
  std::set<Entidades::Projetil *>::iterator itProj;

  // Colisao personagem - obstaculos
  for (itPers = vecPers.begin(); itPers != vecPers.end(); itPers++) {
    for (itObst = listObst.begin(); itObst != listObst.end(); itObst++) {
      (*itObst)->colidir((*itPers), verificaColisao((*itPers), (*itObst)));
    }
  }

  // Colisao projetil - (obstaculos + personagens)
  for (itProj = setProj.begin(); itProj != setProj.end(); itProj++) {
    for (itPers = vecPers.begin(); itPers != vecPers.end(); itPers++) {
      (*itProj)->colidir((*itProj), verificaColisao((*itProj), (*itPers)));
    }
  }

  for (itProj = setProj.begin(); itProj != setProj.end(); itProj++) {
    for (itObst = listObst.begin(); itObst != listObst.end(); itObst++) {
      (*itProj)->colidir((*itProj), verificaColisao((*itProj), (*itObst)));
    }
  }
}

}  // namespace Gerenciadores
