#pragma once

namespace Listas {

template <typename TL> class Lista {
private:
  // Classe Elemento aninhada
  template <typename TE> class Elemento {

  private:
    Elemento<TE> *pProx;
    TE *pInfo;

  public:
    Elemento() : pProx(nullptr), pInfo(nullptr) {}
    ~Elemento() {
      pProx = nullptr;
      pInfo = nullptr;
    }
    void incluir(TE *pElem) { pInfo = pElem; }
    void setProx(Elemento<TE> *pElem) { pProx = pElem; }
    Elemento<TE> *getProximo() const { return pProx; }
    TE *getInfo() const { return pInfo; }
  };
  Elemento<TL> *pPrimeiro;
  Elemento<TL> *pUltimo;
  int tamanho;

public:
  Lista();
  ~Lista();

  Elemento<TL> *getpPrimeiro() const {
    if (pPrimeiro)
      return pPrimeiro;
  }
  Elemento<TL> *getpUltimo() const {
    if (pUltimo)
      return pUltimo;
  }

  void incluir(TL *p) {
    Elemento<TL> *node = new Elemento<TL>();
    if (node != nullptr) {
      node->incluir(p);
      if (pUltimo != nullptr) {
        pUltimo->setProx(node);
        pUltimo = node;
      } else {
        pPrimeiro = node;
        pUltimo = node;
      }
      tamanho++;
    }
  }
  void remover(TL *p) {
    Elemento<TL> *node = pPrimeiro;
    Elemento<TL> *anterior = nullptr;
    while (node != nullptr) {
      anterior = node;
      node = node->getProximo();
      if (node->getInfo() == p) {
        if (node == pPrimeiro) {
          pPrimeiro = node->getProximo();
        } else if (node == pUltimo) {
          pUltimo = anterior;
        } else {
          anterior->setProx(node->getProximo());
        }
        delete node;
        tamanho--;
        break;
      }
    }
    node = nullptr;
    anterior = nullptr;
  }
  // TL pop(TL* p);
  void limpar() {
    Elemento<TL> *node = pPrimeiro;
    while (node != nullptr) {
      Elemento<TL> *anterior = node;
      node = node->getProximo();
      delete anterior;
    }
    pUltimo = nullptr;
    tamanho = 0;
  }
  TL *operator[](int pos) {
    Elemento<TL> *aux = pPrimeiro;
    for (int i = 0; i < pos; i++) {
      aux = aux->getProximo();
    }
    return aux->getInfo();
  }
  int getSize() const { return tamanho; }

public:
  class Iterator {
  private:
    Elemento<TL> *pAtual;

  public:
    Iterator() : pAtual(nullptr) {}
    Iterator(Elemento<TL> *pElem) : pAtual(pElem) {}
    ~Iterator() { pAtual = nullptr; }

    Iterator &operator++() {
      if (pAtual) {
        pAtual = pAtual->getProximo();
      }
      return *this;
    }
    Iterator &operator=(Iterator &outro) {
      if (&outro != this) {
        pAtual = outro.pAtual;
      }
      return *this;
    }
    bool &operator!=(const Iterator &outro) const {
      return this->pAtual != outro.pAtual;
    }
  };
  Iterator begin() const { return Iterator(pPrimeiro); }
  Iterator end() const { return Iterator(pUltimo); }
};

} // namespace Listas
