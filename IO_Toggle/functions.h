#ifndef __FUNCTIONS_H
#define __FUNCTIONS_H

/* Includes ******************************************************************/

#include <stdlib.h>
#include "stm32f4xx.h"

/* Defines *******************************************************************/
#define Set_State_LED GPIO_SetBits(GPIOF , GPIO_Pin_6)
#define Reset_State_LED GPIO_ResetBits(GPIOF , GPIO_Pin_6)
/* Function Prototypes *******************************************************/

void uint16tostr(char buf[], uint32_t, uint8_t);
void Led_Port_Config(void);

#endif /* __FUNCTIONS_H */
