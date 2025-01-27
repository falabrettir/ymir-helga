#include "Ente.h"

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <string>

#include "Gerenciadores/GerenciadorGrafico.h"

Gerenciadores::Gerenciador_Grafico *Ente::pGG(nullptr);

Ente::Ente(ID id) : id(id) {
  pSprite = new sf::Sprite();
  pTexture = new sf::Texture();
  // pGG = Gerenciadores::Gerenciador_Grafico::getInstancia();
  setTarget();
}

Ente::~Ente() {
  delete pSprite;
  delete pTexture;
  delete pAlvo;
}

void Ente::setGerenciadorGrafico(Gerenciadores::Gerenciador_Grafico *ppGG) {
  if (ppGG != nullptr) {
    pGG = ppGG;
  } else {
    std::cerr << "Erro em setGerenciadorGrafico: pGG == NULL\n";
  }
}

void Ente::atualizaSprite(sf::Texture *pTexture) {
  std::clog << "funcao Ente::atualizaSprite" << std::endl;
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
    std::cerr << "Erro em loadFromFile" << std::endl;
    return false;
  }
}

sf::Sprite Ente::getSprite() { return *pSprite; }

void Ente::setTarget() {
  printf("%p\n", pGG);
  if (pGG) {
    pAlvo = pGG->getJanela();
  } else {
    std::cerr << "Erro em setTarget" << std::endl;
  }
}

void Ente::desenhar() {
  if (pGG)
    pGG->desenharEnte(this);
  else {
    std::clog << "Nullptr em desenharEnte" << std::endl;
  }
}
const ID Ente::getId() const { return this->id; }
