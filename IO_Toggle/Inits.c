#include <main.h>
#define ADC1_DR    (0x4001204C)

/*=============* Delay Function *================*/
void wait(int time)
{
  for(int i=0;i<time;i++)
    for(int j=0;j<time;j++);
}

/*=================* GPIO Init *================*/
void GPIO_init()
{
  GPIO_InitTypeDef GPIO_InitStructure;
  
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|
                         RCC_AHB1Periph_GPIOB|
                         RCC_AHB1Periph_GPIOC|
                         RCC_AHB1Periph_GPIOD|
                         RCC_AHB1Periph_GPIOE|
                         RCC_AHB1Periph_GPIOF|
                         RCC_AHB1Periph_GPIOG,ENABLE);

  /* Init GPIO for Scope ADC Inputs */
#if(USE_SCOPE)
  
  #if(USE_SCOPE_A)
    GPIO_InitStructure.GPIO_Pin=ScopeA_PIN;
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AIN;
    GPIO_Init(ScopeA_PORT, &GPIO_InitStructure);  
  #endif
  #if(USE_SCOPE_B)
    GPIO_InitStructure.GPIO_Pin=ScopeB_PIN;
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AIN;
    GPIO_Init(ScopeB_PORT, &GPIO_InitStructure);  
  #endif  
#endif


  /* Init GPIO for LEDs */
