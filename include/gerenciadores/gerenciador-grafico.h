#pragma once
#include <SFML/Graphics.hpp>

namespace Gerenciadores {

class Gerenciador_Grafico {
private:
  sf::RenderWindow janela;

public:
  Gerenciador_Grafico();

  ~Gerenciador_Grafico();

  void desenharEnte(/*TODO*/);
};

} // namespace Gerenciadores
