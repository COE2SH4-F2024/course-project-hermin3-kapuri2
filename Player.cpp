#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.pos->x= mainGameMechsRef -> getBoardSizeX() / 2;
    playerPos.pos->y= mainGameMechsRef -> getBoardSizeY() / 2;
    playerPos.symbol='*';
}


Player::~Player()
{
    // delete any heap members here
    delete playerPos.pos;
    delete mainGameMechsRef;
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;
}

void Player::updatePlayerDir()
{
    char input = mainGameMechsRef->getInput();
    // PPA3 input processing logic   
    if(input != 0)  // if not null character
    {
        switch(input)
        {                      

            case 'w':
            case 'W':
                if (myDir == RIGHT||myDir == LEFT|| myDir == STOP){

                    myDir= UP;
                }
                break;
            case 'a':
            case 'A':
                if (myDir == UP||myDir == DOWN|| myDir == STOP){

                    myDir = LEFT;
                }
                break;
            case 's':
            case 'S':
                if (myDir == RIGHT||myDir == LEFT|| myDir == STOP){

                    myDir = DOWN;
                }
                break;
            case 'd':
            case 'D':
                if (myDir == UP||myDir == DOWN|| myDir == STOP){

                    myDir = RIGHT;
                }
                break;   

            default:
                break;
        }
        input = 0;
    }

}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
 if (myDir == UP){
        playerPos.pos->y = (playerPos.pos->y-1);
        if (playerPos.pos->y == 0){
            playerPos.pos->y = mainGameMechsRef->getBoardSizeY()-2;
        }
    }
    if (myDir == DOWN){
        playerPos.pos->y = (playerPos.pos->y+1);
        if (playerPos.pos->y == mainGameMechsRef->getBoardSizeY()-1){
            playerPos.pos->y = 1;
        }
    }
    if (myDir == RIGHT){
        playerPos.pos->x = (playerPos.pos->x+1);
        if (playerPos.pos->x == mainGameMechsRef->getBoardSizeX()-1){
            playerPos.pos->x = 1;
        }
    }
    if (myDir == LEFT){
        playerPos.pos->x = (playerPos.pos->x-1);
        if (playerPos.pos->x == 0){
            playerPos.pos->x = mainGameMechsRef->getBoardSizeX()-2;
        }
    }
}

// More methods to be added