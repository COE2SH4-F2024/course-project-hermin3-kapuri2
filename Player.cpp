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

}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
 
}

// More methods to be added