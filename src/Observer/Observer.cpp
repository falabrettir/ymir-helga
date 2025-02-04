#include "Observer.h"
#include "Subject.h"

Observer::Observer() : pSub(nullptr) {}

Observer::~Observer() { pSub = nullptr; }

void Observer::setSub(Subject *pSub) { this->pSub = pSub; }
