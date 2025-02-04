#include "Entidades/Personagens/Helga.h"
#include "Entidades/Personagens/Skjolder.h"
#include "Gerenciadores/GerenciadorInput.h"
#include <catch2/catch.hpp>

using namespace Gerenciadores;

TEST_CASE("Gerenciador input") {
  Gerenciador_Input *pGI = Gerenciador_Input::getInstancia();

  SECTION("Metodo getInstancia() retorna ponteiro valido") {
    REQUIRE(pGI != nullptr);
  }

  SECTION("Interface de Subject") {
    Entidades::Personagens::Skjolder *pJog =
        new Entidades::Personagens::Skjolder();

    Entidades::Personagens::Helga *pHelga = new Entidades::Personagens::Helga();

    SECTION("Lista de observadores deve ser inicializada como nullptr") {
      REQUIRE(pGI->observadores == nullptr);
    }

    SECTION("Inscrever/desinscrever observador na lista") {
      pGI->inscrever(static_cast<Observer *>(pJog->getControlador()));

      REQUIRE(pGI->observadores != nullptr);
      REQUIRE(pGI->observadores->size() == 1);

      pGI->inscrever(static_cast<Observer *>(pHelga->getControlador()));

      REQUIRE(pGI->observadores->size() == 2);

      pGI->desinscrever(static_cast<Observer *>(pJog->getControlador()));
      REQUIRE(pGI->observadores->size() == 1);

      pGI->desinscrever(static_cast<Observer *>(pHelga->getControlador()));
      REQUIRE(pGI->observadores->size() == 0);
    }
  }
}
