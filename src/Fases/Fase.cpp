#include "Fases/Fase.h"

#include <SFML/System/Vector2.hpp>
#include <fstream>
#include <iostream>
#include <string>

#include "Entidades/Personagens/Jogador.h"
#include "Gerenciadores/GerenciadorColisoes.h"
#include "IDs.h"

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
  Personagens::Jogador *novoJog = new Personagens::Jogador(ehPrimeiroJogador);

  // Multiplicar posicao em X e Y pelo tamanho do grid ex. 16x16
  novoJog->setPos(pos);

  listaPersonagens.incluir(novoJog);

  ehPrimeiroJogador = false;
}

void Fase::criarEsqueleto(const sf::Vector2f &pos) {
  // TODO: Implementar depois de terminar a classe esqueleto
}

}  // namespace Fases
