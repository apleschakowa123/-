#pragma once
#include "Player.h"

//�����������
class BigTennis: public Observer{
public:
    BigTennis(Player *model, int pos);
    void update(int score, int pos);
};