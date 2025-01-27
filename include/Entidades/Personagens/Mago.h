#include "Entidades/Projetil.h"
#include "Inimigo.h"

namespace Entidades::Personagens::Inimigos {
class Mago : public Inimigo {
private:
  float poder;
  Projetil *bolaDeFogo;

public:
  Mago();
  ~Mago();
  void atacar();
  void executar();
  void aumentarPoder();
};
} // namespace Entidades::Personagens::Inimigos
