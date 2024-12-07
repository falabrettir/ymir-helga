#pragma once

#include <SFML/Window/Event.hpp>

namespace Gerenciadores {

class Gerenciador_Eventos {
private:
  sf::Event evento;

public:
  Gerenciador_Eventos();
  ~Gerenciador_Eventos();
  sf::Event *getEvento
};

} // namespace Gerenciadores
