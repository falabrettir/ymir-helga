#include "Gerenciadores/GerenciadorColisoes.h"
#include "Listas/ListaEntidades.h"
#include <SFML/System/Vector2.hpp>
#include <cmath>

Gerenciadores::Gerenciador_Colisoes::Gerenciador_Colisoes(
    Listas::ListaEntidades *listChar, Listas::ListaEntidades *listObst)
    : listChar(listChar), listObst(listObst) {}
Gerenciadores::Gerenciador_Colisoes::~Gerenciador_Colisoes() {}

const sf::Vector2<float>
Gerenciadores::Gerenciador_Colisoes::calculaColisao(Entidades::Entidade *e1,
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

  return sf::Vector2<float>(dc.x - metadeRect.x, dc.y - metadeRect.y);
}
