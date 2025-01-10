#include "Jogador.h"
class Skjolder : public Entidades::Personagens::Jogador {
private:
  float stamina;
  short int furia;

public:
  Skjolder();
  ~Skjolder();
  void atacar();
  void executar();
};
