#include "Game.h"

int main() {
    Game x;

    /// pregatim harta
    x.distribuie_agenti();
    x.distribuie_items();

    /// dam drumul la joc
    x.play();
    return 0;
}