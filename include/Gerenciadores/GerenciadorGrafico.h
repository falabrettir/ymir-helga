#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Event.hpp>

class Ente;

namespace Gerenciadores {

class Gerenciador_Grafico {
private:
  sf::RenderWindow *janela;
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
};

} // namespace Gerenciadores
