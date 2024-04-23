#include "../include/Game.h"
#include<iostream>

Game::Game(){
 std::cout<<" Game Object CREATED"<<std::endl;
 initializeGame();
}


Game::~Game(){
 std::cout<<" Game Object DESTROYED"<<std::endl;
 delete board;
 delete dice;
 while(!playerList.empty()){
    auto p = playerList.front();
    playerList.pop_front();
    delete p;
 }
}

void Game::initializeGame(){
    board = new Board(10,5,4);
    dice = new Dice(1);
    winner = nullptr;
    addPlayers();
}

void Game::addPlayers(){
    Player* p1 = new Player(1,0);
    Player* p2 = new Player(2,0);
    playerList.push_back(p1);
    playerList.push_back(p2);

}

void Game::startGame(){
    while(winner == nullptr){
         Player* playerTurn = findPlayerTurn();

            //roll the dice
            int diceNumbers = dice->rollDice();

            //get the new position
            int playerNewPosition = playerTurn->currentPosition + diceNumbers;
            playerNewPosition = jumpCheck(playerNewPosition);
            playerTurn->currentPosition = playerNewPosition;

            std::cout<<"player turn is:" + std::to_string(playerTurn->PlayerId) + " new Position is: " + std::to_string(playerNewPosition)<<std::endl;
            //check for winning condition
            if(playerNewPosition >= (board->boardSize * board->boardSize-1)){

                winner = playerTurn;
            }

        }

       std::cout<<"WINNER IS:" + std::to_string(winner->PlayerId)<<std::endl;

}

Player* Game::findPlayerTurn(){
    Player* playerTurns = playerList.front();
    playerList.pop_front();
    playerList.push_back(playerTurns);
    return playerTurns;

}

int Game::jumpCheck (int playerNewPosition) {

        if(playerNewPosition > (board->boardSize * board->boardSize-1) ){
            return playerNewPosition;
        }

        Cell* cell = board->getCell(playerNewPosition);
        if(cell->jump != nullptr && cell->jump->start == playerNewPosition) {
            // String jumpBy = (cell.jump.start < cell.jump.end)? "ladder" : "snake";
            // System.out.println("jump done by: " + jumpBy);
            return cell->jump->end;
        }
        return playerNewPosition;
    }
