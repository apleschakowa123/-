#pragma once
#include "Player.h"

//наблюдатель
class BigTennis: public Observer{
public:
    BigTennis(Player *model, int pos);
    void update(int score, int pos);
};