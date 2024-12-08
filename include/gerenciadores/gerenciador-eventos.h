#pragma once

#include <SFML/Window/Event.hpp>

namespace Gerenciadores {

class Gerenciador_Eventos {
private:
  sf::Event evento;
  static Gerenciador_Eventos *instancia; // Singleton
  Gerenciador_Eventos();

public:
  ~Gerenciador_Eventos();
  static Gerenciador_Eventos *getInstancia();
  sf::Event &getEvento();
};

} // namespace Gerenciadores
