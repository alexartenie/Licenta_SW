/*===============* Includes *==========================*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <main.h>
#include "stm32f4xx.h"
#include "SSD1963.c"
#include <SD_STM32.c>
#include <LCD_App.c>
#include <ADS7843.c>
#include <touch.c>
#include <OS.c>
#include <main.h>
#include <Inits.c>
#include <Scope.c>
#include <ff.c>
#include <string.h>

unsigned int r=1;
/*=====================================================*/

  
/*==================* Main Function *================*/

int main(void)
{
  //array = (int )0xC0000001;
  //TIM4_init();
  create_task("Blink",0,10,&Blink_task);
  create_task("LCD Update",0,15,&LCD_Refresh_task);
  create_task("ScopeA",0,0,&ScopeAGetData);
 // create_task("Nope",0,0,&Nope_task);
  create_task("TOUCH",0,20,&Check_Touch_task); 
  ImageToWrite = LCD_buff;
   SystemInit();
   
  Device_Init();
    
  char print[30];
   Clean_LCD_Buff();
  FMC_Init();
  Clean_LCD_Buff();
  Activate_Scope();
    
   for(int i=0;i<50;i++)
    ScopeA_buff[i]=i*2;
  for(int i=0;i<50;i++)
    ScopeA_buff[50+i]=(50-i)*2; 
  
  NVIC_init();  
  SysTick_Config(SystemCoreClock / 1000);
  while (1)
    { 
      //CheckTouch();
      wait(100);
      //DMA_Cmd(DMA2_Stream0,ENABLE);
  //  sprintf(print,"FMC%d:%d",0,Scope_Sim[0]);
 // ssd1963_PutText(150,250,print,Black,White);
    }
}

void Blink_task()
{
  GPIO_ToggleBits(LED1_PORT,LED1_PIN);
  //sys_scheduler();
 // GPIO_ToggleBits(TOUCH_CS_PORT,TOUCH_CS_BIT);
}

/*============* ADC ISR *============================*/
void ADC_IRQHandler(void)
{
  if(ADC_GetITStatus(ADC1,ADC_IT_EOC)!=RESET)
    {
      static int R=20;
      ADC_ClearFlag(ADC1,ADC_IT_EOC);
      ADC_ClearITPendingBit(ADC1,ADC_IT_EOC);
      ADC_IRQ();
     // sample_counter++;
      //LCD_Draw_Rectangle(R++,40,20,20,Blue);
      
    }
}

void DMA2_Stream0_IRQHandler()
{
  if(DMA_GetITStatus(DMA2_Stream0,DMA_IT_TCIF0));
     {
       DMA_ClearFlag(DMA2_Stream0,DMA_FLAG_TCIF0);
       DMA_ClearITPendingBit(DMA2_Stream0,DMA_IT_TCIF0);
       //LCD_Draw_Rectangle(20,20,20,20,Green);
       sample_counter+=8;
     }
}

void SysTick_Handler()
{   
    sys_scheduler(); 
}

void LCD_Refresh_task()
{   
  //  GPIO_SetBits(LED1_PORT,LED1_PIN);
     LCD_Refresh();
    // GPIO_ResetBits(LED1_PORT,LED1_PIN);
   //  sys_scheduler();
     // sample_counter=0;
   //}
}

void Nope_task()
{
  ;//Clean_LCD_Buff();
}

void Check_Touch_task()
{
  CheckTouch();
}

void ScopeAGetData()
{
      
  char print[30];
  r++;
  if(r>98)
    r=0;
  static int i;
     i++;
     if(i>98)
       i=0;     
    // for(int i=x_old;i<100;i++)
     
     {
       
      //y=(sample_buff[i]-20)*10;
      y=Scope_Window_dY/2+ScopeA_Offset-ScopeA_buff[i]/2;//-sample_buff[i];     
       x+=1;//Scope_X_Step;
       if(x>Scope_Window_dX-8)
        x=0;
      if(Scope_Autoclear)
        Scope_Clear_Path(x);
      LCD_Draw_Rectangle(x+3,y,Scope_Dot_Size,Scope_Dot_Size,ScopeA_Color);
      if(Scope_Use_Interpolation)
      {
        Draw_Line(x_old,y_old,x,y,ScopeA_Color);
        x_old=x;
        y_old=y;
      }
     }
     
     last_sample_count=sample_counter;
     //sys_scheduler();
}






