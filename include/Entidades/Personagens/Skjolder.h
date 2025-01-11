#include "Controladores/ControladorJogador.h"
#include "Jogador.h"

namespace Entidades::Personagens {

class Skjolder : public Entidades::Personagens::Jogador {
private:
  float stamina;
  short int furia;
  Controladores::Controlador_Jogador *pContr;

public:
  Skjolder();
  ~Skjolder();
  Controladores::Controlador_Jogador *getControlador() const;
  void atacar();
  void executar();
};

} // namespace Entidades::Personagens
