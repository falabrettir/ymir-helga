#pragma once
#include "Gerenciadores/GerenciadorGrafico.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Window.hpp>
#include <string>

class Ente {
protected:
  int id;
  static Gerenciadores::Gerenciador_Grafico *pGG;
  static int cont;
  sf::RenderTarget *alvo;
  sf::Texture *texture;
  sf::Sprite *sprite;

public:
  Ente();
  Ente(const std::string &path);
  ~Ente();

  void setGerenciadorGrafico(Gerenciadores::Gerenciador_Grafico *pGG);
  bool setTexture(const std::string &path);
  sf::Sprite getSprite();
  void setTarget();
  virtual void desenhar();
  virtual void executar() = 0;
};
