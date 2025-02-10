#pragma once
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>

#include "Ente.h"
namespace Menus {
class Botao : public Ente {
 private:
  sf::Text texto;
  bool selecionado;

 public:
  Botao(const std::string &text, ID id, sf::Vector2f pos);
  ~Botao();
  void executar();
  void setSelecionado(const bool selecionado);
  const bool getSelecionado() const;
  void inicializa(const std::string &text, sf::Vector2f pos);
  void mudaFase(bool fase2);
  void mudaMultijogador(bool mp);
};
}  // namespace Menus
