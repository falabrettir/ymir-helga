#pragma once

#include <SFML/System/Vector2.hpp>

#include "Entidades/Obstaculos/Espinho.h"
#include "Entidades/Obstaculos/Gosma.h"
#include "Entidades/Obstaculos/Plataforma.h"
#include "Entidades/Personagens/Esqueleto.h"
#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Personagens/Mago.h"
#include "Entidades/Personagens/Slime.h"

namespace Fabricas {

class FabricaEntidades {
 private:
  bool ativo;

 public:
  FabricaEntidades();
  virtual ~FabricaEntidades();
  virtual Entidades::Entidade *criarEntidade(char tipoEntidade,
                                             const sf::Vector2f &pos) = 0;

 protected:
  Entidades::Personagens::Jogador *criarJogador(const sf::Vector2f &pos);

  Entidades::Personagens::Inimigos::Esqueleto *criarEsqueleto(
      const sf::Vector2f &pos);

  Entidades::Personagens::Inimigos::Slime *criarSlime(const sf::Vector2f &pos);

  Entidades::Personagens::Inimigos::Mago *criarMago(const sf::Vector2f &pos);

  Entidades::Obstaculos::Gosma *criarGosma(const sf::Vector2f &pos);

  Entidades::Obstaculos::Espinho *criarEspinho(const sf::Vector2f &pos);

  virtual Entidades::Obstaculos::Plataforma *criarMadeira(
      const sf::Vector2f &pos) = 0;

  virtual Entidades::Obstaculos::Plataforma *criarChao(
      const sf::Vector2f &pos) = 0;
};

}  // namespace Fabricas
