#include "Entidades/Obstaculos/Plataforma.h"
#include "Entidades/Personagens/Jogador.h"
#include <SFML/System/Vector2.hpp>
namespace Entidades {
namespace Obstaculos {
Plataforma::Plataforma(const bool ehFlut)
    : Obstaculo(), altura(540.f), ehFlutuante(ehFlut), empuxo(0.f, 0.f) {}
Plataforma::~Plataforma() {}
void Plataforma::executar() {}
void Plataforma::obstacular(Entidades::Personagens::Jogador *pJog) {}
void Plataforma::colidir(Entidades::Entidade *outraEnt, sf::Vector2<float> ds) {
}

} // namespace Obstaculos
} // namespace Entidades
