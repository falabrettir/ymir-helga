#include "../include/Jogo.h"

Jogo::Jogo() : running(false) {}

Jogo::~Jogo() {}

void Jogo::Run() { running = true; }

bool Jogo::isRunning() const { return running; }
