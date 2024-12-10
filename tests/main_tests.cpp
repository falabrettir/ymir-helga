// #define CATCH_CONFIG_MAIN
// #include "Jogo.h"
// #include "catch2/catch.hpp"
//
// TEST_CASE("Singleton instance creation and validity") {
//   // Ensure the singleton instance is created
//   Gerenciadores::Gerenciador_Grafico *instance1 =
//       Gerenciadores::Gerenciador_Grafico::getInstancia();
//   REQUIRE(instance1 != nullptr);
//
//   // Ensure calling getInstancia() again returns the same instance
//   Gerenciadores::Gerenciador_Grafico *instance2 =
//       Gerenciadores::Gerenciador_Grafico::getInstancia();
//   REQUIRE(instance1 == instance2);
// }
//
// TEST_CASE("Window creation and properties") {
//   Gerenciadores::Gerenciador_Grafico *grafico =
//       Gerenciadores::Gerenciador_Grafico::getInstancia();
//
//   // Ensure the window is created
//   sf::RenderWindow *janela = grafico->getJanela();
//   REQUIRE(janela != nullptr);
//
//   // Check if the window is open
//   REQUIRE(janela->isOpen() == true);
//
//   // Check if vertical sync is enabled (requires specific context settings)
//   // This cannot be directly tested; assume it's set correctly.
// }
//
// TEST_CASE("Window event polling") {
//   Gerenciadores::Gerenciador_Grafico *grafico =
//       Gerenciadores::Gerenciador_Grafico::getInstancia();
//   sf::Event event;
//
//   // Polling an event from a freshly created window should return false
//   REQUIRE(grafico->pollEvent(event) == false);
//
//   // Note: Further tests for event polling require mocking or manual event
//   // generation.
// }
//
// TEST_CASE("Display and clear functions") {
//   Gerenciadores::Gerenciador_Grafico *grafico =
//       Gerenciadores::Gerenciador_Grafico::getInstancia();
//
//   // Ensure the clear function can be called without issues
//   REQUIRE_NOTHROW(grafico->clear());
//
//   // Ensure the display function can be called without issues
//   REQUIRE_NOTHROW(grafico->display());
// }
//
// TEST_CASE("Close window functionality") {
//   Gerenciadores::Gerenciador_Grafico *grafico =
//       Gerenciadores::Gerenciador_Grafico::getInstancia();
//
//   // Close the window
//   REQUIRE_NOTHROW(grafico->fecharJanela());
//
//   // Ensure the window is no longer open
//   REQUIRE(grafico->getJanela()->isOpen() == false);
// }
//
// TEST_CASE("Draw Ente") {
//   Gerenciadores::Gerenciador_Grafico *grafico =
//       Gerenciadores::Gerenciador_Grafico::getInstancia();
//
//   // Create an Ente instance
//   Ente ente("resources/test_texture.png");
//
//   // Set GerenciadorGrafico instance
//   Ente::setGerenciadorGrafico(grafico);
//
//   // Draw Ente and ensure it does not throw
//   REQUIRE_NOTHROW(grafico->desenharEnte(&ente));
//
//   // Validate sprite assignment (basic check)
//   const sf::Sprite *sprite = ente.getSprite();
//   REQUIRE(sprite != nullptr);
//   REQUIRE(sprite->getTexture() != nullptr);
// }
//
// TEST_CASE("Ente texture loading") {
//   Ente ente;
//
//   // Ensure texture loading works for valid file
//   REQUIRE(ente.setTexture("resources/test_texture.png") == true);
//
//   // Ensure texture loading fails for invalid file
//   REQUIRE(ente.setTexture("invalid/path.png") == false);
// }
