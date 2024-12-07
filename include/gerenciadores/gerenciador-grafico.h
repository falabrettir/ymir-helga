#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <string>

namespace Gerenciadores {

class Gerenciador_Grafico {
private:
  sf::RenderWindow janela;
  std::map<std::string, sf::Texture *> textureMap;

public:
  Gerenciador_Grafico();

  ~Gerenciador_Grafico();

  void desenharEnte(/*TODO*/);

  sf::RenderWindow *getJanela();
  void display();
};

} // namespace Gerenciadores
