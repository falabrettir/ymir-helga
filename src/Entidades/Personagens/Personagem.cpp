#include "Entidades/Personagens/Personagem.h"
#include <SFML/System/Vector2.hpp>

Entidades::Personagens::Personagem::Personagem(const std::string &path)
    : Entidades::Entidade::Entidade((0.0, 0.0), (0.0, 0.0), path) {}
