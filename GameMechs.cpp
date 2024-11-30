#include "GameMechs.h"
#include "MacUILib.h"
#include "Player.h"
#include <stdlib.h>
#include <cstdlib>

GameMechs::GameMechs()
{
    srand(time(NULL));
    int randX2 = (rand() % (getBoardSizeX ()- 2)) + 1;
    int randY2 = (rand() % (getBoardSizeY() - 2)) + 1;
    input =0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = 20;
    boardSizeY = 10;
    food.setObjPos(3,5, 'o');
    food.setObjPos(randY2,randX2, 'o');
    
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input =0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = boardX;
    boardSizeY = boardY;
    food.setObjPos(5,5, 'o');
    
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
char GameMechs::getInput() const
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

void GameMechs:: generateFood(objPos blockOff){

    Player *myPlayer;
    bool bad= true;
    int randX;
    int randY;
    int xRange = getBoardSizeX();
    int yRange = getBoardSizeY();
    objPos foodPos = getFoodPos();
    objPos playerPos = myPlayer -> getPlayerPos();
    srand(time(NULL));
    // blockOff.pos->x = (rand() % (xRange - 2)) + 1;
    // blockOff.pos->y = (rand() % (yRange - 2)) + 1;
    while (bad == true){
        bad = false;
        randX = (rand() % (xRange - 2)) + 1;
        randY = (rand() % (yRange - 2)) + 1;
        int randX2 = (rand() % (xRange - 2)) + 1;
        int randY2 = (rand() % (yRange - 2)) + 1;
        foodPos.pos->x = randX2;
        foodPos.pos->y = randY2;
        
        if(randX == foodPos.pos->x && randY == foodPos.pos->y||randX == blockOff.pos->x && randY == blockOff.pos->y)
        {
            bad =true;
        }
        if (bad ==false){
            foodPos.pos->x = randX;
            foodPos.pos->y = randY;
        }
        else {
            bad =true;
        }

    }
    // food.setObjPos(foodPos.pos->x,foodPos.pos->y, 'o');
    // food.setObjPos(foodPos.pos->x,foodPos.pos->y, 'o');
    // food.setObjPos(getFoodPos().pos->x,getFoodPos().pos->y, 'o');
}
objPos GameMechs:: getFoodPos() const{
    return food;
}
