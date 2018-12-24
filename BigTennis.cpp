#include "BigTennis.h"
#include <iostream>

BigTennis::BigTennis(Player *model, int pos){
    model->replace(this, pos);
}

void BigTennis::update(int score, int pos){
   std::cout << "Позиция: "<< pos;
   std::cout << "\nОчки: " << score;
}