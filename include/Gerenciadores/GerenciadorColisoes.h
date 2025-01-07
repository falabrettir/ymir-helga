#pragma once
#include "Listas/ListaEntidades.h"
#include <SFML/System/Vector2.hpp>
namespace Gerenciadores {
class Gerenciador_Colisoes {
private:
  Listas::ListaEntidades *listChar;
  Listas::ListaEntidades *listObst;

public:
  Gerenciador_Colisoes(Listas::ListaEntidades *listChar,
                       Listas::ListaEntidades *listObst);
  ~Gerenciador_Colisoes();
  const sf::Vector2<float> calculaColisao(Entidades::Entidade *e1,
                                          Entidades::Entidade *e2);
  void executar();
};
} // namespace Gerenciadores
