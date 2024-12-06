#include "../../include/Ente/Ente.h"

int Ente::cont(0);
Gerenciadores::Gerenciador_Grafico *pGG(NULL);

Ente::Ente() : id(cont++), texture(NULL) {}
Ente::~Ente() {}

void Ente::desenhar() {}
void Ente::executar() {}
