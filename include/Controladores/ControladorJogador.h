#pragma once

#include "Gerenciadores/GerenciadorInput.h"
#include "Observer.h"
#include <SFML/Window/Keyboard.hpp>
#include <set>
#include <utility>

namespace Entidades {
namespace Personagens {
class Jogador;
} // namespace Personagens
} // namespace Entidades

namespace Controladores {

class Controlador_Jogador : public Observer {
private:
  Entidades::Personagens::Jogador *pJog;
  Gerenciadores::Gerenciador_Input *pGI;
  std::set<std::pair<sf::Keyboard::Key, bool>> teclasPressionadas;

public:
  Controlador_Jogador();
  ~Controlador_Jogador();

  void setJog(Entidades::Personagens::Jogador *pJog);
  void setGI(Gerenciadores::Gerenciador_Input *pGI);

  void atualizarTeclasPressionadas(sf::Keyboard::Key tecla);
  void atualizarTeclasSoltas(sf::Keyboard::Key tecla);
};

} // namespace Controladores
