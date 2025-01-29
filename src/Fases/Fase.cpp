#include "Fases/Fase.h"

#include <SFML/System/Vector2.hpp>
#include <fstream>
#include <iostream>
#include <string>

#include "Gerenciadores/GerenciadorColisoes.h"
#include "IDs.h"
#include "Listas/ListaEntidades.h"

using namespace Entidades;

namespace Fases {

Fase::Fase()
    : Ente(ID::IDfase), listaObstaculos(), listaPersonagens(), pFE(nullptr) {
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

  pGC->executar();
}

void Fase::incluirNoColisor() {
  Listas::Lista<Entidades::Entidade *>::Iterator it;

  for (it = listaObstaculos.begin(); it != listaObstaculos.end(); ++it) {
    pGC->incluirObst(dynamic_cast<Obstaculos::Obstaculo *>(*(*it)));
  }

  // Inclui personagens na lista de personagens do GC
  for (it = listaPersonagens.begin(); it != listaPersonagens.end(); ++it) {
    pGC->incluirPers(
        dynamic_cast<Entidades::Personagens::Personagem *>(*(*it)));
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
        pFE->criarEntidade(linha[i], sf::Vector2f(i * 16, j * 16));
        // TODO: Adicionar entidades criadas nas listas (personagens e
        // obstaculos)
        // Talvez armazenar o retorno em uma variavel e inserir na lista
      }
    }
  }

  arquivoMapa.close();

  incluirNoColisor();
}

}  // namespace Fases
