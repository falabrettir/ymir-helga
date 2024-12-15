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
  sf::RenderTarget *pAlvo;
  sf::Texture *pTexture;
  sf::Sprite *pSprite;

public:
  Ente();
  Ente(const std::string &path);
  virtual ~Ente();

  static void setGerenciadorGrafico(Gerenciadores::Gerenciador_Grafico *pGG);
  bool setTexture(const std::string &path);
  const sf::Sprite *getSprite();
  void setTarget();
  void desenhar();
  virtual void executar() = 0;
};
