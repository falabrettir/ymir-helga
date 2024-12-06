#pragma once

class Jogo {
private:
  bool rodando;

public:
  Jogo();
  ~Jogo();
  void executar();
  bool estaRodando() const;
};
