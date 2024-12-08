#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>
#include <map>
#include <string>

class Ente;

namespace Gerenciadores {

class Gerenciador_Grafico {
private:
  sf::RenderWindow janela;
  std::map<std::string, sf::Texture *> textureMap;
  Gerenciador_Grafico();
  static Gerenciador_Grafico *instancia; // Singleton

public:
  ~Gerenciador_Grafico();
  static Gerenciador_Grafico *getInstancia();
  sf::RenderWindow getJanela();
  void desenharEnte(Ente *pE);
  bool janelaAberta();
  void display();
  bool pollEvent(sf::Event &evento);
  void clear();
};

} // namespace Gerenciadores
