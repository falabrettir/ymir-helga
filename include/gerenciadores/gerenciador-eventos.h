#pragma once

#include <SFML/Window/Event.hpp>

namespace Gerenciadores {

class Gerenciador_Eventos {
private:
  sf::Event evento;
  static Gerenciador_Eventos *instancia;
  Gerenciador_Eventos(); // Singleton

public:
  ~Gerenciador_Eventos();
  sf::Event &getEvento();
  static Gerenciador_Eventos *getInstancia();
};

} // namespace Gerenciadores
