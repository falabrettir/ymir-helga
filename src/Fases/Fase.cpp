#include "Fases/Fase.h"
#include "Gerenciadores/GerenciadorColisoes.h"
#include "IDs.h"
#include <SFML/System/Vector2.hpp>
#include <fstream>
#include <iostream>
#include <string>

namespace Fases {

Fase::Fase() : Ente(IDs::ID::IDfase), ehPrimeiroJogador(true) {
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
        criarEntidade(linha[i], sf::Vector2f(i, j));
      }
    }
  }

  arquivoMapa.close();
}

void Fase::criarJogador(const sf::Vector2f &pos) {
  ehPrimeiroJogador = false;
  // TODO: Terminar
}

void Fase::criarEsqueleto(const sf::Vector2f &pos) {
  // TODO: Implementar
}

} // namespace Fases
