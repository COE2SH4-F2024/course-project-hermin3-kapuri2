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
            case 8:  // exit with backspace
                exitFlag = 1;
                break;

            case 'w':
            case 'W':
                if (direction == RIGHT||direction == LEFT|| direction == STOP){

                    direction = UP;
                }
                break;
            case 'a':
            case 'A':
                if (direction == UP||direction == DOWN|| direction == STOP){

                    direction = LEFT;
                }
                break;
            case 's':
            case 'S':
                if (direction == RIGHT||direction == LEFT|| direction == STOP){

                    direction = DOWN;
                }
                break;
            case 'd':
            case 'D':
                if (direction == UP||direction == DOWN|| direction == STOP){

                    direction = RIGHT;
                }
                break;   
            case '1':
                speed = 225000;
                break;
            case '2':
                speed = 175000;
                break;
            case '3':
                speed = 125000;
                break;
            case '4':
                speed = 100000;
                break;
            case '5':
                speed = 75000;
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
 if (direction == UP){
        object.y = (object.y-1);
        if (object.y == 0){
            object.y = 8;
        }
    }
    if (direction == DOWN){
        object.y = (object.y+1);
        if (object.y == 9){
            object.y = 1;
        }
    }
    if (direction == RIGHT){
        object.x = (object.x+1);
        if (object.x == 19){
            object.x = 1;
        }
    }
    if (direction == LEFT){
        object.x = (object.x-1);
        if (object.x == 0){
            object.x = 18;
        }
    }
}

// More methods to be added