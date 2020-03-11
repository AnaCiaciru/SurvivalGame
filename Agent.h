#ifndef P1_AGENT_H
#define P1_AGENT_H

#include <vector>

using namespace std;

class Agent {

protected:
    int x, y; // coordonatele la care se afla pe harta
    int power; // puterea agentului
    char var; // varianta agentului

public:
    Agent();
    void set_data(int a, int b, int pow);
    void app_item(int val);
    int fight(vector <Agent *> a);
    int get_x();
    int get_y();
    int get_power();
    char get_var();
    virtual void move()=0;
};



class Horse: public Agent{

public:
    Horse();
    void move();
};

class Donkey: public Agent{

public:
    Donkey();
    void move();
};

class Unicorn: public Agent{

public:
    Unicorn();
    void move();
};


#endif //P1_AGENT_H
