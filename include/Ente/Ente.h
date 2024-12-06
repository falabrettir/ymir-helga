#pragma once
#include "../gerenciadores/gerenciador-grafico.h"
#include <SFML/Graphics/Texture.hpp>

class Ente {
protected:
  int id;
  static Gerenciadores::Gerenciador_Grafico *pGG;
  static int cont;
  sf::Texture *texture;

public:
  Ente();
  ~Ente();
  void setGerenciadorGrafico(Gerenciadores::Gerenciador_Grafico *pGG);
  virtual void desenhar() = 0;
  virtual void executar() = 0;
};
