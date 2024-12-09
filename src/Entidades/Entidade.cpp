#include "Entidades/Entidade.h"

using namespace Entidades;

Entidade::Entidade() {}

Entidade::Entidade(sf::Vector2<float> pos, sf::Vector2<float> tamanho,
                   const std::string &path)
    : Ente(path), pos(pos), tamanho(tamanho) {}

Entidade::~Entidade() {}

sf::Vector2<float> Entidade::getPos() const { return pos; }
void Entidade::setPos(sf::Vector2<float> &novaPos) { pos = novaPos; }

void Entidade::salvarDataBuffer() {}
