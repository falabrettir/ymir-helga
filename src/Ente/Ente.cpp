#include "../../include/Ente/Ente.h"

int Ente::cont(0);
Gerenciadores::Gerenciador_Grafico *pGG(NULL);

Ente::Ente() : id(cont++) {}
Ente::~Ente() {}

void Ente::desenhar() {}
void Ente::executar() {}
