#pragma once
#include "Gerenciadores/GerenciadorGrafico.h"
#include <SFML/Graphics.hpp>

namespace Animador {

class Imagem {
private:
  Gerenciadores::Gerenciador_Grafico *pGrafico;
  sf::Texture textura;
  sf::IntRect tamanho;
  const sf::Vector2f escala;
  const unsigned int qtdImagem;
  unsigned int imgAtual;
  const float tempoTroca;
  float tempoTotal;
  const sf::Vector2f origin;

public:
  Imagem(const char *caminhoTextura, const unsigned int qtdImagem,
         const float tempoTroca, const sf::Vector2f escala,
         const sf::Vector2f origin);
  ~Imagem();
  void atualizar(const bool paraEsquerda, const float dt);
  void resetar();
  const unsigned int getQuadroAtual() const;
  void setQuadroAtual(const unsigned int imgAtual);
  const float getTempoTotal() const;
  void setTempoTotal(const float tempoTotal);
  const sf::IntRect getTamanho() const;
  const sf::Texture &getTextura();
  const sf::Vector2f getEscala() const;
  const sf::Vector2f getOrigin() const;
};

} // namespace Animador
