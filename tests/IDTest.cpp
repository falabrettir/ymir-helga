#include <gtest/gtest.h>

#include "IDs.h"

TEST(IDTest, EhJogador) {
  EXPECT_TRUE(ehJogador(ID::IDjogador));
  EXPECT_FALSE(ehJogador(ID::IDslime));
  EXPECT_FALSE(ehJogador(ID::IDesqueleto));
  EXPECT_FALSE(ehJogador(ID::IDmago));
  EXPECT_FALSE(ehJogador(ID::IDmadeira1));
  EXPECT_FALSE(ehJogador(ID::IDmadeira2));
  EXPECT_FALSE(ehJogador(ID::IDpedra));
  EXPECT_FALSE(ehJogador(ID::IDgrama));
  EXPECT_FALSE(ehJogador(ID::IDfase));
  EXPECT_FALSE(ehJogador(ID::IDprojetil));
  EXPECT_FALSE(ehJogador(ID::IDgosma));
  EXPECT_FALSE(ehJogador(ID::IDespinho));
}

TEST(IDTest, EhInimigo) {
  EXPECT_FALSE(ehInimigo(ID::IDjogador));
  EXPECT_TRUE(ehInimigo(ID::IDslime));
  EXPECT_TRUE(ehInimigo(ID::IDesqueleto));
  EXPECT_TRUE(ehInimigo(ID::IDmago));
  EXPECT_FALSE(ehInimigo(ID::IDmadeira1));
  EXPECT_FALSE(ehInimigo(ID::IDmadeira2));
  EXPECT_FALSE(ehInimigo(ID::IDpedra));
  EXPECT_FALSE(ehInimigo(ID::IDgrama));
  EXPECT_FALSE(ehInimigo(ID::IDfase));
  EXPECT_FALSE(ehInimigo(ID::IDprojetil));
  EXPECT_FALSE(ehInimigo(ID::IDgosma));
  EXPECT_FALSE(ehInimigo(ID::IDespinho));
}

TEST(IDTest, EhPlataforma) {
  EXPECT_FALSE(ehPlataforma(ID::IDjogador));
  EXPECT_FALSE(ehPlataforma(ID::IDslime));
  EXPECT_FALSE(ehPlataforma(ID::IDesqueleto));
  EXPECT_FALSE(ehPlataforma(ID::IDmago));
  EXPECT_TRUE(ehPlataforma(ID::IDmadeira1));
  EXPECT_TRUE(ehPlataforma(ID::IDmadeira2));
  EXPECT_TRUE(ehPlataforma(ID::IDpedra));
  EXPECT_FALSE(ehPlataforma(ID::IDgrama));
  EXPECT_FALSE(ehPlataforma(ID::IDfase));
  EXPECT_FALSE(ehPlataforma(ID::IDprojetil));
  EXPECT_FALSE(ehPlataforma(ID::IDgosma));
  EXPECT_FALSE(ehPlataforma(ID::IDespinho));
}
