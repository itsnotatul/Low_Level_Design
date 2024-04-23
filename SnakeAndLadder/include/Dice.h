#pragma once
#include<iostream>

class Dice
{
private:
    int diceCount;
    int min =0,max=6;
public:
    Dice(int diceCount);
    ~Dice();
    int rollDice();
};


