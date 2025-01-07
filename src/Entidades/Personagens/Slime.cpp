#include "../include/Entidades/Personagens/Slime.h"
#include "Entidades/Personagens/Inimigo.h"
#include "Entidades/Personagens/Jogador.h"
#include <SFML/System/Vector2.hpp>
#include <iostream>

Inimigos::Slime::Slime() : lentidao(0) {

  setTexture("/assets/Characters(100x100)/Slime/Slime/Slime-Idle.png");
}
Inimigos::Slime::Slime(sf::Vector2<float> pos, sf::Vector2<float> tamanho,
                       const std::string &path,
                       Entidades::Personagens::Jogador *pJog)
    : lentidao(0),
      Entidades::Personagens::Inimigos::Inimigo(pos, tamanho, path, pJog) {}
Inimigos::Slime::~Slime() {}
void Inimigos::Slime::danificar(Entidades::Personagens::Jogador *pJog) {
  std::cout << "Danificando!" << std::endl;
}
void Inimigos::Slime::executar() {
  if (pJ->getPos().x > this->getPos().x) {
    std::cout << "Perseguindo!" << std::endl;
  }
}
