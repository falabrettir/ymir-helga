#pragma once
#include "Fases/Fase.h"
#include "Gerenciadores/GerenciadorEstados.h"
#include "Gerenciadores/GerenciadorInput.h"
#include "Observer.h"
class ObservadorFase : public Observer {
 private:
  Fases::Fase* fAtual;
  Gerenciadores::GerenciadorEstados* pGS;
  Gerenciadores::GerenciadorInput* pGI;
  std::map<Key, bool> teclasPressionadas;
  Key pause;

 public:
  ObservadorFase(Fases::Fase* fAtual);
  ~ObservadorFase();
  void notificarFim();
  void atualizarTeclasPressionadas(sf::Keyboard::Key tecla);
  void atualizarTeclasSoltas(sf::Keyboard::Key tecla);
  void notificarJogadorMorreu();
  void pausar();
  bool acharTecla(Key tecla);
  void setTeclas();
  void executar();
};
