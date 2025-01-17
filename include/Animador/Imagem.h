#pragma once
#include "Gerenciadores/GerenciadorGrafico.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
namespace Animador {
class Imagem {
private:
  Gerenciadores::Gerenciador_Grafico *pGrafico;
  sf::Texture textura;
  sf::IntRect tam;
  const sf::Vector2f escala;
  const unsigned short int qtdImg;
  unsigned short int imgAtual;
  const float tempoTroca;
  float tempoTotal;

public:
  Imagem(const std::string &path, const unsigned short int qtdImg,
         const float tempoTroca, const sf::Vector2f escala);
  ~Imagem();
  void atualizar(const bool praEsq, const float dt);
  void resetar();
  const sf::IntRect getTamanho() const;
  const sf::Texture *getTextura() const;
  const sf::Vector2f getEscala() const;
};
} // namespace Animador
