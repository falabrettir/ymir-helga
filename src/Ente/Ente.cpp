#include "Ente/Ente.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include <iostream>

int Ente::cont(0);
Gerenciadores::Gerenciador_Grafico *Ente::pGG(nullptr);

Ente::Ente() : id(cont++), texture(nullptr), sprite(nullptr) {}

Ente::~Ente() {}

void Ente::setGerenciadorGrafico(Gerenciadores::Gerenciador_Grafico *pGG) {
  if (pGG != nullptr) {
    this->pGG = pGG;
  }
}

bool Ente::setTexture(const std::string &path) {
  if (texture->loadFromFile(path)) {
    if (!sprite) {
      sprite = new sf::Sprite();
    }
    sprite->setTexture(*texture);
    return true;
  } else {
    std::cerr << "Erro em loadFromFile" << std::endl;
    return false;
  }
}

sf::Sprite *Ente::getSprite() { return sprite; }

void Ente::desenhar() {}

// void Ente::executar() {}
