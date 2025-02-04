#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

#include "Controladores/ControladorJogador.h"
#include "Entidades/Personagens/Personagem.h"
#include "Entidades/Projetil.h"
#include "Fabrica/FabricaProjeteis.h"
#include "Gerenciadores/GerenciadorEventos.h"
#include "Gerenciadores/GerenciadorInput.h"

namespace Entidades::Personagens {

#define MAXVEL 0.3
#define ACEL 0.05;

class Jogador : public Personagem {
 private:
  static Gerenciadores::GerenciadorInput *pGI;
  static Fabricas::FabricaProjeteis *fabProj;
  Controladores::Controlador_Jogador *pContr;
  static bool ehPrimeiroJogador;
  bool podePular;
  Entidades::Projetil *pProj;

 public:
  Jogador(const sf::Vector2f &pos);
  ~Jogador();

  bool getPrimeiroJog() const;

  void colidir(Entidade *pEnt, sf::Vector2f ds = {0, 0});
  void andarDireita();
  void andarEsquerda();
  void naoAndar();
  void pular();
  void atacar();
  void executar();
  void aplicaLentidao(float viscosidade);
};

}  // namespace Entidades::Personagens
