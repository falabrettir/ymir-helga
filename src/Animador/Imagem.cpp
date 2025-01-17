#include "Animador/Imagem.h"

namespace Animador {
Imagem::Imagem(const std::string &path, const unsigned short int qtdImg,
               const float tempoTroca, const sf::Vector2f escala)
    : pGrafico(pGrafico->getInstancia()), qtdImg(qtdImg),
      tempoTroca(tempoTroca), tempoTotal(0.0f), tam(0, 0, 0, 0), imgAtual(0),
      textura(pGrafico->carregarTex(path)), escala(escala) {
  tam.width = textura.getSize().x / (float)qtdImg;
  tam.height = textura.getSize().y;
}
Imagem::~Imagem() {}

void Imagem::atualizar(const bool praEsq, const float dt) {
  tempoTotal = tempoTotal + dt;
  if (tempoTotal >= tempoTroca) {
    tempoTotal -= tempoTroca;
    imgAtual++;
    if (imgAtual >= qtdImg) {
      imgAtual = 0;
    }
  }
  if (praEsq) {
    tam.left = (imgAtual + 1) * abs(tam.width);
    tam.width = -abs(tam.width);

  } else {
    tam.left = imgAtual * tam.width;
    tam.width = abs(tam.width);
  }
}
void Imagem::resetar() {
  imgAtual = 0;
  tempoTotal = 0.f;
}
const sf::IntRect Imagem::getTamanho() const { return tam; }
const sf::Texture *Imagem::getTextura() const { return &textura; }
const sf::Vector2f Imagem::getEscala() const { return escala; }
} // namespace Animador
