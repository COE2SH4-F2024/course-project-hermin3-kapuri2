#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
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
    myPlayer=new Player(myGM);
    myGM = new GameMechs();
}

void GetInput(void)
{
   if(MacUILib_hasChar()!= 0){
        myGM->setInput(MacUILib_getChar());
    }
}

void RunLogic(void)
{
    if(myGM->getInput() != 0)  // if not null character
    {
        if (myGM->getInput() == 8){
            myGM->setExitTrue();
        }
        else if(myGM->getInput() == 'i'){
            myGM->incrementScore();
        }
        else if(myGM->getInput() == 'z'){
            myGM->setLoseFlag();
        }
        
        myGM-> clearInput();
    }
}

void DrawScreen(void)
{
    int i,j;
    objPos playerPos = myPlayer -> getPlayerPos();
    MacUILib_printf("Player[x,y] - [%d, %d], %c",playerPos.pos->x,playerPos.pos->y,playerPos.symbol);

    int const xnum = myGM -> getBoardSizeX();
    int const ynum = myGM -> getBoardSizeY();
    MacUILib_clearScreen();    
    for(j=0;j<ynum;j++){
        for (i=0; i<xnum; i++){
            if (i==0 || i==xnum-1||j==0||j==ynum-1){
                MacUILib_printf ("#");
            }
            // else if (i == getplayerpos.x && j== pos.y){
            //     MacUILib_printf ("%c",pos.symbol);
            // }
            else{
                MacUILib_printf (" ");
            }
        }
        MacUILib_printf ("\n");
    }
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