#pragma once
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>

#include "Ente.h"
namespace Menus {
class Botao : public Ente {
 private:
  sf::Text texto;
  unsigned int fontSize;
  bool selecionado;

 public:
  Botao(const std::string &text, ID id, sf::Vector2f pos);
  ~Botao();
  void executar();
  void setSelecionado(const bool);
  const bool getSelecionado() const;
};
}  // namespace Menus
