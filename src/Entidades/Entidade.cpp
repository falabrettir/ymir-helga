#include "Entidades/Entidade.h"

using namespace Entidades;

Entidade::Entidade() {}

Entidade::Entidade(sf::Vector2<float> pos, sf::Vector2<float> tamanho,
                   const std::string &path)
    : pos(pos), tamanho(tamanho) {}

Entidade::~Entidade() {}

void Entidade::desenhar() {}
