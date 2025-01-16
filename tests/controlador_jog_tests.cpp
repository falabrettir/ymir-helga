#include "Controladores/ControladorJogador.h"
#include "Entidades/Personagens/Skjolder.h"
#include <SFML/Window/Keyboard.hpp>
#include <catch2/catch.hpp>

TEST_CASE("ControladorJogador Testes") {
  Entidades::Personagens::Skjolder jogador;
  Controladores::Controlador_Jogador *controlador = jogador.getControlador();

  SECTION("TestSetControles") {
    controlador->setControles();
    REQUIRE(controlador->acharTecla(sf::Keyboard::D));
    REQUIRE(controlador->acharTecla(sf::Keyboard::A));
    REQUIRE(controlador->acharTecla(sf::Keyboard::W));
    REQUIRE(controlador->acharTecla(sf::Keyboard::Space));
  }

  SECTION("TestControlarJogador") {
    controlador->atualizarTeclasPressionadas(sf::Keyboard::D);
    controlador->controlarJogador();
    REQUIRE(jogador.getVel().x > 0);

    controlador->atualizarTeclasPressionadas(sf::Keyboard::A);
    controlador->controlarJogador();
    REQUIRE(jogador.getVel().x < 0);

    controlador->atualizarTeclasSoltas(sf::Keyboard::A);
    controlador->controlarJogador();
    REQUIRE(jogador.getVel().x == 0);

    controlador->atualizarTeclasPressionadas(sf::Keyboard::W);
    controlador->controlarJogador();
    REQUIRE(jogador.getVel().y < 0);
  }
}
