#pragma once
#include "Entidades/Personagens/Personagem.h"
#include <SFML/Graphics/Texture.hpp>
#include <map>
namespace Animacoes {
class Animador {
private:
  Entidades::Personagens::Personagem *pPers;
  std::map<sf::Texture, const std::string> mapText;
  std::string atual;
  sf::Clock relogio;

public:
  Animador(Entidades::Personagens::Personagem *pPers);
  ~Animador();
  void addAnim(const std::string &path, const std::string &nome,
               const unsigned short int nSprites, const float tTroca);
  void animar(const bool praEsq, const std::string &imgAtual);
  void atualizar(const bool praEsq, const float dt);
};
} // namespace Animacoes
