#include "Gerenciadores/GerenciadorEventos.h"
#include <catch2/catch.hpp>

using namespace Gerenciadores;

TEST_CASE("Gerenciador de eventos") {
  Gerenciador_Eventos *pGE = Gerenciador_Eventos::getInstancia();

  SECTION("Inicializacao do gerenciador de eventos") {
    REQUIRE(pGE != nullptr);
  }
}
