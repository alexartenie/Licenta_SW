//Pin Define

#define LCD_Buffered 0

#define LCD_CTRL_PORT_RST                      GPIOC
#define LCD_CTRL_PIN_RST                          GPIO_Pin_13

#define LCD_CTRL_PORT_RD                        GPIOG
#define LCD_CTRL_PIN_RD                            GPIO_Pin_13

#define LCD_CTRL_PORT_WR                       GPIOG
#define LCD_CTRL_PIN_WR                           GPIO_Pin_12

#define LCD_CTRL_PORT_CS                        GPIOD
#define LCD_CTRL_PIN_CS                            GPIO_Pin_12

#define LCD_CTRL_PORT_RS                        GPIOG
#define LCD_CTRL_PIN_RS                            GPIO_Pin_11

#define LCD_CTRL_PORT_LEDA                   GPIOG
#define LCD_CTRL_PIN_LEDA                       GPIO_Pin_3


#define LCD_DATA_PORT_DB0                      GPIOA
#define LCD_DATA_PIN_DB0                          GPIO_Pin_0

#define LCD_DATA_PORT_DB1                      GPIOA
#define LCD_DATA_PIN_DB1                          GPIO_Pin_1

#define LCD_DATA_PORT_DB2                      GPIOA
#define LCD_DATA_PIN_DB2                          GPIO_Pin_2

#define LCD_DATA_PORT_DB3                      GPIOA
#define LCD_DATA_PIN_DB3                          GPIO_Pin_3

#define LCD_DATA_PORT_DB4                      GPIOB
#define LCD_DATA_PIN_DB4                          GPIO_Pin_4

#define LCD_DATA_PORT_DB5                      GPIOB
#define LCD_DATA_PIN_DB5                          GPIO_Pin_5

#define LCD_DATA_PORT_DB6                      GPIOA
#define LCD_DATA_PIN_DB6                          GPIO_Pin_6

#define LCD_DATA_PORT_DB7                     GPIOA
#define LCD_DATA_PIN_DB7                          GPIO_Pin_7

#define LCD_DATA_PORT_DB8                     GPIOA
#define LCD_DATA_PIN_DB8                          GPIO_Pin_8

#define LCD_DATA_PORT_DB9                     GPIOA
#define LCD_DATA_PIN_DB9                          GPIO_Pin_9

#define LCD_DATA_PORT_DB10                   GPIOA
#define LCD_DATA_PIN_DB10                       GPIO_Pin_10

#define LCD_DATA_PORT_DB11                    GPIOA
#define LCD_DATA_PIN_DB11                        GPIO_Pin_11

#define LCD_DATA_PORT_DB12                    GPIOA
#define LCD_DATA_PIN_DB12                        GPIO_Pin_12

#define LCD_DATA_PORT_DB13                    GPIOA
#define LCD_DATA_PIN_DB13                        GPIO_Pin_13

#define LCD_DATA_PORT_DB14                    GPIOA
#define LCD_DATA_PIN_DB14                        GPIO_Pin_14

#define LCD_DATA_PORT_DB15                    GPIOA
#define LCD_DATA_PIN_DB15                        GPIO_Pin_15




//#include "MainDemo.h"
//#include "HardwareProfile.h"
#include "stm32f4xx.h"

/* some RGB color definitions                                                 */
#define Background_Color            Black//0x471A
#define Text_Color                  Blue

#define Black           0x0000      /*   0,   0,   0 */
#define Navy            0x000F      /*   0,   0, 128 */
#define DarkGreen       0x03E0      /*   0, 128,   0 */
#define DarkCyan        0x03EF      /*   0, 128, 128 */
#define Maroon          0x7800      /* 128,   0,   0 */
#define Purple          0x780F      /* 128,   0, 128 */
#define Olive           0x7BE0      /* 128, 128,   0 */
#define LightGrey       0xC618      /* 192, 192, 192 */
#define DarkGrey        0x7BEF      /* 128, 128, 128 */
#define Blue            0x001F      /*   0,   0, 255 */
#define Green           0x07E0      /*   0, 255,   0 */
#define Cyan            0x07FF      /*   0, 255, 255 */
#define Red             0xF800      /* 255,   0,   0 */
#define Magenta         0xF81F      /* 255,   0, 255 */
#define Yellow          0xFFE0      /* 255, 255,   0 */
#define White           0xFFFE      /* 255, 255, 255 */
#define Orange          0xFD20      /* 255, 165,   0 */
#define GreenYellow     0xAFE5      /* 173, 255,  47 */
#define Pink            0xF81F
#define LightBlue       0x07EF
#define Transparent     0xFFFF
#define DarkYellow      0x4BF0
// LCD I/O pins
// LCD Data
#define LCD_Data_L_TRIS         (TRISE)
#define LCD_Data_L_IO           (LATE)
#define LCD_Data_H_TRIS         (TRISF)
#define LCD_Data_H_IO           (LATF)
// LCD CS
#define LCD_CS_TRIS             (TRISGbits.TRISG4)
#define LCD_CS_IO               (LATGbits.LATG4)
// LCD RS
#define LCD_RS_TRIS             (TRISGbits.TRISG5)
#define LCD_RS_IO               (LATGbits.LATG5)
// LCD WR
#define LCD_WR_TRIS             (TRISGbits.TRISG6)
#define LCD_WR_IO               (LATGbits.LATG6)
// LCD RD
#define LCD_RD_TRIS             (TRISGbits.TRISG7)
#define LCD_RD_IO               (LATGbits.LATG7)
// LCD Reset
#define LCD_Reset_TRIS          (TRISGbits.TRISG3)
#define LCD_Reset_IO            (LATGbits.LATG3)
// LCD BackLight
#define LCD_BL_TRIS             (TRISDbits.TRISD2)
#define LCD_BL_IO               (LATDbits.LATD2)

