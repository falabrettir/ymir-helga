#pragma once

namespace Listas {

template <typename TE> class Elemento {
private:
  Elemento<TE> *pProx;
  TE *pInfo;

public:
  Elemento();
  ~Elemento();

  void incluir(TE *p);
  void setProx(Elemento<TE> *pE);
  const Elemento<TE> *getProximo();
};

} // namespace Listas
