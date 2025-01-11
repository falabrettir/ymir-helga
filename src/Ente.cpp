#include "Ente.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <string>

int Ente::cont(0);
Gerenciadores::Gerenciador_Grafico *Ente::pGG(nullptr);

Ente::Ente()
    : id(cont++), pSprite(new sf::Sprite()), pTexture(new sf::Texture()) {
  setTarget();
}

Ente::~Ente() {
  delete pSprite;
  delete pTexture;
  delete pAlvo;
  cont--;
}

void Ente::setGerenciadorGrafico(Gerenciadores::Gerenciador_Grafico *ppGG) {
  if (ppGG != nullptr) {
    pGG = ppGG;
  }
}

void Ente::atualizaSprite(sf::Texture *pTexture) {
  pSprite->setTexture(*pTexture);
  pSprite->setTextureRect(sf::IntRect(0, 0, 100, 100));
  pSprite->setScale(3.f, 3.f);
}

bool Ente::setTexture(const std::string &path) {
  std::string filePath = ROOT;
  filePath += path;
  if (pTexture->loadFromFile(filePath)) {
    atualizaSprite(pTexture);
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

void Ente::desenhar() {
  std::clog << "desenhar Ente" << std::endl;
  if (pGG)
    pGG->desenharEnte(this);
  else {
    std::clog << "Nullptr em desenharEnte" << std::endl;
  }
}
