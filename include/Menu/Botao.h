#pragma once
#include "Ente.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Text.hpp>
namespace Menus {
class Botao : public Ente {
private:
  sf::Text texto;
  unsigned int fontSize;
  bool selecionado;

public:
  Botao(std::string &text, ID id);
  ~Botao();
  void setTexto(std::string &text);
};
} // namespace Menus
