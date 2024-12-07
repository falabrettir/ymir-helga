#include "../../include/Ente/Ente.h"
#include <iostream>
int Ente::cont(0);
Gerenciadores::Gerenciador_Grafico *pGG(NULL);

Ente::Ente() : id(cont++), texture(nullptr), sprite(nullptr) {}
Ente::~Ente() {}

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

void Ente::desenhar() {}

void Ente::executar() {}
