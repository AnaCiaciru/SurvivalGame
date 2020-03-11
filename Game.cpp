#include "Game.h"
#include <ctime>        // time
#include <cstdlib>      // rand, srand
#include <stdlib.h>

/// functie care pe baza lui rand returneaza o valoare random din intervalul [0,i):
int myrandom(int i) { return rand() % i; }

void Game::distribuie_agenti() {

    int i, x, y;

    srand(unsigned(time(0)));

    Agent *b;

    for (i = 0; i < na; i++) {

        /// gasim o pozitie random disponibila
        x = myrandom(15);
        y = myrandom(15);
        while (harta.get_val(x, y) != '0') {
            x = myrandom(15);
            y = myrandom(15);
        }

        /// avem pozitia si acum vedem ce agent putem distribui pe pozitia respectiva

        if (i < 7) {
            /// cream un nou agent
            b = new Horse;
            a.push_back(b);

            /// ocupam pozitia
            harta.set_val(x, y, 'H');

            /// setam datele pentru agentul plasat
            a[i]->set_data(x, y, 0);
        }

        if (i >= 7 && i < 14) {
            /// cream un nou agent
            b = new Donkey;
            a.push_back(b);

            /// ocupam pozitia
            harta.set_val(x, y, 'D');

            /// setam datele pentru agentul plasat
            a[i]->set_data(x, y, 0);
        }

        if (i >= 14) {
            /// cream un nou agent
            b = new Unicorn;
            a.push_back(b);

            /// ocupam pozitia
            harta.set_val(x, y, 'U');

            /// setam datele pentru agentul plasat
            a[i]->set_data(x, y, 0);
        }

    }

}

void Game::distribuie_items() {
    int i, x, y;

    srand(unsigned(time(0)));
    Item *b;

    /// distribuim atatia itemi cati agenti avem *3
    int nr_items = na * 3;

    for (i = 0; i < nr_items; i++) {

        /// gasim o pozitie random disponibila
        x = myrandom(15);
        y = myrandom(15);
        while (harta.get_val(x, y) != '0') {
            x = myrandom(15);
            y = myrandom(15);
        }

        if (i < na) {
            /// cream un nou item
            b = new ItemTip1;

            /// ocupam pozitia
            harta.set_val(x, y, b->get_treasure());

        }

        if (i >= na && i < na * 2) {
            /// cream un nou item
            b = new ItemTip2;

            /// ocupam pozitia
            harta.set_val(x, y, b->get_treasure());
        }

        if (i >= na * 2) {
            /// cream un nou item
            b = new ItemTip3;

            /// ocupam pozitia
            harta.set_val(x, y, b->get_treasure());
        }

    }

}


void Game::runda() {

    vector<Agent *>::iterator it;
    int x1, y1;

    /// parcurgem toti agentii si incercam sa ii mutam
    for (it = a.begin(); it != a.end() && a.size() != 1; ++it) {

        /// daca agentul nu se mai poate misca atunci iese din joc

        /// preluam coord initiale
        int x2 = (*it)->get_x();
        int y2 = (*it)->get_y();

        /// inainte de a face miscarea trebuie sa eliberam zona in care statea agentul
        harta.set_val(x2, y2, '0');

        /// facem miscarea
        (*it)->move();

        /// aflam coordonatele viitoare
        x1 = (*it)->get_x();
        y1 = (*it)->get_y();

        /// daca sunt aceleasi coord ca cele initiale
        if (x1 == x2 && y1 == y2) {
            /// atunci eliminam agentul
            a.erase(it);
            --it;
        } else {
            /// verificam daca e ocupata zona
            char val = harta.get_val(x1, y1);

            /// daca zona nu este libera
            if (val != '0') {

                /// verificam daca avem item
                if (val >= '0' && val <= '9') {

                    /// convertim valoarea item-ului ca sa o adaugam la puterea agentului
                    int val_int = val - '0';

                    /// aplicam item-ul
                    (*it)->app_item(val_int);

                } else {
                    /// in momentul acesta stim sigur ca va avea loc o lupta

                    /// x1 si y1 sunt coordonatele agentului care statea deja pe loc
                    /// acum vedem cine castiga :D
                    int vf = (*it)->fight(a);

                    /// daca a castigat agentul curent
                    if (vf == 1) {
                        /// l-am eliminat pe cel aflat pe pozitie
                        /// puterile sunt modificate

                        /// trebuie modificata valoarea de pe harta acum
                        harta.set_val(x1, y1, (*it)->get_var());

                    } else {

                        /// daca avem egalitate inseamna ca se elibereaza zona
                        if (vf == 0) {
                            harta.set_val(x1, y1, '0');
                        }
                        /// in acest caz nu trebuie sa mai modificam zona
                        /// deoarece a castigat cel care era deja acolo

                        /// oricum ar fi, acum trebuie sa eliminam agentul curent
                        a.erase(it);
                        --it;

                    }

                }

            } else
                /// daca zona e libera, atunci o ocupam
                harta.set_val(x1, y1, (*it)->get_var());
        }

    }

}

void Game::play() {

    cout << "Configuratia initiala a hartii este: " << endl << endl;
    harta.display();

    int i = 1;
    while (a.size() != 1) {
        cout << "Suntem la runda cu numarul " << i << endl << endl;
        i++;
        runda();
        if (a.size() != 1) {
            harta.display();
            cout << "Au mai ramas " << a.size() << " agenti" << endl << endl;

        }

    }

    cout << "Configuratia finala a hartii este: " << endl << endl;
    harta.display();
    cout << "Iar CASTIGATORUL este agentul de pe pozitia (" << a[0]->get_x() << ", " << a[0]->get_y() << ") avand puterea "
         << a[0]->get_power();

}
