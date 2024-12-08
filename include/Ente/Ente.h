#pragma once
#include "Gerenciadores/GerenciadorGrafico.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>

namespace Gerenciadores {

class Gerenciador_Grafico;

}

class Ente {
protected:
  int id;
  static Gerenciadores::Gerenciador_Grafico *pGG;
  static int cont;
  sf::Texture *texture;
  sf::Sprite *sprite;

public:
  Ente();
  ~Ente();
  void setGerenciadorGrafico(Gerenciadores::Gerenciador_Grafico *pGG);
  bool setTexture(const std::string &path);
  sf::Sprite *getSprite();
  void desenhar();
  // virtual void executar() = 0;
};
