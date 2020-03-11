#include "Agent.h"

Agent::Agent() {
    power = 0;
}


Horse::Horse() {
    var = 'H';
}

Donkey::Donkey() {
    var = 'D';
}

Unicorn::Unicorn() {
    var = 'U';
}


void Agent::set_data(int a, int b, int pow) {
    this->x = a;
    this->y = b;
    this->power = pow;
}

void Agent::app_item(int val) {
    power += val;
}

/* cand va fi apelata aceasta functie stim sigur ca
   sunt 2 agenti cu aceleasi coordonate
   functia va returna 1, daca va castiga agentul curent
                      0, daca e egalitate
                      -1, daca va castiga agentul aflat deja pe pozitie

 */
int Agent::fight(vector<Agent *> a) {

    vector<Agent *>::iterator it;

    for (it = a.begin(); it != a.end(); ++it) {
        if ((*it)->x == x && (*it)->y == y && (*it) != this) {
            /// acum ne luptam

            if (power > (*it)->power) {

                /// modificam puterea
                power -= (*it)->power;

                /// il eliminam pe cel aflat pe pozitie
                a.erase(it);
                --it;
                return 1;

            } else {
                /// daca au puterile egale, ii eliminam pe amandoi
                if (power == (*it)->power) {
                    a.erase(it);
                    --it;
                    return 0;
                }

                /// modificam puterea
                (*it)->power -= power;

                /// il vom elimina pe cel curent in functia principala
                return -1;
            }

        }

    }

}


int Agent::get_x() {
    return x;
}

int Agent::get_y() {
    return y;
}

int Agent::get_power() {
    return power;
}

char Agent::get_var() {
    return var;
}


void Horse::move() {
    // coboara pe diagonala
    x--;
    y--;

    int dim = 15;
    if (!(x >= 0 && x < dim && y >= 0 && y < dim)) {
        /// daca iese din mapa revenim la pozitia initiala
        x++;
        y++;
    }

}

void Donkey::move() {
    // se misca in jos
    x++;
    int dim = 15;
    if (!(x >= 0 && x < dim && y >= 0 && y < dim)) {
        /// daca iese din mapa revenim la pozitia initiala
        x--;
    }
}

void Unicorn::move() {
    // se misca spre dreapta
    y++;
    int dim = 15;
    if (!(x >= 0 && x < dim && y >= 0 && y < dim)) {
        /// daca iese din mapa revenim la pozitia initiala
        y--;
    }
}