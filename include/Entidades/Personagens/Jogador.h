#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

#include "Controladores/ControladorJogador.h"
#include "Entidades/Personagens/Personagem.h"
#include "Gerenciadores/GerenciadorEventos.h"

namespace Entidades::Personagens {

#define MAXVEL 0.3
#define ACEL 0.05;

class Jogador : public Personagem {
 private:
  bool ehPrimeiroJogador;

 protected:
  bool podePular;
  Controladores::Controlador_Jogador *pContr;

 public:
  Jogador(const sf::Vector2f &pos, const bool ehPrimeiroJogador = true);
  ~Jogador();

  void setPrimeiroJog(bool ehPrimeiroJogador);
  bool getPrimeiroJog() const;

  void colidir(Entidade *pEnt, sf::Vector2f ds = {0, 0});
  void andarDireita();
  void andarEsquerda();
  void naoAndar();
  void pular();
  void atacar();
  void executar();
  void aplicaLentidao(float viscosidade);

  Controladores::Controlador_Jogador *getControlador() const;
};

}  // namespace Entidades::Personagens
