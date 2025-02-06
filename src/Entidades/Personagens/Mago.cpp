#include "Entidades/Personagens/Mago.h"

#include <SFML/System/Vector2.hpp>
#include <iostream>

#include "Fabrica/FabricaProjeteis.h"
#include "Fases/Fase.h"
#include "Gerenciadores/GerenciadorColisoes.h"
namespace Entidades::Personagens::Inimigos {

Fabricas::FabricaProjeteis *Mago::fabProj =
    Fabricas::FabricaProjeteis::getInstancia();

Mago::Mago(const sf::Vector2f &pos)
    : Inimigo(ID::IDmago), poder(1.05), bolaDeFogo(nullptr) {
  std::clog << "Criando novo mago\n";

  setTextura("/assets/Personagens/Mago.png");
  pSprite->setTextureRect({16, 16, 16, 16});
  tamanho = {48, 48};
  setPos(pos);
}

Mago::~Mago() { delete bolaDeFogo; }

void Mago::atacar() {
  if (!fabProj) {
    std::cerr << "erro: Mago::atacar() => fabProj == nullptr\n";
    exit(EXIT_FAILURE);
  }
  if (!pFase) {
    std::cerr << "erro: Mago::atacar() => pFase == nullptr\n";
    exit(EXIT_FAILURE);
  }

  // Ataca apenas se a ultima bola de fogo ja colidiu
  if (!bolaDeFogo) {
    bolaDeFogo = fabProj->criarProjetil(this, poder);
    pFase->adicionarProjetil(bolaDeFogo);

    aumentarPoder();
  }
}

void Mago::aumentarPoder() { poder *= poder; }

void Mago::executar() {
  atualizarKnockback();
  setDanificando(false);
  setNoChao(false);

  if (!getNoChao())
    cair();

  perseguir();

  if (getVisando()) {
    atacar();
  }

  mover();

  pGC->notificar(this);

  sf::RectangleShape debugShape(tamanho);
  debugShape.setPosition(pSprite->getPosition());
  debugShape.setFillColor(sf::Color::Transparent);
  debugShape.setOutlineColor(sf::Color::Red);
  debugShape.setOutlineThickness(1);
  pGG->getJanela()->draw(debugShape);
}

} // namespace Entidades::Personagens::Inimigos
