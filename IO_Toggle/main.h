/**
  ******************************************************************************
  * @file    GPIO/GPIO_IOToggle/main.h 
  * @author  MCD Application Team
  * @version V1.2.0RC2
  * @date    20-February-2013
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H


/*==============* Peripheral destination *============
  TIM2 - Scope ADC Trigger
  

======================================================*/


/*==============*System Defines *======================*/

#define CPU_CLOCK 168000000
#define APB1_CLOCK 42000000
#define Clock_Calibration 1.166555
#define Scope_ADC_Burst 1000
#define Scope_TIM TIM2
#define Scope_Grid 25
#define Scope_Grid_Color DarkYellow
#define Scope_Window_dX (((int)(375/Scope_Grid))*Scope_Grid+7)
#define Scope_Window_dY (((int)(225/Scope_Grid))*Scope_Grid+7)
/*====================================================*/


/*===============* Constants for System State *=========*/
#define Active_Scope_Channels    1
#define Scope_Sample_Rate        10
#define ScopeA_Time_Scale        1000
#define Scope_Sample_Period      (1000/Scope_Sample_Rate)
float Scope_X_Step;
#define ScopeA_Color             Yellow
#define Scope_Use_Interpolation  0
#define Scope_Autoclear          1
int Scope_Active;
int CAN_Active;
int AWG_Active;
int ScopeA_Offset;
int ScopeB_Offset;
#define Scope_Dot_Size           1
/*=====================================================*/

/*=============* System Configuration *==============*/
#define USE_TOUCH               1
#define USE_LCD                 1
#define USE_SCOPE               1
#define USE_SCOPE_A             1
#define USE_SCOPE_B             0
#define Scope_Grid_Enabled      1
#define USE_LEDS                1
/*===================================================*/

/*=============* Functions Declaration *==============*/

void GPIO_init();
void Scope_ADC_init();
void DMA_init();
void UART_init();
void NVIC_init();
void TIM_ScopeTrig_init(int);
void wait(int);
void AWG_DAC_init();
unsigned char time[9];
unsigned char temp1wire[7];
void SPI1_Init();
void CheckTouch();
void LCD_Init(void);
void Activate_Scope(void);
void DeActivate_Scope(void);
void LCD_Refresh_task(void);
void Nope_task(void);
void Blink_task(void);
void Check_Touch_task(void);
void PWM_Config(int);
/*=====================================================*/

/*================* Global Variables *=================*/
int sample_counter;
int last_sample_count;
volatile int sample_buff[];
volatile int x,y,x_old,y_old;
/*=====================================================*/

/*================* Pin Destination *=================*/
#define LED1_PORT                GPIOE
#define LED1_PIN                 GPIO_Pin_2

#define LED2_PORT                GPIOE
#define LED2_PIN                 GPIO_Pin_3

#define LED3_PORT                GPIOF
#define LED3_PIN                 GPIO_Pin_9

#define ScopeA_PORT              GPIOC
#define ScopeA_PIN               GPIO_Pin_1
#define ScopeA_PINSource         GPIO_PinSource1

#define ScopeB_PORT              GPIOF
#define ScopeB_PIN               GPIO_Pin_10
#define ScopeB_PINSource         GPIO_PinSource10
/*=====================================================*/

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
