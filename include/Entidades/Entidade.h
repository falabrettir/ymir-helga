#include "Ente.h"
#include <SFML/System/Vector2.hpp>

namespace Entidades {

class Entidade : public Ente {
protected:
  sf::Vector2<float> pos;
  sf::Vector2<float> tamanho;

public:
  Entidade();
  Entidade(sf::Vector2<float> pos, sf::Vector2<float> tamanho,
           const std::string &path);
  virtual ~Entidade();
  virtual void desenhar();
  void salvarDataBuffer();
  virtual void executar() = 0;
};

} // namespace Entidades
