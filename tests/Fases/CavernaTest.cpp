#include <gtest/gtest.h>

#include <SFML/System/Vector2.hpp>

#include "Fases/Caverna.h"

class CavernaTest : public ::testing::Test, public Fases::Caverna {
 protected:
  Fases::Caverna* caverna;

  void SetUp() override { caverna = new Fases::Caverna(); }

  void TearDown() override { delete caverna; }
};

TEST_F(CavernaTest, ConstructorTest) { ASSERT_NE(caverna, nullptr); }

TEST_F(CavernaTest, CriarEntidadeTest) {
  sf::Vector2f pos(100.0f, 100.0f);
  caverna->criarEntidade('S', pos);
  ASSERT_EQ(getContSlimes(), 1);

  caverna->criarEntidade('E', pos);
  ASSERT_EQ(getContEsqueletos(), 1);
}

TEST_F(CavernaTest, CriarSlimeTest) {
  sf::Vector2f pos(100.0f, 100.0f);
  caverna->criarSlime(pos);
  ASSERT_EQ(getContSlimes(), 1);
}

TEST_F(CavernaTest, CriarPedraTest) {
  sf::Vector2f pos(100.0f, 100.0f);
  caverna->criarPedra(pos);
  // Add assertions to check if the pedra was created correctly
}

TEST_F(CavernaTest, CriarMadeiraTest) {
  sf::Vector2f pos(100.0f, 100.0f);
  caverna->criarMadeira(pos);
  // Add assertions to check if the madeira was created correctly
}

TEST_F(CavernaTest, CriarGosmaTest) {
  sf::Vector2f pos(100.0f, 100.0f);
  caverna->criarGosma(pos);
  // Add assertions to check if the gosma was created correctly
}
