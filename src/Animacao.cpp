#include "Animacao.h"
#include "Entidades/Personagens/Personagem.h"
#include <SFML/Graphics/Texture.hpp>
namespace Animacoes {
Animador::Animador(Entidades::Personagens::Personagem *pPers)
    : pPers(pPers), mapText(), atual(""), relogio() {
  mapText.clear();
}
Animador::~Animador() {}

void Animador::addAnim() {}

void Animador::animar(const bool praEsq) {}

} // namespace Animacoes
