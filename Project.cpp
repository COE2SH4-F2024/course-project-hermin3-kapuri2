#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs *myGM;

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
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
    int i,j;
    exitFlag = false;
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    int i,j;
    MacUILib_clearScreen();    
    for(j=0;j<10;j++){
        for (i=0; i<20; i++){
            if (i==0 || i==19||j==0||j==9){
                MacUILib_printf ("#");
            }
            // else if (i == pos.x && j== pos.y){
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
    MacUILib_clearScreen();    

    MacUILib_uninit();
}
