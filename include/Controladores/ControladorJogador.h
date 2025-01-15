#pragma once

#include "Gerenciadores/GerenciadorInput.h"
#include "Observer.h"
#include <SFML/Window/Keyboard.hpp>

typedef sf::Keyboard::Key Key;

namespace Entidades::Personagens {
class Jogador;
} // namespace Entidades::Personagens

namespace Controladores {

class Controlador_Jogador : public Observer {
private:
  Entidades::Personagens::Jogador *pJog;
  std::map<Key, bool> teclasPressionadas;
  Key direita;
  Key esquerda;
  Key pulo;
  Key ataque;

public:
  Controlador_Jogador();
  ~Controlador_Jogador();

  void setJog(Entidades::Personagens::Jogador *pJog);

  // Funcao para diferenciar os controles do jogador2
  void setControles();

  // Retorna true se a tecla esta no map 'teclasPressionadas'
  bool acharTecla(Key tecla);

  void atualizarTeclasPressionadas(Key tecla);
  void atualizarTeclasSoltas(Key tecla);
  void controlarJogador();
};

} // namespace Controladores
