#pragma once

#include "Controladores/ControladorJogador.h"
#include "Entidades/Personagens/Personagem.h"
#include "Gerenciadores/GerenciadorEventos.h"
#include <SFML/System/Vector2.hpp>

namespace Entidades::Personagens {

#define VEL 0.3

class Jogador : public Personagem {
private:
  bool ehPrimeiroJogador;

protected:
  bool podePular;
  Controladores::Controlador_Jogador *pContr;

public:
  Jogador();
  ~Jogador();

  void setPrimeiroJog(bool ehPrimeiroJogador);
  bool getPrimeiroJog() const;

  void andarDireita();
  void andarEsquerda();
  void naoAndar();
  void pular();
  void mover();
  virtual void atacar() = 0;
  virtual void executar();
  Controladores::Controlador_Jogador *getControlador() const;
};

} // namespace Entidades::Personagens
