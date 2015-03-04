/*===============* Includes *==========================*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <main.h>
#include "stm32f4xx.h"
#include "SSD1963.c"
#include <LCD_App.c>
#include <ADS7843.c>
#include <touch.c>
#include <OS.c>
#include <main.h>
#include <Inits.c>
#include <Scope.c>
//#include "ff.c"
//#include "diskio.c"
//#include "spi.c"
/*=====================================================*/

/*==================* Main Function *================*/
int Scope_Sim[100];
int main(void)
{
  
  //TIM4_init();
  create_task("Blink",0,100,&Blink_task);
  create_task("LCD Update",0,100,&LCD_Refresh_task);
  create_task("Nope",0,0,&Nope_task);
  create_task("TOUCH",0,20,&Check_Touch_task); 
  
  for(int i=0;i<50;i++)
    Scope_Sim[i]=i*2;
  for(int i=0;i<50;i++)
    Scope_Sim[50+i]=(50-i)*2;
  SystemInit();
  Device_Init();
  Activate_Scope();
  FMC_Init();  
  
  NVIC_init();  
  SysTick_Config(SystemCoreClock / 1000);
  while (1)
    { 
      //CheckTouch();
      wait(1000);
      //DMA_Cmd(DMA2_Stream0,ENABLE);
    
    }
}

void Blink_task()
{
  GPIO_ToggleBits(LED1_PORT,LED1_PIN);
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
  char print[20];
  
  //LCD_Draw_Rectangle(last_sample_count,40,20,20,Yellow);
  // if(last_sample_count<sample_counter)
   //{
     static int i;
     i++;
     if(i>99)
       i=0; 
    // for(int i=x_old;i<100;i++)
     {
       
      //y=(sample_buff[i]-20)*10;
      y=Scope_Window_dY/2+ScopeA_Offset-Scope_Sim[i]/2;//-sample_buff[i];     
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
     // sample_counter=0;
   //}
  
    /*
    sprintf(print,"Ticks:%d",last_sample_count);
    ssd1963_PutText(20,200,print,Black,White);
    sprintf(print,"Ticks:%d",sample_counter);
    ssd1963_PutText(20,220,print,Black,White);
   */
}

void Nope_task()
{
  ;
}

void Check_Touch_task()
{
  CheckTouch();
}








