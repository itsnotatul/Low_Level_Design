#include "../include/Player.h"
#include<iostream>

Player::Player(int id, int pos): PlayerId(id),currentPosition(pos){
 std::cout<<" Player Object CREATED"<<std::endl;
}


Player::~Player(){
 std::cout<<" Player Object DESTROYED"<<std::endl;
}