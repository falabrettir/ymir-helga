#include "Gerenciadores/GerenciadorColisoes.h"
#include "Listas/ListaEntidades.h"
#include <SFML/System/Vector2.hpp>

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
}
