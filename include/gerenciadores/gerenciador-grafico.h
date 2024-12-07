#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>
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
  bool estaAberta();
  void display();
  bool pollEvent(sf::Event &evento);
};

} // namespace Gerenciadores
