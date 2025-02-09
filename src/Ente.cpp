#include "Ente.h"

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <iostream>
#include <string>

#include "Gerenciadores/GerenciadorGrafico.h"

Gerenciadores::GerenciadorGrafico* Ente::pGG(Gerenciadores::GerenciadorGrafico::getInstancia());

Ente::Ente(ID id) : id(id) {
  pSprite = new sf::Sprite();
  pTexture = new sf::Texture();

  setTarget();
}

Ente::~Ente() {
  delete pSprite;
  pSprite = nullptr;

  delete pTexture;
  pTexture = nullptr;

  pAlvo = nullptr;
  std::clog << "~Ente" << std::endl;
}

void Ente::atualizaSprite(sf::Texture* pTexture) {
  pSprite->setTexture(*pTexture);
  pSprite->setScale(3.f, 3.f);
}

bool Ente::setTextura(const std::string& path) {
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
  if (pGG == nullptr) {
    std::cerr << "erro: Ente::setTarget() => pGG == nullptr" << std::endl;
    exit(EXIT_FAILURE);
  }

  pAlvo = pGG->getJanela();
}

void Ente::desenhar() {
  if (pGG == nullptr) {
    std::cerr << "erro: Ente::desenhar() => pGG == nullptr" << std::endl;
    exit(EXIT_FAILURE);
  }

  pGG->desenharEnte(this);
}

const ID Ente::getId() const { return this->id; }
