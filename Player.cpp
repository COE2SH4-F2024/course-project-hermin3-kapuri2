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
    switch (myDir)
    {
    case LEFT:
        if (input == 'w')
        {
            myDir = UP;
        }
        if (input == 's')
        {
            myDir = DOWN;
        }
        break;
    case RIGHT:
        if (input == 'w')
        {
            myDir = UP;
        }
        if (input == 's')
        {
            myDir = DOWN;
        }
        break;
    case UP:
        if (input == 'a')
        {
            myDir = LEFT;
        }
        if (input == 'd')
        {
            myDir = RIGHT;
        }
        break;
    case DOWN:
        if (input == 'a')
        {
            myDir = LEFT;
        }
        if (input == 'd')
        {
            myDir = RIGHT;
        }
        break;

    default:
        if (input == 'a')
        {
            myDir = LEFT;
        }
        if (input == 'd')
        {
            myDir = RIGHT;
        }
        if (input == 'w')
        {
            myDir = UP;
        }
        if (input == 's')
        {
            myDir = DOWN;
        }
        break;
    }

}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
}

// More methods to be added