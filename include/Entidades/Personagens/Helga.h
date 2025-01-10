#include "Jogador.h"

class Helga : public Entidades::Personagens::Jogador {
private:
  // TODO:
  // Classe projetil
  // Projetil* pFlecha;
  short int numFlechas;

public:
  Helga();
  ~Helga();
  void atacar();
  void executar();
};
