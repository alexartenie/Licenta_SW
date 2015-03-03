/* 
 * File:   touch.h
 * Author: Greg
 *
 * Created on August 26, 2014, 1:56 PM
 */

#ifndef TOUCH_H

#define STM32
   
#define	TOUCH_H


#include <stdint.h>

//TouchScreen controller

/* \defgroup TouchScreenCommands Commands to touchscreen controller.
@{ */
#define CMD_START       (0x80)
#define CMD_12BIT       (0x00)
#define CMD_8BIT        (0x08)
#define CMD_DIFF        (0x00)
#define CMD_SINGLE      (0x04)
#define CMD_X_POS       (0x10)
#define CMD_Z1_POS      (0x30)
#define CMD_Z2_POS      (0x40)
#define CMD_Y_POS       (0x50)
#define CMD_PWD         (0x00)
#define CMD_ALWAYSON    (0x03)

#define NOP for(int i=0;i<2;i++);

#define SPIDelay(t)   for(int i=0;i<t;i++);
/* }@ */
   
#ifdef PIC32
#include <xc.h>          /* Defines special funciton registers, CP0 regs  */
#include <plib.h>
#include "../spi_lib/spi.h"
   #define TOUCH_SPI_CS_BIT       BIT_15    /* Define SPI CS signal to be PIC port RB1 */
   #define TOUCH_SPI_CS_PORT      IOPORT_C
   #define TOUCH_SPI_CS_HIGH      PORTSetBits(TOUCH_SPI_CS_PORT, TOUCH_SPI_CS_BIT)
   #define TOUCH_SPI_CS_LOW       PORTClearBits(TOUCH_SPI_CS_PORT, TOUCH_SPI_CS_BIT)

   #define TOUCH_INT_BIT          (PORTGbits.RG0)
   #define TOUCH_INT_HIGH         TS_INT_IO = 1
   #define TOUCH_INT_LOW         TS_INT_IO = 0

//   #define TOUCH_SPI_SCK_BIT       BIT_15    /* Define SPI CS signal to be PIC port RB1 */
//   #define TOUCH_SPI_SCK_PORT      IOPORT_C
   #define TOUCH_SCK_HIGH      LATGbits.LATG6=1
   #define TOUCH_SCK_LOW       LATGbits.LATG6=0
  
   #define TOUCH_SPI_MOSI_HIGH     LATGbits.LATG8=1
   #define TOUCH_SPI_MOSI_LOW      LATGbits.LATG8=0

   #define TOUCH_SEND(data)       spiPutGetByte(data)
   #define TOUCH_RECEIVE          spiPutGetByte(0x00)
   
  
   
#endif
   
