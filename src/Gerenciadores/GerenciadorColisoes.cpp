/*
 * Código adaptado do então monitor Giovane Nero, disponível em:
 * github.com/Giovanenero/JogoPlataforma2D-Jungle
 */

#include "Gerenciadores/GerenciadorColisoes.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>

namespace Gerenciadores {

Gerenciador_Colisoes *Gerenciador_Colisoes::instancia = nullptr;

Gerenciador_Colisoes::Gerenciador_Colisoes() : vecPers(), listObst() {
  vecPers.clear();
  listObst.clear();
}

Gerenciador_Colisoes::~Gerenciador_Colisoes() {}

Gerenciador_Colisoes *Gerenciador_Colisoes::getInstancia() {
  if (instancia == nullptr) {
    instancia = new Gerenciador_Colisoes();
  }
  return instancia;
}

sf::Vector2f Gerenciador_Colisoes::verificaColisao(Entidades::Entidade *e1,
                                                   Entidades::Entidade *e2) {

  //     sf::FloatRect h2 = e2->getHitbox();
  //
  //     float sbesq = (h1.left + h1.width) - h2.left;
  //     float sbdireita = (h2.left + h2.width) - h1.left;
  //     float sbcima = (h1.top + h1.height) - h2.top;
  //     float sbbaixo = (h2.top + h2.height) - h1.top;
  //
  //     bool daesq = std::abs(sbesq) < std::abs(sbdireita);
  //     bool decima = std::abs(sbcima) < std::abs(sbbaixo);
  //
  //     float sbX = daesq ? sbesq : sbdireita;
  //     float sbY = decima ? sbcima : sbbaixo;
  //
  //     if (std::abs(sbX) < std::abs(sbY)) {
  //       sf::Vector2f pos(e2->getPos().x + sbX * (daesq ? -1 : 1),
  //       e2->getPos().y); e2->setPos(pos);
  //     } else {
  //       if (decima) {
  //         sf::Vector2f pos(e2->getPos().x, e2->getPos().y + sbY * -1);
  //         e2->setNoChao(true);
  //       } else {
  //         sf::Vector2f pos(e2->getPos().x, e2->getPos().y + sbY);
  //       }
  //       e2->setVelY(0);
  //     }
  //   }
  // }
  sf::Vector2f p1 = e1->getHitbox().getPosition();
  sf::Vector2f p2 = e2->getHitbox().getPosition();

  sf::Vector2f t1 = e1->getHitbox().getSize();
  sf::Vector2f t2 = e2->getHitbox().getSize();

  sf::Vector2f dc(std::fabs((p1.x + t1.x / 2.0f) - (p2.x + t2.x / 2.0f)),
                  std::fabs((p1.y + t1.y / 2.0f) -
                            (p2.y + t2.y / 2.0f))); // calcula a distancia
  // os centros
  //  dos retangulos em x e y
  sf::Vector2f metadeRect(
      t1.x / 2.0f + t2.x / 2.0f,
      t1.y / 2.0f + t2.y / 2.0f); // calcula a distancia entre as arestas
  sf::Vector2f ds(dc.x - metadeRect.x, dc.y - metadeRect.y);
  return ds;
}

void Gerenciador_Colisoes::incluirPers(
    Entidades::Personagens::Personagem *pPers) {
  if (pPers)
    vecPers.push_back(pPers);
}

void Gerenciador_Colisoes::incluirObst(
    Entidades::Obstaculos::Obstaculo *pObst) {
  if (pObst)
    listObst.push_back(pObst);
}

// TODO: Implementar colisão com projéteis
// void Gerenciador_Colisoes::incluirProj(Entidades::Projetil *pProj){
//   if(pProj != nullptr){
//     setProj.insert(pProj);
//   }else{return;}
// }

// TODO: Refatorar
void Gerenciador_Colisoes::executar() {
  for (auto pPers : vecPers) {
    for (auto pObst : listObst) {
      pObst->colidir(pPers, verificaColisao(pPers, pObst));
    }
  }
}
} // namespace Gerenciadores
