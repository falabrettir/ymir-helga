#include "Menu/Botao.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>

namespace Menus {
Botao::Botao(std::string &text, ID id, sf::Vector2f pos)
    : Ente(id), selecionado(false) {
  texto.setFont(*Gerenciadores::GerenciadorGrafico::getInstancia()->getFonte());
  texto.setString(text);
  texto.setScale(3.f, 3.f);

  setTextura("/assets/Botao.png");
  pSprite->setPosition(pos);
}
Botao::~Botao() {
  delete pSprite;
  pSprite = nullptr;
}
} // namespace Menus
