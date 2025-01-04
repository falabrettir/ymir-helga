#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

class Ente;

namespace Gerenciadores {

class Gerenciador_Grafico {
private:
  sf::RenderWindow *janela;
  float alturaJanela;
  float larguraJanela;
  sf::Clock relogio;
  float deltaTempo;
  static Gerenciador_Grafico *instancia;

private:
  Gerenciador_Grafico();
  ~Gerenciador_Grafico();
  Gerenciador_Grafico(const Gerenciador_Grafico &) = delete;
  Gerenciador_Grafico &operator=(const Gerenciador_Grafico &) = delete;

public:
  static Gerenciador_Grafico *getInstancia();
  sf::RenderWindow *getJanela() const;
  void desenharEnte(Ente *pE);
  bool janelaAberta();
  void display();
  void clear();
  void fecharJanela();
  void atualizaDeltaTempo();
  const float getDeltaTempo() const;
  const float getLarguraJanela() const;
  const float getAlturaJanela() const;
};

} // namespace Gerenciadores
