#include "Map.h"

Map::Map() {
    int i, j;
    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
            m[i].push_back('0');
}

Map::~Map() {
    int i, j;
    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
            m[i].pop_back();
}


void Map::set_val(int x, int y, char val) {
    m[x][y] = val;
}

char Map::get_val(int x, int y) {
    return m[x][y];
}

void Map::display() {
    vector<char>::iterator it;
    int i;

    for (i = 0; i < dim; i++) {
        for (it = m[i].begin(); it != m[i].end(); ++it)
            cout << *it << " ";
        cout << endl;
    }
    cout << endl << "-----------------------------" << endl;
}