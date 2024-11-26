#define CATCH_CONFIG_MAIN
#include "../include/Jogo.h"
#include <catch2/catch.hpp>

TEST_CASE("Inicialização do jogo") {
  Jogo jogo;

  SECTION("Jogo ainda não inicializado") { REQUIRE(jogo.isRunning() == false); }

  jogo.Run();

  SECTION("Jogo inicializado") { REQUIRE(jogo.isRunning() == true); }
}
