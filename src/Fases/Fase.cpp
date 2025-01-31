#include "Fases/Fase.h"

#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "Entidades/Entidade.h"
#include "Gerenciadores/GerenciadorColisoes.h"
#include "IDs.h"
#include "Listas/ListaEntidades.h"

using namespace Entidades;

namespace Fases {

Fase::Fase()
    : Ente(ID::IDfase),
      States::State(),
      listaObstaculos(),
      listaJogadores(),
      listaInimigos(),
      listaProjeteis(),
      pGC(Gerenciadores::GerenciadorColisoes::getInstancia()) {
  listaObstaculos.limpar();
  listaJogadores.limpar();
  listaInimigos.limpar();
  listaProjeteis.limpar();
}

Fase::~Fase() {
  pGC = nullptr;
  listaObstaculos.limpar();
  listaJogadores.limpar();
  listaInimigos.limpar();
  listaProjeteis.limpar();
}

void Fase::executar() {
  listaObstaculos.executar();
  listaJogadores.executar();
  listaInimigos.executar();
  // TODO: listaProjeteis.executar() ???
}

void Fase::incluirNoColisor() {
  Listas::Lista<Entidade>::Iterator it;

  // Inclui obstaculos na lista de obstaculos do GC
  for (it = listaObstaculos.begin(); it != listaObstaculos.end(); ++it) {
    pGC->incluirObst(dynamic_cast<Obstaculos::Obstaculo *>(*it));
  }

  // Inclui jogadores na lista de personagens do GC
  for (it = listaJogadores.begin(); it != listaJogadores.end(); ++it) {
    pGC->incluirPers(dynamic_cast<Personagens::Personagem *>(*it));
  }

  // Inclui inimigos na lista de personagens do GC
  for (it = listaInimigos.begin(); it != listaInimigos.end(); ++it) {
    pGC->incluirPers(dynamic_cast<Personagens::Personagem *>(*it));
  }
}

void Fase::incluirNasListas(Entidade *novaEntidade) {
  ID id = novaEntidade->getId();
  if (ehJogador(id)) {
    listaJogadores.incluir(novaEntidade);
  } else if (ehInimigo(id)) {
    listaInimigos.incluir(novaEntidade);
  } else if (ehObstaculo(id)) {
    listaObstaculos.incluir(novaEntidade);
  }
}

void Fase::criarMapa(const std::string path) {
  std::ifstream arquivoMapa;
  std::string filePath = ROOT;
  filePath += path;

  arquivoMapa.open(filePath);
  if (!arquivoMapa.is_open()) {
    std::cout << "Erro ao abrir arquivo de mapa" << std::endl;
    exit(EXIT_FAILURE);
  }

  std::string linha;
  Entidade *novaEntidade;
  for (int j = 0; std::getline(arquivoMapa, linha); j++) {
    for (int i = 0; i < linha.size(); i++) {
      if (linha[i] != ' ') {
        novaEntidade =
            pFE->criarEntidade(linha[i], sf::Vector2f(i * 16, j * 16));
        incluirNasListas(novaEntidade);
      }
    }
  }

  arquivoMapa.close();

  incluirNoColisor();
}

}  // namespace Fases
