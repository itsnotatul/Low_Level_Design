#pragma once
#include "Cell.h"
class Board
{
private:
   Cell** cells;
public:
   int boardSize;
public:
    Board(int boardSize, int snakeCnt, int LadderCnt);
    ~Board();
    void initializeCells(int boardSize);
    void addSnakeAndLadder(int boardSize, int snakeCnt, int LadderCnt);
    Cell* getCell(int playerPosition);
};



