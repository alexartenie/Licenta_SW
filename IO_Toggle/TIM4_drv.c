#ifndef _Definitions_
  #define _Definitions_
  #include "Definitions.h"
#endif
#include "main.h"
#define FRZ 0
#define ALM 1
#define ILM 2
#define TGL 3
#define FIL 4
#define FAL 5
#define PWM1 6
#define PWM2 7
void TIM4_setPWM(int channel,float dutycicle)
{
  switch(channel)
  {
  case 1 : {TIM4->CCR1=(dutycicle*TIM4->ARR)/100;break;}
  case 2 : {TIM4->CCR2=dutycicle/100*TIM4->ARR;break;}
  case 3 : {TIM4->CCR3=dutycicle/100*TIM4->ARR;break;}
  case 4 : {TIM4->CCR4=dutycicle/100*TIM4->ARR;break;}            
  }
}

void TIM4_EnableClock()
{
  RCC->APB1ENR|=(1<<TIM4EN);//Enable clock to TIM4
}

void TIM4_EnableOC(int Channel)
{
  TIM4->CCER|=(1<<(Channel-1)*4);
}

void TIM4_SetOCMode(int Channel,int Mode)
{
   switch(Channel)
   {
   case 1 : {TIM4->CCMR1&=~(3<<4); TIM4->CCMR1|=(Mode<<4);break;}
   case 2 : {TIM4->CCMR1&=~(3<<12);TIM4->CCMR1|=(Mode<<12);break;}
   case 3 : {TIM4->CCMR2&=~(3<<4);TIM4->CCMR2|=(Mode<<4);break;}
   case 4 : {TIM4->CCMR2&=~(3<<12);TIM4->CCMR2|=(Mode<<12);break;}
   }
}

void TIM4_SetPSC(int PSC)
{
  TIM4->PSC=PSC;
}

void TIM4_SetReloadValue(int RLDV)
{
  TIM4->ARR=RLDV;
}

void TIM4_EnableCNT()
{
  TIM4->CR1|=(1<<CEN);
}






