#include "Ente.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include <iostream>
#include <string>

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
  std::string filePath = ROOT;
  filePath += path;
  if (texture->loadFromFile(filePath)) {
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

sf::Sprite Ente::getSprite() { return *sprite; }

void Ente::setTarget() {
  if (pGG != nullptr) {
    alvo = (pGG->getJanela());
  }
}
void Ente::desenhar() { alvo->draw(getSprite()); }

// void Ente::executar() {}
