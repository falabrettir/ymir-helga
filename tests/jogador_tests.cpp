#include "Entidades/Personagens/Skjolder.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include <catch2/catch.hpp>

TEST_CASE("Jogador") {
  Gerenciadores::Gerenciador_Grafico *pGG =
      Gerenciadores::Gerenciador_Grafico::getInstancia();

  Ente::setGerenciadorGrafico(pGG);

  Entidades::Personagens::Skjolder jogador;
}
