#ifndef P1_GAME_H
#define P1_GAME_H

/// in Agent.h avem:
/* #include <vector>
    using namespace std;
*/

#include "Map.h"
#include "Agent.h"
#include "Item.h"

class Game {

    int na = 21; // nr-ul de agenti
    /// numarul de agenti il folosim numai la generare
    /// in rest vom utiliza size()

    vector<Agent *> a;
    Map harta;

public:
    void distribuie_items();

    void distribuie_agenti();

    void runda(); /// se vor misca toti agenti
    void play(); /// vor fi parcurse toate rundele

};


#endif //P1_GAME_H