#define Set_nWr LCD_WR_IO = 1
#define Clr_nWr LCD_WR_IO = 0

#define Set_Cs  LCD_CS_IO = 1
#define Clr_Cs  LCD_CS_IO = 0

#define Set_Rs  LCD_RS_IO = 1
#define Clr_Rs  LCD_RS_IO = 0

#define Set_nRd LCD_RD_IO = 1
#define Clr_nRd LCD_RD_IO = 0

#define Set_Rst LCD_Reset_IO = 1
#define Clr_Rst LCD_Reset_IO = 0

#define Lcd_Light_ON   LCD_BL_IO = 1
#define Lcd_Light_OFF  LCD_BL_IO = 0


//unsigned int CheckController(void);
//void Lcd_Configuration(void);
void ssd1963_Initialization(void);
void ssd1963_Reset(void);
void ssd1963_WriteRegister(unsigned int index,unsigned int dat);
void ssd1963_SetCursor(unsigned int x,unsigned int y);
void ssd1963_SetWindows(unsigned int StartX,unsigned int StartY,unsigned int EndX,unsigned int EndY);
void ssd1963_DrawPicture(unsigned int StartX,unsigned int StartY,unsigned int EndX,unsigned int EndY,unsigned int* pic);
void ssd1963_SetPoint(unsigned int x,unsigned int y,unsigned int point);
void ssd1963_PutChar(unsigned int x,unsigned int y,unsigned char c,unsigned int charColor,unsigned int bkColor);
void ssd1963_Clear(unsigned int dat);
void ssd1963_Delay(unsigned long nCount);
void ssd1963_Test(void);
unsigned int ssd1963_GetCode(void);
void ssd1963_WriteData(unsigned int dat);
void ssd1963_WriteIndex(unsigned int idx);

void ssd1963_PutText(unsigned int x,unsigned int y,char *pString,unsigned int charColor,unsigned int bkColor);

void ssd1963_BackLight(unsigned char status);

unsigned int ssd1963_BGR2RGB(unsigned int c);

//unsigned int ili9320_GetPoint(unsigned int x,unsigned int y);
//unsigned int ili9320_ReadData(void);
//unsigned int ili9320_ReadRegister(unsigned int index);

unsigned int GUI_Color565(unsigned long RGB);  // RGB颜色转为16位(565)

void GUI_Text(unsigned int x, unsigned int y, unsigned char *str, unsigned int len,unsigned int Color, unsigned int bkColor);
void GUI_Line(unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1,unsigned int color);  // 画线
void GUI_Circle(unsigned int cx,unsigned int cy,unsigned int r,unsigned int color,unsigned char fill);  // 画园
void GUI_Rectangle(unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1,unsigned int color,unsigned char fill); // 画矩形
void GUI_Square(unsigned int x0, unsigned int y0, unsigned int with, unsigned int color,unsigned char fill);  // 画正方形

void Touch_Initialization(void);
unsigned int  Touch_GetPhyX(void);
unsigned int  Touch_GetPhyY(void);
unsigned int  Touch_MeasurementX(void);
unsigned int  Touch_MeasurementY(void);

void ssd1963_PutLine(unsigned int x,unsigned int y,unsigned char axe, unsigned int length,unsigned int Color);
void ssd1963_ClearZone(unsigned int x,unsigned int y,unsigned int dX, unsigned int dY,unsigned int Color);
void ssd1963_Write(int);

//int my_image[]={Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue,Blue};


