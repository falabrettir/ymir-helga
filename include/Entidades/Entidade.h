#include "Ente.h"
#include <SFML/System/Vector2.hpp>

namespace Entidades {

const float gravidade = 5;

class Entidade : public Ente {
protected:
  sf::Vector2<float> pos;
  sf::Vector2<float> tamanho;
  sf::Vector2<float> velocidade;
  std::ostream *buffer;

public:
  Entidade();
  Entidade(sf::Vector2<float> pos, sf::Vector2<float> tamanho,
           const std::string &path);
  virtual ~Entidade();

  // virtual void executar() = 0;
  // virtual void salvar() = 0;
  sf::Vector2<float> getPos() const;
  void setPos(sf::Vector2<float> &novaPos);
  sf::Vector2<float> getVel() const;
  void setVel(sf::Vector2<float> &novaVel);
  void salvarDataBuffer();
};

} // namespace Entidades
