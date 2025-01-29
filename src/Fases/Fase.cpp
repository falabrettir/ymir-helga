#include "Fases/Fase.h"

#include <SFML/System/Vector2.hpp>
#include <fstream>
#include <iostream>
#include <string>

#include "Entidades/Personagens/Esqueleto.h"
#include "Entidades/Personagens/Jogador.h"
#include "Gerenciadores/GerenciadorColisoes.h"
#include "Gerenciadores/GerenciadorInput.h"
#include "IDs.h"
#include "Listas/ListaEntidades.h"

using namespace Entidades;

namespace Fases {

Fase::Fase()
    : Ente(ID::IDfase),
      States::State(),
      ehPrimeiroJogador(true),
      listaObstaculos(new Listas::ListaEntidades()),
      listaPersonagens(new Listas::ListaEntidades),
      pGC(Gerenciadores::Gerenciador_Colisoes::getInstancia()),
      pGI(Gerenciadores::Gerenciador_Input::getInstancia()) {
  listaObstaculos->limpar();
  listaPersonagens->limpar();
}

Fase::~Fase() {
  pGC = nullptr;
  pGI = nullptr;
  listaObstaculos->limpar();
  listaPersonagens->limpar();
}

void Fase::executar() {
  listaObstaculos->executar();
  listaPersonagens->executar();
}

void Fase::incluirNoColisor() {
  Listas::Lista<Entidades::Entidade>::Iterator it;

  for (it = listaObstaculos->begin(); it != listaObstaculos->end(); ++it) {
    pGC->incluirObst(dynamic_cast<Obstaculos::Obstaculo *>(*it));
  }

  // Inclui personagens na lista de personagens do GC
  for (it = listaPersonagens->begin(); it != listaPersonagens->end(); ++it) {
    pGC->incluirPers(dynamic_cast<Entidades::Personagens::Personagem *>(*it));
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

  incluirNoColisor();
}

void Fase::criarJogador(const sf::Vector2f &pos) {
  Personagens::Jogador *novoJog = new Personagens::Jogador(pos, ehPrimeiroJogador);

  pGI->inscrever(novoJog->getControlador());

  listaPersonagens->incluir(novoJog);

  ehPrimeiroJogador = false;
}

void Fase::criarEsqueleto(const sf::Vector2f &pos) {
  Personagens::Inimigos::Esqueleto *novoEsq = new Personagens::Inimigos::Esqueleto(pos);
  listaPersonagens->incluir(novoEsq);
}

}  // namespace Fases
