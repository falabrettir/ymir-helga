#include <gtest/gtest.h>

#include "Jogo.h"

class JogoTest : public testing::Test {
 protected:
  Jogo* jogo;

  void SetUp() override { jogo = new Jogo(); }

  void TearDown() override { delete jogo; }
};

TEST_F(JogoTest, ConstructorTest) { ASSERT_NE(jogo, nullptr); }

TEST_F(JogoTest, AtualizarTest) {
  // Assuming atualizar() modifies some state, you should check that state here.
  // For example:
  // jogo->atualizar();
  // ASSERT_EQ(expected_state, jogo->getState());
}

TEST_F(JogoTest, ExecutarTest) {
  // Assuming executar() runs the game loop or similar, you should check the effects here.
  // For example:
  // jogo->executar();
  // ASSERT_EQ(expected_result, jogo->getResult());
}
