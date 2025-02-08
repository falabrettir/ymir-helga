#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

#include "Entidades/Entidade.h"
#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Projetil.h"
#include "Fabrica/FabricaEntidades.h"
#include "Listas/ListaEntidades.h"
#include "State.h"

class ObservadorFase;

namespace Gerenciadores {
class GerenciadorColisoes;
} // namespace Gerenciadores

namespace Fases {

class Fase : public Ente, public States::State {
protected:
  Entidades::Personagens::Jogador *pJog;
  Gerenciadores::GerenciadorColisoes *pGC;
  Fabricas::FabricaEntidades *pFE;
  ObservadorFase *thisObs;

  Listas::ListaEntidades listaObstaculos;
  Listas::ListaEntidades listaInimigos;
  Listas::ListaEntidades listaJogadores;
  Listas::ListaEntidades listaProjeteis;

  const bool mp;

public:
  Fase(ID id, bool mp = false);
  ~Fase();

  virtual void executar();
  void notificarMorreu(Entidades::Entidade *pEnt);

  void limparListas();
  void incluirNaLista(Entidades::Entidade *novaEntidade);
  void adicionarProjetil(Entidades::Projetil *novoProjetil);
  void removerProjetil(Entidades::Projetil *projetil);
  void criarMapa(const std::string path);
  const bool getMp();
};

} // namespace Fases
