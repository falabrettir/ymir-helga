#pragma once
#include "Imagem.h"
namespace Animador {
class Animacao {
private:
  sf::RectangleShape *corpo;
  std::map<std::string, Imagem *> mapImagem;
  sf::Clock relogio;
  std::string imgAtual;

public:
  Animacao(sf::RectangleShape *corpo);
  ~Animacao();
  void atualizar(const bool praEsq, std::string imgAtual);
  void addAnim(const std::string &path, std::string nomeAnim,
               const unsigned short int qtdImg, float tempotroca,
               const sf::Vector2f escala);
};
} // namespace Animador
