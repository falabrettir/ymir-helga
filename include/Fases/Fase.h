#pragma once

#include <SFML/System/Vector2.hpp>

#include "Gerenciadores/GerenciadorInput.h"
#include "Listas/ListaEntidades.h"

namespace Gerenciadores {
class Gerenciador_Colisoes;
} // namespace Gerenciadores

namespace Fases {

class Fase : public Ente {
protected:
  Gerenciadores::Gerenciador_Colisoes *pGC;
  Gerenciadores::Gerenciador_Input *pGI;

  Listas::ListaEntidades listaObstaculos;
  Listas::ListaEntidades listaPersonagens;

  bool ehPrimeiroJogador;

public:
  Fase();
  ~Fase();

  virtual void executar();
  void incluirNoColisor();
  void criarMapa(const std::string path);
  void criarJogador(const sf::Vector2f &pos);
  void criarEsqueleto(const sf::Vector2f &pos);
  virtual void criarEntidade(char tipoEntidade, const sf::Vector2f &pos) = 0;
};

} // namespace Fases
