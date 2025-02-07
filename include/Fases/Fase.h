#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

#include "Entidades/Entidade.h"
#include "Entidades/Projetil.h"
#include "Fabrica/FabricaEntidades.h"
#include "Listas/ListaEntidades.h"
#include "State.h"

class ObservadorFase;

namespace Gerenciadores {
class GerenciadorColisoes;
}  // namespace Gerenciadores

namespace Fases {

class Fase : public Ente, public States::State {
 protected:
  Gerenciadores::GerenciadorColisoes *pGC;
  Fabricas::FabricaEntidades *pFE;
  ObservadorFase *thisObs;

  Listas::ListaEntidades listaObstaculos;
  Listas::ListaEntidades listaInimigos;
  Listas::ListaEntidades listaJogadores;
  Listas::ListaEntidades listaProjeteis;

 public:
  Fase();
  ~Fase();

  virtual void executar();

  void incluirNoGC(                        // TODO: excluir essa funcao e
      Entidades::Entidade *novaEntidade);  // responsabilizar cada entidade por
                                           // se cadastrar no gc

  void incluirNaLista(Entidades::Entidade *novaEntidade);
  void adicionarProjetil(Entidades::Projetil *novoProjetil);
  void removerProjetil(Entidades::Projetil *projetil);
  void criarMapa(const std::string path);
};

}  // namespace Fases
