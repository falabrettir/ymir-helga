#include "Menu/Botao.h"

#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <iostream>

#include "Gerenciadores/GerenciadorGrafico.h"

namespace Menus {
Botao::Botao(const std::string& text, ID id, sf::Vector2f pos)
    : Ente(id), selecionado(false), texto() {
  inicializa(text, pos);
}
Botao::~Botao() {
  delete pSprite;
  pSprite = nullptr;
}
void Botao::executar() {
  desenhar();
  if (pAlvo == nullptr) {
    std::cerr << "Erro em Botao::executar() => pAlvo == nullptr!\n";
    exit(EXIT_FAILURE);
  }
  if (selecionado) {
    texto.setFillColor(sf::Color::Yellow);
  } else {
    texto.setFillColor(sf::Color::White);
  }
  pAlvo->draw(texto);
}
void Botao::setSelecionado(const bool selecionado) { this->selecionado = selecionado; }
const bool Botao::getSelecionado() const { return selecionado; }
void Botao::inicializa(const std::string& text, sf::Vector2f pos) {
  texto.setFont(*Gerenciadores::GerenciadorGrafico::getInstancia()->getFonte());
  texto.setString(text);
  texto.setScale(1.f, 1.f);

  setTextura("/assets/Botao.png");
  pSprite->setTextureRect({0, 0, 128, 32});

  // Centraliza o sprite do botão
  pSprite->setPosition(pos.x - pSprite->getGlobalBounds().width / 2.f, pos.y);

  // Obtém limites atualizados do sprite e do texto
  sf::FloatRect spriteBounds = pSprite->getGlobalBounds();
  sf::FloatRect textBounds = texto.getLocalBounds();

  // Define origem e posição do texto para centralizá-lo no botão
  texto.setOrigin(textBounds.width / 2.f, textBounds.height / 2.f);
  texto.setPosition(spriteBounds.left + spriteBounds.width / 2.f,
                    spriteBounds.top + spriteBounds.height / 2.f);

  texto.setFillColor(sf::Color::White);
  texto.setOutlineColor(sf::Color::Black);
  texto.setOutlineThickness(2.f);
}
}  // namespace Menus
