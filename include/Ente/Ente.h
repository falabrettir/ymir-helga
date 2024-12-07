#pragma once
#include "../gerenciadores/gerenciador-grafico.h"
#include <SFML/Graphics/Sprite.hpp>

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
  virtual void desenhar();
  virtual void executar() = 0;
};
