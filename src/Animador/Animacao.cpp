#include "Animador/Animacao.h"
namespace Animador {
Animacao::Animacao(sf::RectangleShape *corpo)
    : corpo(corpo), mapImagem(), imgAtual(""), relogio() {}
Animacao::~Animacao() {
  std::map<std::string, Imagem *>::iterator it = mapImagem.begin();
  while (it != mapImagem.end()) {
    if (it->second) {
      delete (it->second);
      it->second = nullptr;
    }
    it++;
  }
  mapImagem.clear();
}

} // namespace Animador
