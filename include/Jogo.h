#pragma once
#include <SFML/Graphics.hpp>

class Jogo {
private:
  bool running;

public:
  Jogo();
  ~Jogo();
  void Run();
  bool isRunning() const;
};
