#include "Fases/Fase.h"

#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include "Entidades/Entidade.h"
#include "Entidades/Obstaculos/Obstaculo.h"
#include "Entidades/Personagens/Personagem.h"
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

void Fase::incluirNoGC(Entidade *novaEntidade) {
  if (!novaEntidade) {
    std::cerr << "erro: Fase::incluirNoGC() => novaEntidade == nullptr\n";
    exit(EXIT_FAILURE);
  }

  ID id = novaEntidade->getId();

  if (ehObstaculo(id)) {
    pGC->incluirObst(dynamic_cast<Obstaculos::Obstaculo *>(novaEntidade));
  } else if (ehPersonagem(id)) {
    pGC->incluirPers(dynamic_cast<Personagens::Personagem *>(novaEntidade));
  }
}

void Fase::incluirNaLista(Entidade *novaEntidade) {
  if (!novaEntidade) {
    std::cerr << "erro: Fase::incluirNaLista() => novaEntidade == nullptr\n";
    exit(EXIT_FAILURE);
  }

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
    std::cerr << "erro: arquivoMapa.open()\n";
    exit(EXIT_FAILURE);
  }

  std::string linha;
  Entidade *novaEntidade;
  for (int j = 0; std::getline(arquivoMapa, linha); j++) {
    for (int i = 0; i < linha.size(); i++) {
      if (linha[i] != ' ') {
        novaEntidade =
            pFE->criarEntidade(linha[i], sf::Vector2f(i * 16, j * 16));
        incluirNaLista(novaEntidade);
        incluirNoGC(novaEntidade);
      }
    }
  }

  arquivoMapa.close();
}

}  // namespace Fases
