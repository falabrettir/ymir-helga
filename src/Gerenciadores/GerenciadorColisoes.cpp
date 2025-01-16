// Código adaptado do então monitor Giovane Nero, disponível em:
// github.com/Giovanenero/JogoPlataforma2D-Jungle
#include "Gerenciadores/GerenciadorColisoes.h"
#include "Listas/Lista.h"
#include "Listas/ListaEntidades.h"
#include <SFML/System/Vector2.hpp>
#include <cmath>
namespace Gerenciadores {
static Gerenciador_Colisoes *instancia(nullptr);

Gerenciador_Colisoes::Gerenciador_Colisoes() : vecChar() {}
Gerenciador_Colisoes::~Gerenciador_Colisoes() {}
Gerenciador_Colisoes *Gerenciador_Colisoes::getInstancia() {
  if (instancia == nullptr) {
    instancia = new Gerenciador_Colisoes();
  }
  return instancia;
}

sf::Vector2<float>
Gerenciador_Colisoes::verificaColisao(Entidades::Entidade *e1,
                                      Entidades::Entidade *e2) {
  sf::Vector2<float> p1 = e1->getPos();
  sf::Vector2<float> p2 = e2->getPos();

  sf::Vector2<float> t1 = e1->getSize();
  sf::Vector2<float> t2 = e2->getSize();

  sf::Vector2<float> dc(
      std::fabs((p1.x + t1.x / 2.0f) - (p2.x + t2.x / 2.0f)),
      std::fabs((p1.y + t1.y / 2.0f) -
                (p2.y + t2.y / 2.0f))); // calcula a distancia entre os centros
                                        // dos retangulos em x e y
  sf::Vector2<float> metadeRect(
      t1.x / 2.0f + t2.x / 2.0f,
      t1.y / 2.0f + t2.y / 2.0f); // calcula a distancia entre as arestas
  sf::Vector2<float> ds(dc.x - metadeRect.x, dc.y - metadeRect.y);
  return ds;
}

void Gerenciador_Colisoes::incluirChar(
    Entidades::Personagens::Personagem *pPers) {
  if (pPers != nullptr) {
    vecChar.push_back(pPers);
  } else {
    return;
  }
}
// void Gerenciador_Colisoes::incluirObst(Entidades::Obstaculos* pObst){
//   if(pObst != nullptr){
//     listObst.push_back(pObst);
//   }else{return;}
// }
// void Gerenciador_Colisoes::incluirProj(Entidades::Projetil *pProj){
//   if(pProj != nullptr){
//     setProj.insert(pProj);
//   }else{return;}
// }

// TODO: Cozer
void Gerenciador_Colisoes::executar() {}
} // namespace Gerenciadores
