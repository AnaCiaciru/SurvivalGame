#ifndef P1_MAP_H
#define P1_MAP_H

#include <iostream>
#include <map>

#include "Agent.h"

class Map {

    map<int, vector<char> > m; // harta
    const int dim = 15; // dimensiunea hartii
public:
    Map();

    ~Map();

    void set_val(int x, int y, char val);

    char get_val(int x, int y);

    void display();
};


#endif //P1_MAP_H
