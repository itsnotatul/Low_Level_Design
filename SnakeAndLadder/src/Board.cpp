#include "../include/Board.h"
#include<iostream>
#include<stdio.h>
#include<time.h>

Board::Board(int boardSize, int snakeCnt, int LadderCnt ): boardSize
(boardSize){
 std::cout<<" Board Object CREATED"<<std::endl;
  initializeCells(boardSize);
  addSnakeAndLadder(boardSize,snakeCnt,LadderCnt);  
}


Board::~Board(){
 std::cout<<" Board Object DESTROYED"<<std::endl;
 for(int i=0;i<boardSize;i++){
    delete []cells[i];
 }
 delete [] cells;
}

void Board::initializeCells(int boardSize){
    cells = new Cell*[boardSize];
    for(int i=0;i<boardSize;i++){
        cells[i] = new Cell[boardSize];
        for(int j=0;j<boardSize;j++){
            cells[i][j].jump =  new Jump();
        }
    }
    // std::cout<<"checkpoint"<<std::endl;s
}

void Board::addSnakeAndLadder(int boardSize, int snakeCnt,int LadderCnt){
    srand(time(nullptr));
        while(snakeCnt > 0){
            int head = rand()%(boardSize*boardSize-1)+1;
            int tail = rand()%(boardSize*boardSize-1)+1;

            if(tail >= head) continue;
            // std::cout<<head<<" "<<tail<<std::endl;
            getCell(head)->jump->start = head;
             getCell(head)->jump->end = tail;
            snakeCnt--;
        }
//  std::cout<<"checkpoint2"<<std::endl;
         while(LadderCnt > 0){
            int head = rand()%(boardSize*boardSize-1)+1;
            int tail = rand()%(boardSize*boardSize-1)+1;

            if(tail <= head) continue;

            getCell(head)->jump->start = head;
            getCell(head)->jump->end = tail;
            LadderCnt--;
        }
}

Cell* Board::getCell(int playerPosition){
    if (playerPosition < 0 || playerPosition >= boardSize * boardSize) {
            throw std::out_of_range("Player position is out of the board's range.");
        }
    return &cells[playerPosition/boardSize][playerPosition%boardSize];
}