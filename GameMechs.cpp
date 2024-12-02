#include "GameMechs.h"
#include "MacUILib.h"
#include "Player.h"
#include <stdlib.h>
#include <cstdlib>

GameMechs::GameMechs()
{
    int randX2 = (rand() % (18)) + 1;
    int randY2 = (rand() % (8)) + 1;
    input =0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = 20;
    boardSizeY = 10;
    // foodPos.pos->x = 0;
    // foodPos.pos->y = 0;
    // foodPos.symbol = 'z';
    // //food.setObjPos(3,5, 'o');
    foodPos.setObjPos(getFoodPos().pos->x,getFoodPos().pos->y, 'z');
    
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input =0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = boardX;
    boardSizeY = boardY;
    foodPos.setObjPos(5,5, 'o');
    
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    
void GameMechs::collectAsyncInput(){
    if(MacUILib_hasChar()!= 0){
        input = MacUILib_getChar();
    }
    if(input == 8) exitFlag = true;
}
char GameMechs::getInput() 
{
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input =0;
}

// More methods should be added here

void GameMechs:: generateFood(objPosArrayList* blockOff){

    int xRange = getBoardSizeX();
    int yRange = getBoardSizeY();
    bool bad;

    srand(time(NULL)); 

    do {
        bad = false;

        
        int randX = (rand() % (xRange - 2)) + 1; 
        int randY = (rand() % (yRange - 2)) + 1;

       
        for (int i = 0; i < blockOff->getSize(); i++) {
            objPos ThisSeg = blockOff->getElement(i);
            if (randX == ThisSeg.pos->x && randY == ThisSeg.pos->y) {
                bad = true;
                break;
            }
        }

       
        if (bad== false) {
            foodPos.setObjPos(randX, randY, 'o'); 
        }

    } while (bad== true); 
}
        
objPos GameMechs:: getFoodPos() const{
    return foodPos;
}