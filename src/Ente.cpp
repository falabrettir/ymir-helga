#include "Ente.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <string>

int Ente::cont(0);
Gerenciadores::Gerenciador_Grafico *Ente::pGG(nullptr);

Ente::Ente() : id(cont++) {}

Ente::Ente(const std::string &path) : id(cont++) {
  pSprite = new sf::Sprite();
  pTexture = new sf::Texture();
  setTexture(path);
  setTarget();
}

Ente::~Ente() {}

void Ente::setGerenciadorGrafico(Gerenciadores::Gerenciador_Grafico *pGG) {
  if (pGG != nullptr) {
    pGG = pGG;
  }
}

bool Ente::setTexture(const std::string &path) {
  std::string filePath = ROOT;
  filePath += path;
  if (pTexture->loadFromFile(filePath)) {
    if (!pSprite) {
      pSprite = new sf::Sprite();
    }
    pSprite->setTexture(*pTexture);
    pSprite->setTextureRect(sf::IntRect(0, 0, 100, 100));
    return true;
  } else {
    std::cerr << "Erro em loadFromFile" << std::endl;
    return false;
  }
}

const sf::Sprite *Ente::getSprite() { return pSprite; }

void Ente::setTarget() {
  if (pGG != nullptr) {
    pAlvo = (pGG->getJanela());
  }
}

void Ente::desenhar() { pAlvo->draw(*(getSprite())); }
