#include "../../include/Ente/Ente.h"

int Entes::Ente::cont(0);
Gerenciadores::Gerenciador_Grafico *pGG(NULL);

Entes::Ente::Ente() : id(cont++) {}
Entes::Ente::~Ente() {}
