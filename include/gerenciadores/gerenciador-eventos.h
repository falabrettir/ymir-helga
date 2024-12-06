#pragma once

#include "gerenciadores/gerenciador-grafico.h"
#include <SFML/Window/Event.hpp>

namespace Gerenciadores {

class Gerenciador_Eventos {
private:
  sf::Event evento;

public:
  void executar(Gerenciador_Grafico *pGG);
};

} // namespace Gerenciadores
