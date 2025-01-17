
#include "Fases/Fase.h"
#include "Entidades/Entidade.h"
#include "Entidades/Obstaculos/Plataforma.h"
#include "Entidades/Personagens/Helga.h"
#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Personagens/Personagem.h"
#include "Entidades/Personagens/Skjolder.h"
#include "Gerenciadores/GerenciadorColisoes.h"
#include "Listas/Lista.h"
#include "Listas/ListaEntidades.h"

namespace Fases {

Fase::Fase() {
  vecJog.clear();
  listaEnt.limpar();

  pGC = Gerenciadores::Gerenciador_Colisoes::getInstancia();

  criarEntidades();

  criarPlataformas();
  criarCenario();

  executar();
}

Fase::~Fase() {
  vecJog.clear();
  listaEnt.limpar();
}

void Fase::executar() {}

void Fase::criarPlataformas() {}

void Fase::criarCenario() {}

void Fase::criarEntidades() {
  listaEnt.incluir(new Entidades::Personagens::Helga());
  listaEnt.incluir(new Entidades::Personagens::Skjolder());

  // TODO: Para cara entidade, inserir em listaEnt
  Listas::Lista<Entidades::Entidade *>::Iterator it = listaEnt.begin();
}

} // namespace Fases
