#include "Menu/Botao.h"

#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>

#include "Gerenciadores/GerenciadorGrafico.h"

namespace Menus {
Botao::Botao(const std::string &text, ID id, sf::Vector2f pos) : Ente(id), selecionado(false) {
  texto.setFont(*Gerenciadores::GerenciadorGrafico::getInstancia()->getFonte());
  texto.setString(text);
  texto.setScale(3.f, 3.f);

  setTextura("/assets/Botao.png");
  pSprite->setPosition(pos);
  texto.setPosition(pSprite->getGlobalBounds().width / 2, pSprite->getGlobalBounds().height / 2);
  texto.setFillColor(sf::Color::White);
  texto.setOutlineColor(sf::Color::Black);
}
Botao::~Botao() {
  delete pSprite;
  pSprite = nullptr;
}
void Botao::executar() { desenhar(); }
}  // namespace Menus
