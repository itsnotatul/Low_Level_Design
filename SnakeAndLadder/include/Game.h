#pragma once
#include "Board.h"
#include "Dice.h"
#include "Player.h"

#include<list>

class Game
{
private:
   Board* board;
   std::list<Player*>playerList;
   Dice* dice;
   Player* winner; 
   
public:
   Game();
   ~Game();
   void initializeGame();
   void addPlayers();
   void startGame();
   Player* findPlayerTurn();
   int jumpCheck (int playerNewPosition); 
};


