#include "functions.h"

void uint16tostr(char buf[], uint32_t d, uint8_t base);

void uint16tostr(char buf[], uint32_t d, uint8_t base)
{
    uint32_t div = 1;
    uint8_t index = 0;
    while (d/div >= base) div *= base;
    while (div != 0)
    {
            uint32_t num = d/div;
            d = d%div;
            div /= base;
            if (num > 9)
                    buf[index] = (num-10) + 65;
            else
                    buf[index] = num + 48;
            index++;
    }
    buf[index] = 0;	// end of string
}

void Led_Port_Config(void)
{
	// State LED on pin PF6 for the HY Core 407z board
  GPIO_InitTypeDef GPIO_LED_Structure; 
  // Enable GPIOs clock //
  RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOF , ENABLE);
	//-- GPIO Configuration ------------------------------------------------------//
  GPIO_LED_Structure.GPIO_Pin = GPIO_Pin_6;
  GPIO_LED_Structure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_LED_Structure.GPIO_OType = GPIO_OType_PP;
  GPIO_LED_Structure.GPIO_PuPd  = GPIO_PuPd_UP;
  GPIO_LED_Structure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOF, &GPIO_LED_Structure); 
}