#ifdef STM32
  #define TOUCH_PORT             GPIOG
  #define TOUCH_SPI_CLOCK        RCC_APB1Periph_SPI2
  #define TOUCH_SPI              SPI2
  #define TOUCH_GPIO_AF          GPIO_AF_SPI2

  #define TOUCH_CS_BIT       GPIO_Pin_14    /* Define SPI CS signal to be PIC port RB1 */
  #define TOUCH_CS_PORT      GPIOG
  #define TOUCH_CS_PinSource GPIO_PinSource14
  #define TOUCH_CS_HIGH      GPIO_SetBits(TOUCH_CS_PORT,TOUCH_CS_BIT)
  #define TOUCH_CS_LOW       GPIO_ResetBits(TOUCH_CS_PORT,TOUCH_CS_BIT)
 

  #define TOUCH_INT_BIT          GPIO_Pin_13   
  #define TOUCH_INT_PORT         GPIOD
  #define TOUCH_INT_PinSource    GPIO_PinSource13
  #define TOUCH_INT_HIGH         GPIO_SetBits(TOUCH_INT_PORT,TOUCH_INT_BIT)
  #define TOUCH_INT_LOW          GPIO_ResetBits(TOUCH_INT_PORT,TOUCH_INT_BIT)

  #define TOUCH_SCK_BIT          GPIO_Pin_13   
  #define TOUCH_SCK_PORT         GPIOB
  #define TOUCH_SCK_PinSource    GPIO_PinSource13
  #define TOUCH_SCK_HIGH         GPIO_SetBits(TOUCH_SCK_PORT,TOUCH_SCK_BIT)
  #define TOUCH_SCK_LOW          GPIO_ResetBits(TOUCH_SCK_PORT,TOUCH_SCK_BIT)

  #define TOUCH_MOSI_BIT         GPIO_Pin_15  
  #define TOUCH_MOSI_PORT        GPIOB
  #define TOUCH_MOSI_PinSource   GPIO_PinSource15
  #define TOUCH_MOSI_HIGH        GPIO_SetBits(TOUCH_MOSI_PORT,TOUCH_MOSI_BIT)
  #define TOUCH_MOSI_LOW         GPIO_ResetBits(TOUCH_MOSI_PORT,TOUCH_MOSI_BIT)

  #define TOUCH_MISO_BIT         GPIO_Pin_14  
  #define TOUCH_MISO_PORT        GPIOB
  #define TOUCH_MISO_PinSource   GPIO_PinSource14
  #define TOUCH_MISO_HIGH        GPIO_SetBits(TOUCH_MISO_PORT,TOUCH_MISO_BIT)
  #define TOUCH_MISO_LOW         GPIO_ResetBits(TOUCH_MISO_PORT,TOUCH_MISO_BIT)

  
  
  #define TOUCH_SEND(data)       SPI_I2S_SendData(TOUCH_SPI,data)
  #define TOUCH_RECEIVE          SPI_I2S_ReceiveData(TOUCH_SPI)
#endif
   
// Get X position command
#define CMD_X_POSITION 0x93 //((1 << ADS_CTRL_SWITCH_SHIFT) | ADS_CTRL_START | ADS_CTRL_PD0 | ADS_CTRL_PD1)
// Get Y position command
#define CMD_Y_POSITION 0xD3 //((5 << ADS_CTRL_SWITCH_SHIFT) | ADS_CTRL_START | ADS_CTRL_PD0 | ADS_CTRL_PD1)
// Enable penIRQ
#define CMD_ENABLE_PENIRQ  0x90 //((1 << ADS_CTRL_SWITCH_SHIFT) | ADS_CTRL_START)

#define MIN_PRESSURE    (30) //!<Minimal pressure to registre pressing.
volatile float ax_calibrate, bx_calibrate; //!<Calibrating coefficients for touchscreen X axis.
volatile float ay_calibrate, by_calibrate; //!<Calibrating coefficients for touchscreen Y axis.

  /**@struct A struct type - point.
   */
typedef struct
{
volatile	uint16_t x;
volatile	uint16_t y;
} TP_POINT;

typedef TP_POINT CAL_POINT;

volatile unsigned char pressure;               //!<touch panel pressure
volatile TP_POINT tp_raw;				//!<raw pos (touch panel)
volatile TP_POINT tp_calibrated;        //!<calibrated pos (screen)

/** @function TouchRead
  Reads touch screen throw SPI.
  Writes in global variable tp_raw coordinates of pressing.
  \return Pressure value (z coordinate)
 */
int TouchRead(void);

/** @function TouchLCD_Calibrate
Calibrates touch screen.
Reads from global variables raw touch screen data,
writes calibrated data in global variables in respect with calibration coefficients.
@return 1 if calibration was successful, 0 if unsuccessful.
*/
void TouchLCD_Calibrate(void);

void TSD_GetRawMeasurement(unsigned int *pData);
void Decode_TS(unsigned int x, unsigned int y);
void TouchInitialization(void);
unsigned int  Touch_GetPhyX(void);
unsigned int  Touch_GetPhyY(void);
unsigned int  Touch_MeasurementX(void);
unsigned int  Touch_MeasurementY(void);

char spi_put_get_char (char c);
#endif	/* TOUCH_H */

