#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include <time.h>
#include <stdlib.h>
using namespace std;

#define DELAY_CONST 100000
GameMechs *myGM;
Player *myPlayer;


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() ==false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    myGM = new GameMechs();
    myPlayer=new Player(myGM);
    myGM -> generateFood(myPlayer->getPlayerPos());
    
}

void GetInput(void)
{
   myGM -> collectAsyncInput();
}

void RunLogic(void)
{
    
    if (myGM->getInput() == 'p'){
        myGM->generateFood(myPlayer->getPlayerPos());
    }
    // else if(myGM->getInput() == 'i'){
    //     myGM->incrementScore();
    // }
    // else if(myGM->getInput() == 'z'){
    //     myGM->setLoseFlag();
    // }
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    myGM-> clearInput();

}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    int i,j;
    
    objPosArrayList* playerPos = myPlayer -> getPlayerPos();
    int playerSize = playerPos->getSize();
    objPos food = myGM -> getFoodPos();
    int const xnum = myGM -> getBoardSizeX();
    int const ynum = myGM -> getBoardSizeY();   
    for(j=0;j<ynum;j++){
        for (i=0; i<xnum; i++){
            // we now need to iterate thru the playerpos array list to print the whole list
            for(int k=0; k< playerSize; k++){
                objPos thisSeg = playerPos-> getElement(k);
                // check if the current segment x, y pos matches the (i,j) coord. if yes, print the symbol.

                // watch out we need to skip the if else clock below if we have printed something in the for loop (need bool and continue)
            }
            // do smth here to determine whether to continue with the if else or to move on to the next iteration of i-j
            if (i==0 || i==xnum-1||j==0||j==ynum-1){
                MacUILib_printf ("#");
            }
            // else if (i == playerPos.pos->x && j == playerPos.pos->y){
            //     MacUILib_printf("%c", playerPos.getSymbol());
            // }
            else if ( i == food.pos->x && j == food.pos->y){
                MacUILib_printf("%c", food.symbol);
            }
            else{
                MacUILib_printf (" ");// this might mess it up
            }
        }
        MacUILib_printf ("\n");

    }
    //foodPos.setObjPos(foodPos.pos->x,foodPos.pos->y, 'o');
    // MacUILib_printf("Player[x,y] - [%d, %d] , %c",playerPos.pos->x,playerPos.pos->y,playerPos.symbol);
    // MacUILib_printf("Player[x,y] - [%d, %d] %d, %d",food.pos->x, food.pos->y, xnum, ynum);
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    myGM->clearInput();
    MacUILib_clearScreen();   
    if (myGM-> getLoseFlagStatus() == true){
        MacUILib_printf("Snake ran into itself. Game Over.");
    } 
    else{
        MacUILib_printf("YOU WIN!");
    }
    delete myPlayer;

    delete myGM;
    MacUILib_uninit();
}