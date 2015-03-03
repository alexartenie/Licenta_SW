#ifndef _Definitions_
#define _Definitions_
#include "Definitions.h"
#endif
#include "main.h"
#define IN 0
#define OUT 1
#define AF 2
#define AN 3

void GPIOD_EnableClock()
{
   RCC->AHB1ENR|=(1<<GPIODEN);
}
void GPIOD_SetPinMode(int PIN/*PIN to configure*/,int MODE/*I_MODE,O_MODE,AF_MODE,AN_MODE*/)
{
  GPIOD->MODER&=~(3<<PIN*2);//Clearing those 2 bits
  GPIOD->MODER|=(MODE<<PIN*2);//Setting those 2 bits according to the mode
}

