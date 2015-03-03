#include "touch.h"

volatile char calibrated_flag = 0; //!< Use or not default calibration.

void TouchInitialization(void)
{
    //Configure SPI
    TOUCH_CS_HIGH; // deselect chip for now
    //TOUCH_CS_LOW; //CS for Touch
}
int TouchPutGetByte(int data)
{
  TOUCH_SEND(data);
  return TOUCH_RECEIVE;
}
int TouchRead(void)
{
  uint8_t a1, b1;
  uint16_t x, y;
 	//get pressure
 	TOUCH_CS_LOW;
        SPIDelay(100);
        TouchPutGetByte(CMD_START | CMD_8BIT | CMD_DIFF | CMD_Z1_POS);
 	a1 = TouchPutGetByte(0x00);
        TouchPutGetByte(CMD_START | CMD_8BIT | CMD_DIFF | CMD_Z2_POS);
        uint8_t temp = TouchPutGetByte(0x00);
 	b1 = 127 - (temp & 0x7F);
 	TOUCH_CS_HIGH;
 	pressure = a1 + b1;
if(pressure > MIN_PRESSURE)
  {
    //using 2 samples for x and y position
    TOUCH_CS_LOW;
    //get X data
    TouchPutGetByte(CMD_START | CMD_12BIT | CMD_DIFF | CMD_X_POS);
    a1 = TouchPutGetByte(0x00);
    b1 = TouchPutGetByte(0x00);
    x = ((a1<<4)|(b1>>4)); //12bit: ((a<<4)|(b>>4)) //10bit: ((a<<2)|(b>>6))
     //get Y data
    TouchPutGetByte(CMD_START | CMD_12BIT | CMD_DIFF | CMD_Y_POS);
    a1 = TouchPutGetByte(0x00);
    b1 = TouchPutGetByte(0x00);
    y = ((a1<<4)|(b1>>4)); //12bit: ((a<<4)|(b>>4)) //10bit: ((a<<2)|(b>>6))
        if (x && y)
        {
          tp_raw.x = y;
          tp_raw.y = x;
        }
	TOUCH_CS_HIGH;
  }
  else pressure = 0;
  return pressure;
}

void TouchLCD_Calibrate(void)
{
	if (calibrated_flag)
	{
		tp_calibrated.x = ( ax_calibrate * ((float)(tp_raw.x)) + bx_calibrate);
		tp_calibrated.y = ( ay_calibrate * ((float)(tp_raw.y)) + by_calibrate);
	}
	else
	{
		ax_calibrate = 0.25;
		bx_calibrate = -25;
		ay_calibrate = 0.15;
		by_calibrate = -30;
	}
	tp_calibrated.x = ( ax_calibrate * ((float)(tp_raw.x)) + bx_calibrate);
	tp_calibrated.y = ( ay_calibrate * ((float)(tp_raw.y)) + by_calibrate);
	if (tp_calibrated.x >= 480)	 tp_calibrated.x = 480;
	else if (tp_calibrated.x < 0)  tp_calibrated.x = 0;
	if (tp_calibrated.y >= 272)	 tp_calibrated.y = 272;
	else if (tp_calibrated.y < 0)  tp_calibrated.y = 0;
}

unsigned char TouchReleased(void)
{
	unsigned int a1, b1;
	//get pressure
	TOUCH_CS_LOW;
	TouchPutGetByte(CMD_START | CMD_8BIT | CMD_DIFF | CMD_Z1_POS);
	a1 = TouchPutGetByte(0x00);
	TouchPutGetByte(CMD_START | CMD_8BIT | CMD_DIFF | CMD_Z2_POS);
	b1 = 127 - (TouchPutGetByte(0x00) & 0x7F);
	TOUCH_CS_HIGH;
	pressure = a1 + b1;
	return pressure;
}

void CheckTouch()
{
  static int X;
  if(TOUCH_READ_INT_PIN==0)
  {  
    char touch_str[80];
    char calib_str[80];
    int pressure = TouchRead();
    sprintf(touch_str, "X: %6d, Y: %6d, Z: %6d", tp_raw.x, tp_raw.y, pressure);
    TouchLCD_Calibrate();
    sprintf(calib_str, "X: %6d, Y: %6d, Z: %6d", tp_calibrated.x, tp_calibrated.y, pressure);
    ssd1963_PutText(10, 70, "Touchscreen RAW data:", Yellow, Black);
    ssd1963_PutText(10, 85, touch_str, Yellow, Black);
    ssd1963_PutText(10, 100, "Touchscreen calibrated data:", Red, Black);
    ssd1963_PutText(10, 115, calib_str, Red, Black);
  }
}

