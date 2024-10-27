#include "../include/Jogo.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Game initialization", "[game]") {
  Jogo jogo;
  REQUIRE(jogo.isRunning() == false);
}
