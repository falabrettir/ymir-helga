#include "Fabrica/FabricaProjeteis.h"

namespace Fabricas {

FabricaProjeteis::FabricaProjeteis() : ativo(true) {}

FabricaProjeteis::~FabricaProjeteis() { ativo = false; }

}  // namespace Fabricas
