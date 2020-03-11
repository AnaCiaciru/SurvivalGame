#include "Item.h"

/// constructorii
ItemTip1::ItemTip1() {
    treasure = '5';
}


ItemTip2::ItemTip2() {
    treasure = '3';
}

ItemTip3::ItemTip3() {
    treasure = '1';
}

/// destructorii
ItemTip1::~ItemTip1() {
    treasure = '0';
}


ItemTip2::~ItemTip2() {
    treasure = '0';
}

ItemTip3::~ItemTip3() {
    treasure = '0';
}

char Item::get_treasure() {
    return treasure;
}
