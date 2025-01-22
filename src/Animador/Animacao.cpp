#include "Animador/Animacao.h"
#include <SFML/System/Vector2.hpp>
namespace Animador {
Animacao::Animacao(sf::RectangleShape *corpo)
    : corpo(corpo), mapImagem(), imgAtual(""), relogio() {}
Animacao::~Animacao() {
  std::map<std::string, Imagem *>::iterator it = mapImagem.begin();
  while (it != mapImagem.end()) {
    if (it->second) {
      delete (it->second);
      it->second = nullptr;
    }
    it++;
  }
  mapImagem.clear();
}
void Animacao::atualizar(const bool praEsq, std::string imgAtual) {
  if (this->imgAtual != imgAtual) {
    if (this->imgAtual != "") {
      mapImagem[this->imgAtual]->resetar();
    }
    this->imgAtual = imgAtual;
  }
  float dt = relogio.getElapsedTime().asSeconds();
  relogio.restart();

  Imagem *img = mapImagem[this->imgAtual];
  sf::Vector2f tamCorpo = corpo->getSize();
  sf::Vector2f escala = img->getEscala();

  img->atualizar(praEsq, dt);
  corpo->setTextureRect(img->getTamanho());
  corpo->setTexture(img->getTextura());
  corpo->setScale(escala.x, escala.y);
}
void Animacao::addAnim(const std::string &path, std::string nomeAnim,
                       const unsigned short int qtdImg, float tempotroca,
                       const sf::Vector2f escala) {
  Imagem *img = new Imagem(path, qtdImg, tempotroca, escala);
  mapImagem.insert(std::pair<std::string, Imagem *>(nomeAnim, img));
}

} // namespace Animador
