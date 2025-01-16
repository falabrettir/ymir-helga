#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Personagens/Personagem.h"
#include "Obstaculo.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
namespace Entidades {
namespace Obstaculos {
class Plataforma : public Obstaculo {
private:
  float altura;
  sf::Vector2f empuxo;
  sf::RectangleShape rec;
  bool ehFlutuante;

public:
  Plataforma(const bool ehFlut = false);
  ~Plataforma();
  void executar();
  void obstacular(Entidades::Personagens::Jogador *pJog);
  void colidir(Entidades::Entidade *outraEnt,
               sf::Vector2f ds = sf::Vector2f(0.0f, 0.0f));
};
} // namespace Obstaculos
} // namespace Entidades
