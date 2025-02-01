#pragma once
#include "Ente.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
namespace Menus {
class Botao : public Ente {
private:
  sf::Text texto;
  unsigned int fontSize;
  bool selecionado;

public:
  Botao(std::string &text, ID id, sf::Vector2f pos);
  ~Botao();
};
} // namespace Menus
