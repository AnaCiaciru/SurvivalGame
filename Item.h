#ifndef P1_ITEM_H
#define P1_ITEM_H


class Item {

protected:
    char treasure; // comoara
public:
    char get_treasure();
};


class ItemTip1 : public Item {

public:
    /// creste puterea agentului cu 5p
    ItemTip1();

    ~ItemTip1();
};

class ItemTip2 : public Item {

public:
    /// creste puterea agentului cu 3p
    ItemTip2();

    ~ItemTip2();
};

class ItemTip3 : public Item {

public:
    /// creste puterea agentului cu 1p
    ItemTip3();

    ~ItemTip3();
};

#endif //P1_ITEM_H
