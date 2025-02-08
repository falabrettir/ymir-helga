#include "Entidades/Personagens/Personagem.h"

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <cstdlib>
#include <iostream>

#include "Fases/Fase.h"

namespace Entidades::Personagens {

Fases::Fase *Personagem::pFase = nullptr;

Personagem::Personagem(ID id)
    : Entidade(id),
      hp(200),
      dano(10),
      danificando(false),
      emAnimacaoKnockback(false),
      tempoKnockback(0.0f),
      duracaoKnockback(0.5f),
      direcaoKnockback(0.f, 0.f),
      invencivel(false),
      tempoInvencibilidade(0.0f),
      podeAtacar(true),
      ultimoAtaque(0),
      vivo(true) {}

Personagem::~Personagem() {}

void Personagem::setFase(Fases::Fase *fase) {
  if (!fase) {
    std::cerr << "erro: Personagem::setFase(...) => fase == nullptr\n";
    exit(EXIT_FAILURE);
  }
  pFase = fase;
}

void Personagem::tomarDano(int dano, bool esq) {
  hp -= dano;

  if (hp <= 0) {
    vivo = false;
    setPos({-6000, -6000});
  }

  if (!invencivel && !emAnimacaoKnockback && getNoChao()) {
    hp -= dano;

    // Inicia animação de knockback e invencibilidade
    emAnimacaoKnockback = true;
    tempoKnockback = 0.0f;

    // Zera a velocidade atual antes de aplicar o knockback
    setVel({0.f, 0.f});

    // Define a direção do knockback (para trás e para cima)
    direcaoKnockback.x = esq ? -1.0f : 1.0f;

    // Aplica velocidade inicial para criar um arco natural
    sf::Vector2f novaVel;
    novaVel.x = direcaoKnockback.x * 0.5f;  // Velocidade horizontal constante
    novaVel.y = -0.7f;                      // Impulso inicial para cima
    setVel(novaVel);
    setNoChao(false);
  }

  setDanificando(true);
  invencivel = true;
  tempoInvencibilidade = 0.0f;
}

void Personagem::setDano(const int dano) { this->dano = dano; }

const int Personagem::getDano() const { return dano; }
void Personagem::setDanificando(bool danificando) {
  this->danificando = danificando;
}

void Personagem::executar() {
  ultimoAtaque += pGG->getDeltaTempo();
  if (ultimoAtaque > 1000) {
    podeAtacar = true;
    ultimoAtaque = 0;
  }

  if (!vivo) pFase->notificarMorreu(this);
}

const bool Personagem::getDanificando() const { return danificando; }
void Personagem::atualizarKnockback() {
  const float deltaTime = 0.016f;  // Aproximadamente 60 FPS

  // Atualiza invencibilidade
  if (invencivel) {
    tempoInvencibilidade += deltaTime;
    if (tempoInvencibilidade >= DURACAO_INVENCIBILIDADE) {
      invencivel = false;
      tempoInvencibilidade = 0.0f;
    }
  }

  // Atualiza knockback
  if (emAnimacaoKnockback) {
    tempoKnockback += deltaTime;

    // Finaliza o knockback se o tempo acabou ou se tocou o chão
    if (tempoKnockback >= duracaoKnockback || getNoChao()) {
      emAnimacaoKnockback = false;
      setDanificando(false);
      setVel({0.f, 0.f});
    } else {
      // Pega a velocidade atual
      sf::Vector2f vel = getVel();

      // Aplica gravidade para criar o arco
      vel.y += 0.08f;  // Força da gravidade

      // Diminui mais rapidamente a velocidade horizontal (exponencial)
      float t = tempoKnockback / duracaoKnockback;
      vel.x = direcaoKnockback.x * 0.5f *
              std::exp(-4.0f * t);  // Decaimento exponencial mais rápido

      setVel(vel);
    }
  }
}

}  // namespace Entidades::Personagens
