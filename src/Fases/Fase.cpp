#include "Fases/Fase.h"

#include <SFML/System/Vector2.hpp>
#include <fstream>
#include <iostream>
#include <string>

#include "Entidades/Entidade.h"
#include "Entidades/Obstaculos/Obstaculo.h"
#include "Entidades/Personagens/Jogador.h"
#include "Gerenciadores/GerenciadorColisoes.h"
#include "IDs.h"
#include "Listas/Lista.h"
#include "Listas/ListaEntidades.h"

using namespace Entidades;

namespace Fases {

Fase::Fase() : Ente(ID::IDfase), ehPrimeiroJogador(true) {
  pGC = Gerenciadores::Gerenciador_Colisoes::getInstancia();
  listaObstaculos.limpar();
  listaPersonagens.limpar();
}

Fase::~Fase() {
  pGC = nullptr;
  listaObstaculos.limpar();
  listaPersonagens.limpar();
}

void Fase::executar() {
  listaObstaculos.percorrer();
  listaPersonagens.percorrer();
}

// TODO:
// Percorrer a lista de obstaculos e personagens adicionando eles ao GC
// Tambem inscrever os jogadores no gerenciador de input
void Fase::inicializar() {
  Listas::Lista<Entidades::Entidade *>::Iterator it;
  for (it = listaObstaculos.begin(); it != listaObstaculos.end();
       it.operator++()) {
    pGC->incluirObst(dynamic_cast<Obstaculos::Obstaculo *>(*it));
  }
}

void Fase::criarMapa(const std::string path) {
  std::ifstream arquivoMapa;
  std::string filePath = ROOT;
  filePath += path;

  arquivoMapa.open(filePath);
  if (!arquivoMapa.is_open()) {
    std::cout << "Erro ao abrir arquivo de mapa" << std::endl;
    exit(1);
  }

  std::string linha;
  for (int j = 0; std::getline(arquivoMapa, linha); j++) {
    for (int i = 0; i < linha.size(); i++) {
      if (linha[i] != ' ') {
        criarEntidade(linha[i], sf::Vector2f(i * 16, j * 16));
      }
    }
  }

  arquivoMapa.close();
}

void Fase::criarJogador(const sf::Vector2f &pos) {
  Personagens::Jogador *novoJog =
      new Personagens::Jogador(pos, ehPrimeiroJogador);
  listaPersonagens.incluir(novoJog);
  ehPrimeiroJogador = false;
}

void Fase::criarEsqueleto(const sf::Vector2f &pos) {
  // TODO: Implementar depois de terminar a classe esqueleto
}

} // namespace Fases
