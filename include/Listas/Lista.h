#pragma once

namespace Listas {

template <class TL> class Lista {
public:
  // Classe Elemento aninhada
  template <class TE> class Elemento {
  private:
    Elemento<TE> *pProx;
    TE *pInfo;

  public:
    Elemento() : pProx(nullptr), pInfo(nullptr) {}
    Elemento(TE *info) : pInfo(info), pProx(nullptr) {}
    ~Elemento() {
      pProx = nullptr;
      pInfo = nullptr;
    }
    void incluir(TE *pElem) { pInfo = pElem; }
    void setProx(Elemento<TE> *pElem) { pProx = pElem; }
    Elemento<TE> *getProximo() const { return pProx; }
    TE *getInfo() const { return pInfo; }
  };

private:
  Elemento<TL> *pPrimeiro;
  Elemento<TL> *pUltimo;
  int tamanho;

public:
  Lista() : pPrimeiro(nullptr), pUltimo(nullptr), tamanho(0) {}

  ~Lista() { limpar(); }

  Elemento<TL> *getpPrimeiro() const {
    if (pPrimeiro)
      return pPrimeiro;
  }

  Elemento<TL> *getpUltimo() const {
    if (pUltimo)
      return pUltimo;
  }

  void incluir(TL *p) {
    if (p != nullptr) {
      Elemento<TL> *node = new Elemento<TL>();
      if (node != nullptr) {
        node->incluir(p);
        if (pPrimeiro == nullptr) {
          pPrimeiro = node;
          pUltimo = node;
        } else {
          pUltimo->setProx(node);
          pUltimo = node;
        }
        tamanho++;
      }
    }
  }

  void remover(TL *p) {
    Elemento<TL> *node = pPrimeiro;
    Elemento<TL> *anterior = nullptr;
    while (node != nullptr && node->getInfo() != p) {
      anterior = node;
      node = node->getProximo();
    }
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
    }
    node = nullptr;
    anterior = nullptr;
  }

  // TL pop(TL* p);
  void limpar() {
    Elemento<TL> *node = pPrimeiro;
    while (node != nullptr) {
      pPrimeiro = pPrimeiro->getProximo();
      delete node;
      node = pPrimeiro;
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

    TL *operator*() { return pAtual->getInfo(); }

    Iterator &operator++() {
      if (pAtual) {
        pAtual = pAtual->getProximo();
      }
      return *this;
    }

    Iterator &operator=(const Iterator &outro) {
      if (&outro != this) {
        this->pAtual = outro.pAtual;
      }
      return *this;
    }

    bool operator!=(const Iterator &outro) const {
      return this->pAtual != outro.pAtual;
    }

    friend class Lista;
  };

  Iterator begin() { return Iterator(pPrimeiro); }

  Iterator end() { return Iterator(nullptr); }
};

} // namespace Listas
