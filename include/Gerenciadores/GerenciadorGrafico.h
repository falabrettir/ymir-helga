#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

const int larguraJanela = 800;
const int alturaJanela = 600;

class Ente;

namespace Gerenciadores {

class Gerenciador_Grafico {
private:
  sf::RenderWindow *janela;
  sf::Clock relogio;
  float deltaTempo;
  static Gerenciador_Grafico *instancia; // Singleton
  Gerenciador_Grafico();

public:
  ~Gerenciador_Grafico();
  static Gerenciador_Grafico *getInstancia(); // Singleton
  sf::RenderWindow *getJanela() const;

  void desenharEnte(Ente *pE);
  bool janelaAberta();
  void display();
  bool pollEvent(sf::Event &evento);
  void clear();
  void fecharJanela();
  void atualizaDeltaTempo();
  const float getDeltaTempo() const;
};

} // namespace Gerenciadores
