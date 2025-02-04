#include "Ente.h"

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <iostream>
#include <string>

#include "Gerenciadores/GerenciadorGrafico.h"

Gerenciadores::GerenciadorGrafico *Ente::pGG(
    Gerenciadores::GerenciadorGrafico::getInstancia());

Ente::Ente(ID id) : id(id) {
  pSprite = new sf::Sprite();
  pTexture = new sf::Texture();
  if (pGG == nullptr) pGG = Gerenciadores::GerenciadorGrafico::getInstancia();
  setTarget();
}

Ente::~Ente() {
  delete pSprite;
  delete pTexture;
  delete pAlvo;
}

void Ente::atualizaSprite(sf::Texture *pTexture) {
  pSprite->setTexture(*pTexture);
  // pSprite->setTextureRect({0, 0, 48, 48});
  pSprite->setScale(3.f, 3.f);
}

bool Ente::setTextura(const std::string &path) {
  std::string filePath = ROOT;
  filePath += path;
  if (pTexture->loadFromFile(filePath)) {
    atualizaSprite(pTexture);
    return true;
  } else {
    std::cerr << "erro: loadFromFile()\n";
    exit(EXIT_FAILURE);
  }
}

sf::Sprite Ente::getSprite() { return *pSprite; }

void Ente::setTarget() {
  if (pGG) {
    pAlvo = pGG->getJanela();
  } else {
    std::cerr << "erro: Ente::setTarget() => pGG == nullptr\n";
    exit(EXIT_FAILURE);
  }
}

void Ente::desenhar() {
  if (pGG)
    pGG->desenharEnte(this);
  else {
    std::cerr << "erro: Ente::desenhar() => pGG == nullptr";
    exit(EXIT_FAILURE);
  }
}

const ID Ente::getId() const { return this->id; }
