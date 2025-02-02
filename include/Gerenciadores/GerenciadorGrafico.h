#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

class Ente;

namespace Gerenciadores {

class GerenciadorGrafico {
 private:
  sf::Font *superPixel;
  sf::RenderWindow *pJanela;
  float alturaJanela;
  float larguraJanela;
  sf::Clock relogio;
  float deltaTempo;
  static GerenciadorGrafico *instancia;

 private:
  GerenciadorGrafico();
  ~GerenciadorGrafico();
  GerenciadorGrafico(const GerenciadorGrafico &) = delete;
  GerenciadorGrafico &operator=(const GerenciadorGrafico &) = delete;

 public:
  static GerenciadorGrafico *getInstancia();
  void carregarFonte(const std::string &path);
  sf::Font *getFonte() const;
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

}  // namespace Gerenciadores
