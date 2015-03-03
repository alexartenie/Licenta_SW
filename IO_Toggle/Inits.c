#include <main.h>
#define ADC1_DR    ((uint32_t)0x4001244C)



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
  
}

/*=============* Init ADC for Scope *==================*/
void Scope_ADC_init()
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);
  
  ADC_InitTypeDef ADC_InitStructure;
  
  ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_Rising;
  ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T2_TRGO;
  ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
  ADC_InitStructure.ADC_NbrOfConversion = 2;
  ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 1, ADC_SampleTime_3Cycles);
  if(Active_Scope_Channels==2)
  {
    ADC_RegularChannelConfig(ADC1, ADC_Channel_12, 2, ADC_SampleTime_3Cycles);
    ADC_InitStructure.ADC_ScanConvMode=ENABLE;
  }
  else
  {
    ADC_InitStructure.ADC_ScanConvMode=DISABLE;
  }
  ADC_Init(ADC1, &ADC_InitStructure);
  ADC_ITConfig(ADC1,ADC_IT_EOC,ENABLE);  
  ADC_Cmd(ADC1, ENABLE);  
  ADC_DMACmd(ADC1, ENABLE);
}

/*==============* DMA Initialization *===================*/
void DMA_init()
{
  
  //enable DMA1 clock
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2,ENABLE);  
  //create DMA structure
  DMA_InitTypeDef  DMA_InitStructure;
  DMA_InitStructure.DMA_Channel = DMA_Channel_0;
  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&(ADC1->DR);
  DMA_InitStructure.DMA_Memory0BaseAddr =(uint32_t)&sample_buff;
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory ;
  DMA_InitStructure.DMA_BufferSize = 8;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
  DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;
  DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;
  DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_1QuarterFull;
  DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
  DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
  
  DMA_Init(DMA2_Stream0,&DMA_InitStructure);
  
  //ADC_DMACmd(ADC1,ENABLE);
  
  DMA_ITConfig(DMA2_Stream0,DMA_IT_TC,ENABLE);
  DMA_Cmd(DMA2_Stream0,ENABLE);
  
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
   /* NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = ADC_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);*/
    
   // NVIC_EnableIRQ(ADC_IRQn);
     NVIC_EnableIRQ(DMA2_Stream0_IRQn);
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
   timerInitStructure.TIM_Period = (APB1_CLOCK/2/freq - 1)*Clock_Calibration;
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
    SPI_InitStruct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;
    SPI_InitStruct.SPI_FirstBit = SPI_FirstBit_LSB;    
    
    SPI_Init(TOUCH_SPI,&SPI_InitStruct);
    
    SPI_Cmd(TOUCH_SPI,ENABLE);
  }
}

void LCD_Init()
{
   if(USE_LCD)
  {
  //Initializarea LCD Display-ului
    ssd1963_Initialization();
    ssd1963_SetWindows(10,10,200,200);
    // Clear LCD
    ssd1963_Clear(Black);
   // Draw_Image(100,100,96,96,GFX_pika2,0);
   // Menu_Enter();
  }
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
  DMA_init();
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





