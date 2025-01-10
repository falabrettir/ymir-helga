#include "Controladores/ControladorJogador.h"
#include "Jogador.h"
class Skjolder : public Entidades::Personagens::Jogador {
private:
  float stamina;
  short int furia;
  Controladores::Controlador_Jogador *pCont;

public:
  Skjolder();
  ~Skjolder();
  Controladores::Controlador_Jogador *getControlador() const;
  void atacar();
  void executar();
};