#if(USE_LEDS)
  GPIO_InitStructure.GPIO_Pin = LED1_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Init(LED1_PORT, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = LED2_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Init(LED2_PORT, &GPIO_InitStructure); 
  
  GPIO_InitStructure.GPIO_Pin = LED3_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Init(LED3_PORT, &GPIO_InitStructure); 
#endif
  
  /*Init GPIO for LCD*/
#if(USE_LCD)
  GPIO_InitStructure.GPIO_Pin=LCD_DATA_PIN_DB0;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Init(LCD_DATA_PORT_DB0, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin=LCD_DATA_PIN_DB1;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Init(LCD_DATA_PORT_DB1, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin=LCD_DATA_PIN_DB2;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Init(LCD_DATA_PORT_DB2, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin=LCD_DATA_PIN_DB3;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Init(LCD_DATA_PORT_DB3, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin=LCD_DATA_PIN_DB4;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Init(LCD_DATA_PORT_DB4, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin=LCD_DATA_PIN_DB5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Init(LCD_DATA_PORT_DB5, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin=LCD_DATA_PIN_DB6;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Init(LCD_DATA_PORT_DB6, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin=LCD_DATA_PIN_DB7;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Init(LCD_DATA_PORT_DB7, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin=LCD_DATA_PIN_DB8;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Init(LCD_DATA_PORT_DB8, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin=LCD_DATA_PIN_DB9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Init(LCD_DATA_PORT_DB9, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin=LCD_DATA_PIN_DB10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Init(LCD_DATA_PORT_DB10, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin=LCD_DATA_PIN_DB11;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Init(LCD_DATA_PORT_DB11, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin=LCD_DATA_PIN_DB12;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Init(LCD_DATA_PORT_DB12, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin=LCD_DATA_PIN_DB13;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Init(LCD_DATA_PORT_DB13, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin=LCD_DATA_PIN_DB14;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Init(LCD_DATA_PORT_DB14, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin=LCD_DATA_PIN_DB15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Init(LCD_DATA_PORT_DB15, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin=LCD_CTRL_PIN_RST;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Init(LCD_CTRL_PORT_RST, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin=LCD_CTRL_PIN_RD;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Init(LCD_CTRL_PORT_RD, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin=LCD_CTRL_PIN_WR;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Init(LCD_CTRL_PORT_WR, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin=LCD_CTRL_PIN_CS;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Init(LCD_CTRL_PORT_CS, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin=LCD_CTRL_PIN_RS;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Init(LCD_CTRL_PORT_RS, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin=LCD_CTRL_PIN_LEDA;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Init(LCD_CTRL_PORT_LEDA, &GPIO_InitStructure);
#endif
  
  /*Init Touch*/
#if(USE_TOUCH) 
  GPIO_InitStructure.GPIO_Pin=TOUCH_CS_BIT;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Init(TOUCH_CS_PORT, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin=TOUCH_INT_BIT;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_Init(TOUCH_INT_PORT, &GPIO_InitStructure);
    
  GPIO_InitStructure.GPIO_Pin=TOUCH_SCK_BIT;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_Init(TOUCH_SCK_PORT, &GPIO_InitStructure);  
  
  GPIO_InitStructure.GPIO_Pin=TOUCH_MOSI_BIT;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_Init(TOUCH_MOSI_PORT, &GPIO_InitStructure);  
  
  GPIO_InitStructure.GPIO_Pin=TOUCH_MISO_BIT;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_Init(TOUCH_MISO_PORT, &GPIO_InitStructure); 
  
  GPIO_PinAFConfig(TOUCH_SCK_PORT,TOUCH_SCK_PinSource,TOUCH_GPIO_AF);
  GPIO_PinAFConfig(TOUCH_MOSI_PORT,TOUCH_MOSI_PinSource,TOUCH_GPIO_AF);
  GPIO_PinAFConfig(TOUCH_MISO_PORT,TOUCH_MISO_PinSource,TOUCH_GPIO_AF);
#endif
  
#if(USE_FMC)
  /*Init FMC*/
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;       //FMC SDnWE
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource0, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2;       //FMC SDnE0
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource2, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3;       //FMC SDnSCKE0
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource3, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;       //FMC D2
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource0, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1;       //FMC D3
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource1, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;       //FMC D13
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource8, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;       //FMC D14
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource9, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;       //FMC D15
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource10, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_14;       //FMC D0
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_15;       //FMC D1
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_15;       //FMC SDnCAS
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOG, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOG, GPIO_PinSource15, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;       //FMC SDCLK
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOG, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOG, GPIO_PinSource8, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;       //FMC BA1
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOG, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOG, GPIO_PinSource5, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4;       //FMC BA0
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOG, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOG, GPIO_PinSource4, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2;       //FMC A12
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOG, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOG, GPIO_PinSource2, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1;       //FMC A11
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOG, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOG, GPIO_PinSource1, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;       //FMC A10
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOG, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOG, GPIO_PinSource0, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_15;       //FMC A9
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOF, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOF, GPIO_PinSource15, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_14;       //FMC A8
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOF, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOF, GPIO_PinSource14, GPIO_AF_FMC);
  
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_13;       //FMC A7
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOF, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOF, GPIO_PinSource13, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12;       //FMC A6
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOF, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOF, GPIO_PinSource12, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_11;       //FMC SDnRAS
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOF, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOF, GPIO_PinSource11, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;       //FMC A5
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOF, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOF, GPIO_PinSource5, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4;       //FMC A4
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOF, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOF, GPIO_PinSource4, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3;       //FMC A3
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOF, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOF, GPIO_PinSource3, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2;       //FMC A2
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOF, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOF, GPIO_PinSource2, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1;       //FMC A1
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOF, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOF, GPIO_PinSource1, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;       //FMC A0
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOF, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOF, GPIO_PinSource0, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_15;       //FMC D12
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource15, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_14;       //FMC D11
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource14, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_13;       //FMC D10
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource13, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12;       //FMC D9
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource12, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_11;       //FMC D8
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource11, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;       //FMC D7
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource10, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;       //FMC D6
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource9, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;       //FMC D5
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource8, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_7;       //FMC D4
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource7, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1;       //FMC nBL1
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource1, GPIO_AF_FMC);
  
  GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;       //FMC nBL0
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOE, &GPIO_InitStructure);
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource0, GPIO_AF_FMC);
#endif 
  /*Init GPIO for LCD SDCARD*/
#if(USE_LCD_SD)
   GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
   GPIO_Init(GPIOD, &GPIO_InitStructure);
#endif
  
}

/*=============* Init ADC for Scope *==================*/
void Scope_ADC_init()
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);
  
  ADC_InitTypeDef ADC_InitStructure;
  
  ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_Rising;
  ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
  ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T2_TRGO;
  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
  ADC_InitStructure.ADC_NbrOfConversion = 1;
  
  ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 1, ADC_SampleTime_3Cycles);
  if(Active_Scope_Channels==2)
  {
    ADC_InitStructure.ADC_NbrOfConversion = 2;
    ADC_RegularChannelConfig(ADC1, ADC_Channel_12, 2, ADC_SampleTime_3Cycles);
    ADC_InitStructure.ADC_ScanConvMode=ENABLE;
  }
  else
  {
    ADC_InitStructure.ADC_ScanConvMode=DISABLE;
  }
  ADC_Init(ADC1, &ADC_InitStructure);
  ADC_ITConfig(ADC1,ADC_IT_EOC,ENABLE);  
 // ADC_DMARequestAfterLastTransferCmd(ADC1,ENABLE);
  //ADC_MultiModeDMARequestAfterLastTransferCmd(ENABLE);
  
  ADC_Cmd(ADC1, ENABLE);  
  
}
int buff[100];
/*==============* DMA Initialization *===================*/
void DMA_init()
{
  
  //enable DMA1 clock
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2,ENABLE);  
  DMA_DeInit(DMA2_Stream0);
  //create DMA structure
  DMA_InitTypeDef  DMA_InitStructure;
  DMA_InitStructure.DMA_Channel = DMA_Channel_0;
  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)(&ADC1->DR);
  DMA_InitStructure.DMA_Memory0BaseAddr =(uint32_t)(&buff);
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory ;
  DMA_InitStructure.DMA_BufferSize = 100;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;
  DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_1QuarterFull;
  DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
  DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
  
  DMA_Init(DMA2_Stream0,&DMA_InitStructure);
  
  
  //ADC_DMACmd(ADC1,ENABLE);
  
  DMA_ITConfig(DMA2_Stream0,DMA_IT_TC,ENABLE);
  DMA_Cmd(DMA2_Stream0,ENABLE);
  ADC_DMACmd(ADC1, ENABLE);
/*  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1,ENABLE);
  DMA_InitTypeDef  DMA_InitStructure;
  DMA_DeInit(DMA1_Stream0);
  DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
  DMA_InitStructure.DMA_BufferSize = 10;
  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)ADC1_DR;
  DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)ADC_values;
  DMA_Init(DMA1_Stream0, &DMA_InitStructure);
  DMA_ITConfig(DMA1_Stream0, DMA_IT_TC, ENABLE);
  DMA_Cmd(DMA1_Stream0, ENABLE);  */
}

/*=============* Initilize Needed Interrupts *==============*/
void NVIC_init()
{
    NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = DMA2_Stream0_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    //NVIC_EnableIRQ(ADC_IRQn);
     //NVIC_EnableIRQ(DMA2_Stream0_IRQn);
}

/*=========* Timer for Scope ADC Trig *============*/
void TIM_ScopeTrig_init(int freq)
{
  /* Enable Clock to the Scope Timer */
  if(Scope_TIM==TIM2)
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE); 
  else if(Scope_TIM==TIM3)
          ;
   
  /* Initialize Scope Timer */
   TIM_TimeBaseInitTypeDef timerInitStructure;
   
   timerInitStructure.TIM_Prescaler = 0;
   timerInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
   timerInitStructure.TIM_Period = (84000000/freq - 1)*Clock_Calibration;
   timerInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
   timerInitStructure.TIM_RepetitionCounter = 0;
   TIM_TimeBaseInit(Scope_TIM, &timerInitStructure);
  
   TIM_Cmd(Scope_TIM, ENABLE); 
   TIM_SelectOutputTrigger(Scope_TIM,TIM_TRGOSource_Update);
}

void TOUCH_SPI_Init()
{
  static int initiated;
 // if(initiated=0)
  {
    initiated=1;
    RCC_APB1PeriphClockCmd(TOUCH_SPI_CLOCK, ENABLE);
    
    SPI_InitTypeDef SPI_InitStruct;
    
    SPI_InitStruct.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
    SPI_InitStruct.SPI_Mode = SPI_Mode_Master;
    SPI_InitStruct.SPI_DataSize = SPI_DataSize_8b;
    SPI_InitStruct.SPI_CPOL = SPI_CPOL_Low;
    SPI_InitStruct.SPI_CPHA = SPI_CPHA_1Edge;
    SPI_InitStruct.SPI_NSS = SPI_NSS_Soft;
    SPI_InitStruct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;
    SPI_InitStruct.SPI_FirstBit = SPI_FirstBit_LSB;    
    
    SPI_Init(TOUCH_SPI,&SPI_InitStruct);
    
    SPI_Cmd(TOUCH_SPI,ENABLE);
  }
}

void LCD_Init()
{
#if(USE_LCD)
  {
  //Initializarea LCD Display-ului
    ssd1963_Initialization();
    // Clear LCD
    ssd1963_Clear(Black);
   // Draw_Image(100,100,96,96,GFX_pika2,0);
   // Menu_Enter();
  }
#endif
}

void PWM_init()
{
  TIM_TypeDef TIM_cfg;
  TIM_TimeBaseInitTypeDef TIM_tmbase;
  
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
  
  TIM_tmbase.TIM_Prescaler=100;//1
  TIM_tmbase.TIM_CounterMode=TIM_CounterMode_Up;
  TIM_tmbase.TIM_Period=1000;//13400;
  TIM_tmbase.TIM_ClockDivision=TIM_CKD_DIV1;
  TIM_TimeBaseInit(TIM4,&TIM_tmbase);
  TIM_Cmd(TIM4,ENABLE);
  
  TIM_OCInitTypeDef TIM_OC = {0,};
  TIM_OC.TIM_OCMode=TIM_OCMode_PWM1;
  //TIM_OC.TIM_Pulse=200;
  TIM_OC.TIM_OutputState=TIM_OutputState_Enable;
  TIM_OC.TIM_OCPolarity=TIM_OCPolarity_High;
  TIM_OC1Init(TIM4,&TIM_OC);
  TIM_OC1PreloadConfig(TIM4,TIM_OCPreload_Enable);
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_TIM4);
}

void TIM4_init()
{
  TIM_TypeDef TIM_cfg;
  TIM_TimeBaseInitTypeDef TIM_tmbase;
  
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
  
  TIM_tmbase.TIM_Prescaler=8000;//1
  TIM_tmbase.TIM_CounterMode=TIM_CounterMode_Up;
  TIM_tmbase.TIM_Period=1000;//13400;
  TIM_tmbase.TIM_ClockDivision=TIM_CKD_DIV1;
  TIM_TimeBaseInit(TIM4,&TIM_tmbase);
  TIM_Cmd(TIM4,ENABLE);
  
  TIM_OCInitTypeDef TIM_OC = {0,};
  TIM_OC.TIM_OCMode=TIM_OCMode_PWM1;
  TIM_OC.TIM_Pulse=200;
  TIM_OC.TIM_OutputState=TIM_OutputState_Enable;
  TIM_OC.TIM_OCPolarity=TIM_OCPolarity_High;
  TIM_OC1Init(TIM4,&TIM_OC);
  TIM_OC1PreloadConfig(TIM4,TIM_OCPreload_Enable);
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_TIM4);
}

void PWM_Config(int dc)
{
  TIM_SetCompare1(TIM4,dc);
}

void Device_Init()
{
  GPIO_init();  
  //DMA_init();
#if(USE_SCOPE)
  /*Scope_X_Step=(Scope_Sample_Period*Scope_Grid)/ScopeA_Time_Scale;
  Scope_Active=0;
  CAN_Active=0;
  AWG_Active=0;
  for(int i=0;i<100;i++)
    sample_buff[i]=0;*/
#endif  
  
#if(USE_LCD)
  LCD_Init();  
#endif

#if(USE_TOUCH)
  TOUCH_SPI_Init();
#endif
  //PWM_Config(500); 
  
}

void FMC_Init()
{
  uint32_t timeout = SDRAM_TIMEOUT;
  RCC_AHB3PeriphClockCmd(RCC_AHB3Periph_FMC, ENABLE);
  
  FMC_SDRAMTimingInitTypeDef FMC_SDRAMTimingInit;
  FMC_SDRAMTimingInit.FMC_LoadToActiveDelay = 2;
  FMC_SDRAMTimingInit.FMC_ExitSelfRefreshDelay = 7;
  FMC_SDRAMTimingInit.FMC_SelfRefreshTime = 4;
  FMC_SDRAMTimingInit.FMC_RowCycleDelay = 7;
  FMC_SDRAMTimingInit.FMC_WriteRecoveryTime = 2;
  FMC_SDRAMTimingInit.FMC_RPDelay = 2;
  FMC_SDRAMTimingInit.FMC_RCDDelay = 2;  
  
  FMC_SDRAMInitTypeDef  FMC_SDRAMInitStructure;
  FMC_SDRAMInitStructure.FMC_Bank = FMC_Bank1_SDRAM;
  FMC_SDRAMInitStructure.FMC_ColumnBitsNumber = FMC_ColumnBits_Number_9b;
  FMC_SDRAMInitStructure.FMC_RowBitsNumber = FMC_RowBits_Number_13b;
  FMC_SDRAMInitStructure.FMC_SDMemoryDataWidth = FMC_SDMemory_Width_16b;
  FMC_SDRAMInitStructure.FMC_InternalBankNumber = FMC_InternalBank_Number_4;
  FMC_SDRAMInitStructure.FMC_CASLatency = FMC_CAS_Latency_3;
  FMC_SDRAMInitStructure.FMC_WriteProtection = FMC_Write_Protection_Disable;
  FMC_SDRAMInitStructure.FMC_SDClockPeriod = FMC_SDClock_Period_2;
  FMC_SDRAMInitStructure.FMC_ReadBurst = FMC_Read_Burst_Disable;
  FMC_SDRAMInitStructure.FMC_ReadPipeDelay = FMC_ReadPipe_Delay_1;
  FMC_SDRAMInitStructure.FMC_SDRAMTimingStruct = &FMC_SDRAMTimingInit;
  
  FMC_SDRAMInit(&FMC_SDRAMInitStructure);
  
  FMC_SDRAMCommandTypeDef  FMC_SDRAMCommandStructure;  
  FMC_SDRAMCommandStructure.FMC_CommandMode = FMC_Command_Mode_CLK_Enabled;
  FMC_SDRAMCommandStructure.FMC_CommandTarget = FMC_Command_Target_bank1;
  FMC_SDRAMCommandStructure.FMC_AutoRefreshNumber = 1;
  FMC_SDRAMCommandStructure.FMC_ModeRegisterDefinition = 0;
 
  /* Wait until the SDRAM controller is ready */ 
	timeout = SDRAM_TIMEOUT;
	while (FMC_GetFlagStatus(FMC_Bank1_SDRAM, FMC_FLAG_Busy) != RESET && timeout--);
	/* Send the command */
	FMC_SDRAMCmdConfig(&FMC_SDRAMCommandStructure);
        
  /* Configure a PALL (precharge all) command */ 
	FMC_SDRAMCommandStructure.FMC_CommandMode            = FMC_Command_Mode_PALL;
	FMC_SDRAMCommandStructure.FMC_CommandTarget          = FMC_Command_Target_bank1;
	FMC_SDRAMCommandStructure.FMC_AutoRefreshNumber      = 1;
	FMC_SDRAMCommandStructure.FMC_ModeRegisterDefinition = 0;
        
  /* Wait until the SDRAM controller is ready */  
	timeout = SDRAM_TIMEOUT;
	while (FMC_GetFlagStatus(FMC_Bank1_SDRAM, FMC_FLAG_Busy) && timeout--);
	/* Send the command */
	FMC_SDRAMCmdConfig(&FMC_SDRAMCommandStructure);
        
  /* Configure a Auto-Refresh command */ 
	FMC_SDRAMCommandStructure.FMC_CommandMode            = FMC_Command_Mode_AutoRefresh;
	FMC_SDRAMCommandStructure.FMC_CommandTarget          = FMC_Command_Target_bank1;
	FMC_SDRAMCommandStructure.FMC_AutoRefreshNumber      = 8;
	FMC_SDRAMCommandStructure.FMC_ModeRegisterDefinition = 0;
	
	/* Wait until the SDRAM controller is ready */
	timeout = SDRAM_TIMEOUT;
	while (FMC_GetFlagStatus(FMC_Bank1_SDRAM, FMC_FLAG_Busy) && timeout--);
	/* Send the command */
	FMC_SDRAMCmdConfig(&FMC_SDRAMCommandStructure);
  
  /* Configure a load Mode register command */
	FMC_SDRAMCommandStructure.FMC_CommandMode            = FMC_Command_Mode_LoadMode;
	FMC_SDRAMCommandStructure.FMC_CommandTarget          = FMC_Command_Target_bank1;
	FMC_SDRAMCommandStructure.FMC_AutoRefreshNumber      = 1;
	FMC_SDRAMCommandStructure.FMC_ModeRegisterDefinition = 0x0231;
	
	/* Wait until the SDRAM controller is ready */
	timeout = SDRAM_TIMEOUT;
	while (FMC_GetFlagStatus(FMC_Bank1_SDRAM, FMC_FLAG_Busy) && timeout--);
	/* Send the command */
	FMC_SDRAMCmdConfig(&FMC_SDRAMCommandStructure);
        
   /* Set the device refresh counter */
	FMC_SetRefreshCount(680);
   
   /* Wait until the SDRAM controller is ready */ 
	timeout = SDRAM_TIMEOUT;
	while(FMC_GetFlagStatus(FMC_Bank1_SDRAM, FMC_FLAG_Busy) != RESET && timeout--);
        
   /* Check if everything goes right */
	/* Write 0x10 at location 0x50 and check if result is the same on read operation */
	/*TM_SDRAM_Write8(0x50, 0x10);
	if (TM_SDRAM_Read8(0x50) == 0x10) {
		//Initialized OK
		return 1;
	}
	//Not OK
	return 0;*/  
}

void LCD_SD_Init()
{
#if(USE_LCD_SD)
  disk_initialize(0);
  LCD_SD_Mount();
#endif
}












