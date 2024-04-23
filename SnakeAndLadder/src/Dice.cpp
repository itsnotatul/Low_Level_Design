#include "../include/Dice.h"
#include<iostream>
#include<stdio.h>
#include<time.h>

Dice::Dice(int diceCount): diceCount(diceCount){
 std::cout<<" Dice Object CREATED"<<std::endl;
}


Dice::~Dice(){
 std::cout<<" Dice Object DESTROYED"<<std::endl;
}

int Dice::rollDice(){
    int diceUsed =0;
    int totalSum =0;
    srand(time(nullptr));
    while(diceUsed < diceCount){
        totalSum += rand()%6+1;
        diceUsed++;
    }
    return totalSum;
}