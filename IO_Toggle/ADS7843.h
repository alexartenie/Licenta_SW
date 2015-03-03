#include <touch.h>
#ifdef PIC32
#include <xc.h>          /* Defines special funciton registers, CP0 regs  */
//TouchScreen controller
//TS_MOSI
#define TS_MISO_TRIS            (TRISGbits.TRISG7)
#define SET_MISO                GPIO_SetBits()
#define TS_MISO_IO              (PORTGbits.RG7)//(LATGbits.LATG7)
//TS_MOSI
#define TS_MOSI_TRIS            (TRISGbits.TRISG8)
#define TS_MOSI_IO              (LATGbits.LATG8)
//TS_SCK
#define TS_SCK_TRIS             (TRISGbits.TRISG6)
#define TS_SCK_IO               (LATGbits.LATG6)
//TS_CS
#define TS_CS_TRIS              (TRISCbits.TRISC15)
#define TS_CS_IO                (LATCbits.LATC15)
//TS_INT
#define TS_INT_TRIS             (TRISGbits.TRISG0)
#define TS_INT_IO               (PORTGbits.RG0)
//TS_BUSY
#define TS_BUSY_TRIS            (TRISGbits.TRISG1)
#define TS_BUSY_IO              (PORTGbits.RG1)

#define TOUCHSCREEN_SPI_IF	(PIR3bits.SSP2IF)
#define TOUCHSCREEN_SSPBUF	(SSP2BUF)
#define TOUCHSCREEN_SPICON1	(SSP2CON1)
#define TOUCHSCREEN_SPICON1bits	(SSP2CON1bits)
#define TOUCHSCREEN_SPICON2	(SSP2CON2)
#define TOUCHSCREEN_SPISTAT	(SSP2STAT)
#define TOUCHSCREEN_SPISTATbits	(SSP2STATbits)

#define Touch_PenIRQ_CN_Enable          CN2_ENABLE					// Defines the Change Notice number for the PenIRQ Input
#define	Touch_PenIRQ_CN_Disable         CN2_DISABLE

#define	Buzzer_TRIS			TRISGbits.TRISG14
#define	Buzzer_ODC			ODCGbits.ODCG14
#define	Buzzer				LATGbits.LATG14

#define TOUCH_READ_INT_PIN      TS_INT_IO
#define TOUCH_INT_AS_OUTPUT     TS_INT_TRIS = 0
#define TOUCH_INT_AS_INPUT      TS_INT_TRIS = 1
#define TOUCH_READ_MISO_PIN     TS_MISO_IO
#endif

#ifdef STM32
#define TOUCH_READ_INT_PIN      GPIO_ReadInputDataBit(TOUCH_INT_PORT,TOUCH_INT_BIT)
#define TOUCH_INT_AS_OUTPUT     {GPIO_InitTypeDef GPIO_str; GPIO_str.GPIO_Pin=TOUCH_INT_BIT; GPIO_str.GPIO_Mode = GPIO_Mode_OUT; GPIO_Init(TOUCH_INT_PORT, &GPIO_str);}
#define TOUCH_INT_AS_INPUT      {GPIO_InitTypeDef GPIO_str; GPIO_str.GPIO_Pin=TOUCH_INT_BIT; GPIO_str.GPIO_Mode = GPIO_Mode_IN; GPIO_Init(TOUCH_INT_PORT, &GPIO_str);}
#define TOUCH_READ_MISO_PIN     GPIO_ReadInputDataBit(TOUCH_MISO_PORT,TOUCH_MISO_BIT)
#endif

#define on				0
#define off				1

void Touch_Init(void);			// Initialises the touch screen
unsigned int ReadTouchXY(void);		// Reads the touch screen chipa and returns the coordinates
void delayms(int delay);
void TDelay(void);		// 200ns delay used to read and write to the touch chip
void PulseTouch_CLK (void);


unsigned char Touch_Read (void);	//reads one bit at a time from the IC
