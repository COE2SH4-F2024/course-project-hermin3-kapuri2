#include "Player.h"
#include "objPosArrayList.h"

// after step 2. after we insert a new position to the head of the list check whether the new position consumes food. if it doesnt, remove the tail. if it does, keep the tail

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    playerPosList = new objPosArrayList();
    myDir = STOP;

    objPos headPos(thisGMRef->getBoardSizeX()/2, thisGMRef->getBoardSizeY()/2, '*');

    playerPosList->insertHead(headPos);

    // more actions to be included
    // playerPos.pos->x= mainGameMechsRef -> getBoardSizeX() / 2;
    // playerPos.pos->y= mainGameMechsRef -> getBoardSizeY() / 2;
    // playerPos.symbol = '*';
}


Player::~Player()
{
    // delete any heap members here
    //delete playerPos.pos;
    delete mainGameMechsRef;
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    //returning the reference to the player objPos array list
    return playerPosList;
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

// (up here) create a temp objpos to calculate the new head position. probably should get the head element of the playerposlist as a good starting point
objPos temp = playerPosList -> getHeadElement();
// (down in the if statement) calculate the new position of the head using the temp objpos

    // PPA3 Finite State Machine logic
 if (myDir == UP){  
        temp.pos->y = (temp.pos->y-1);
        if (temp.pos->y == 0){
            temp.pos->y = mainGameMechsRef->getBoardSizeY()-2;
        }
    }
    if (myDir == DOWN){
        temp.pos->y = (temp.pos->y+1);
        if (temp.pos->y == mainGameMechsRef->getBoardSizeY()-1){
            temp.pos->y = 1;
        }
    }
    if (myDir == RIGHT){
        temp.pos->x = (temp.pos->x+1);
        if (temp.pos->x == mainGameMechsRef->getBoardSizeX()-1){
            temp.pos->x = 1;
        }
    }
    if (myDir == LEFT){
        temp.pos->x = (temp.pos->x-1);
        if (temp.pos->x == 0){
            temp.pos->x = mainGameMechsRef->getBoardSizeX()-2;
        }
    }
    // insert temp objpos to the head of the list
    playerPosList -> insertHead(temp);
    playerPosList -> removeTail();


    //(later, like 3b): check if the new temp objpos overlaps w the food pos (get it from gamemech class)
    //use is poition equal method from objpos class
    //if overlap, food consumed. do not remove tail. then take the respective actions to increase the score 
    // if no overlap, remove tail complete movement
}

// More methods to be added