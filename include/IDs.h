#pragma once

enum class ID {
  unknown = -1,
  IDjogador,            // 0
  IDslime,              // 1
  IDesqueleto,          // 2
  IDmago,               // 3
  IDmadeira1,           // 4
  IDmadeira2,           // 5
  IDpedra,              // 6
  IDgrama,              // 7
  IDfase,               // 8
  IDprojetil,           // 9
  IDgosma,              // 10
  IDespinho,            // 11
  IDbotaonovojogo,      // 12
  IDbotaocarregarjogo,  // 13
  IDbotaocolocacao,     // 14
  IDbotaosair,          // 15
  IDbotaocontinuar,     // 16
  IDmenuprincipal,      // 17
  IDmenuopcao           // 18

};

inline bool ehJogador(ID id) { return id == ID::IDjogador; }

inline bool ehInimigo(ID id) {
  switch (id) {
    case ID::IDslime:
    case ID::IDesqueleto:
    case ID::IDmago:
      return true;

    default:
      return false;
  }
}

inline bool ehPlataforma(ID id) {
  switch (id) {
    case ID::IDgrama:
    case ID::IDpedra:
    case ID::IDmadeira1:
    case ID::IDmadeira2:
      return true;

    default:
      return false;
  }
}

inline bool ehObstaculo(ID id) {
  switch (id) {
    case ID::IDpedra:
    case ID::IDespinho:
    case ID::IDgosma:
    case ID::IDgrama:
    case ID::IDmadeira1:
    case ID::IDmadeira2:
      return true;

    default:
      return false;
  }
}

inline bool ehPersonagem(ID id) {
  switch (id) {
    case ID::IDesqueleto:
    case ID::IDjogador:
    case ID::IDmago:
    case ID::IDslime:
      return true;

    default:
      return false;
  }
}

inline bool ehProjetil(ID id) {
  switch (id) {
    case ID::IDprojetil:
      return true;
    default:
      return false;
  }
}
