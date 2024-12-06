#include "gerenciadores/gerenciador-grafico.h"

using namespace Gerenciadores;

Gerenciador_Grafico::Gerenciador_Grafico()
    : janela(sf::VideoMode(800, 600), "SFML window") {}

sf::RenderWindow *Gerenciador_Grafico::getJanela() { return &janela; }
