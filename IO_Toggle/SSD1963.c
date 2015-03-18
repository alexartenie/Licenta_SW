
#include "ssd1963.h"
#include "lcd_font.h"
char ascii_8x16[1536];

volatile unsigned int LCD_Window_StartX;
volatile unsigned int LCD_Window_StartY;
volatile unsigned int LCD_Window_EndX;
volatile unsigned int LCD_Window_EndY;
/****************************************************************************
* void ssd1963_Initialization()
*
* Parameters:
* Return:
*
* Example uf use: ssd1963_Initialization();
****************************************************************************/
void ssd1963_Initialization()
{
    int i;    
    //Initialize signal pins as outputs
    /*LCD_Data_L_TRIS = 0;
    LCD_Data_H_TRIS = 0;
    LCD_CS_TRIS = 0;
    LCD_RS_TRIS = 0;
    LCD_WR_TRIS = 0;
    LCD_RD_TRIS = 0;
    LCD_Reset_TRIS = 0;
    LCD_BL_TRIS = 0;
    Lcd_Light_OFF;*/
    //Made in GPIO_init();
    
    
    ssd1963_WriteData(0xffff);
    GPIO_SetBits(LCD_CTRL_PORT_RST,LCD_CTRL_PIN_RST);//  Set_Rst;
    GPIO_SetBits(LCD_CTRL_PORT_WR, LCD_CTRL_PIN_WR);//Set_nWr;
    GPIO_SetBits(LCD_CTRL_PORT_CS, LCD_CTRL_PIN_CS);//Set_Cs;
    GPIO_SetBits(LCD_CTRL_PORT_RS, LCD_CTRL_PIN_RS);//Set_Rs;
    GPIO_SetBits(LCD_CTRL_PORT_RD, LCD_CTRL_PIN_RD);//Set_nRd;
    GPIO_SetBits(LCD_CTRL_PORT_RST,LCD_CTRL_PIN_RST);//Set_Rst;
    
    ssd1963_Reset();                                        // ��λ ili9320_Reset
    for(i=5000;i>0;i--);
    for(i=5000;i>0;i--);
    for(i=5000;i>0;i--);
    
    GPIO_ResetBits(LCD_CTRL_PORT_CS,LCD_CTRL_PIN_CS);//Clr_Cs;
    ssd1963_WriteRegister(0x0000,0x0001);
    ssd1963_Delay(1000);
    for(i=5000;i>0;i--);
    for(i=5000;i>0;i--);

    
    GPIO_ResetBits(LCD_CTRL_PORT_CS,LCD_CTRL_PIN_CS);//Clr_Cs;
    // Software Reset
    ssd1963_WriteIndex(0x01);
    ssd1963_WriteIndex(0x01);
    ssd1963_WriteIndex(0x01);
    
    ssd1963_Delay(100);
    ssd1963_WriteIndex(0xE2); //PLL multiplier, set PLL clock to 120M
    //ssd1963_WriteData(0x14); //29
    ssd1963_WriteData(0x1D);
    //ssd1963_WriteData(0x03);
    ssd1963_WriteData(0x03);
    ssd1963_WriteData(0x04);
    
    ssd1963_WriteRegister(0xe0,0x01);    //START PLL
    ssd1963_Delay(100);
    ssd1963_WriteRegister(0xe0,0x03);    //LOCK PLL
    ssd1963_Delay(100);
    
    GPIO_ResetBits(LCD_CTRL_PORT_CS,LCD_CTRL_PIN_CS);//Clr_Cs;
    ssd1963_WriteIndex(0xb0);        //LCD specification
    ssd1963_WriteData(0x20);             //SET TFT MODE & hsync+Vsync+DEN MODE
    ssd1963_WriteData(0x00);             //SET TFT MODE & hsync+Vsync+DEN MODE
    ssd1963_WriteData(0x01);             //SET horizontal size=480-1 HightByte
    ssd1963_WriteData(0xdf);             //SET horizontal size=480-1 LowByte
    ssd1963_WriteData(0x01);             //SET vertical size=272-1 HightByte
    ssd1963_WriteData(0x0f);             //SET vertical size=272-1 LowByte
    ssd1963_WriteData(0x00);             //SET even/odd line RGB seq.=RGB
    ssd1963_Delay(500);
    
    ssd1963_WriteRegister(0xf0,0x03);    //SET pixel data I/F format = 16bit 5-6-5
    
    ssd1963_WriteRegister(0x3a,0x50);   // SET R G B format = 5 6 5
    
    GPIO_ResetBits(LCD_CTRL_PORT_CS,LCD_CTRL_PIN_CS);//Clr_Cs;
    ssd1963_WriteIndex(0xe6);           //PLL setting for PCLK, depends on resolution
    ssd1963_WriteData(0x03);
    //ssd1963_WriteData(0xa0);
     ssd1963_WriteData(0x85);
   // ssd1963_WriteData(0x00);
      ssd1963_WriteData(0x1D);
    
    ssd1963_WriteIndex(0xb4);        //SET HBP,
    ssd1963_WriteData(0x02);             //SET HSYNC Total=928 HightByte
    ssd1963_WriteData(0x0d);             //SET HSYNC Total=928 LowByte      
    ssd1963_WriteData(0x00);             //SET HBP 46 HightByte
    ssd1963_WriteData(0x25);             //SET HBP 46 LowByte
    ssd1963_WriteData(0x02);             //SET VBP 48
    ssd1963_WriteData(0x00);             //SET Hsync pulse start position  (15 HighByte)
    ssd1963_WriteData(0x00);             //15 LowByte
    ssd1963_WriteData(0x00);             //SET Hsync pulse subpixel start position
    
    ssd1963_WriteIndex(0xb6);         //SET VBP,
    ssd1963_WriteData(0x01);             //SET Vsync total=525 HighByte
    ssd1963_WriteData(0x1e);             // 525 LowByte
    ssd1963_WriteData(0x00);             //SET VBP=16 HighByte
    ssd1963_WriteData(0x08);             // 16 LowByte
    ssd1963_WriteData(0x01);             //SET Vsync pulse 16
    ssd1963_WriteData(0x00);             //SET Vsync pulse start position (8 HighByte)
    ssd1963_WriteData(0x00);             //8 LowByte
    
    ssd1963_WriteIndex(0x2a);        //SET column address
    ssd1963_WriteData(0x00);            //SET start column address=0
    ssd1963_WriteData(0x00);
    ssd1963_WriteData(0x01);            //SET end column address=479
    ssd1963_WriteData(0xdf);
    
    ssd1963_WriteIndex(0x2b);        //SET page address
    ssd1963_WriteData(0x00);            //SET start page address=0
    ssd1963_WriteData(0x00);
    ssd1963_WriteData(0x01);            //SET end page address=271
    ssd1963_WriteData(0x0f);
        
    ssd1963_WriteRegister(0x36,0x03);    //Rotation
    
    GPIO_ResetBits(LCD_CTRL_PORT_CS,LCD_CTRL_PIN_CS);//Clr_Cs;
    ssd1963_WriteIndex(0x29);        //SET display on
    
         //       ssd1963_WriteRegister(0x00be);         //SET PWM for B/L
         //       ssd1963_WriteData(0x000e);
          //      ssd1963_WriteData(0x00ff);
          //      ssd1963_WriteData(0x0009);
          //      ssd1963_WriteData(0x00ff);
          //      ssd1963_WriteData(0x0000);
          //      ssd1963_WriteData(0x0000);
    
    ssd1963_WriteIndex(0x00d0);
    ssd1963_WriteData(0x000d);
    
    //Reset GPIO0
    ssd1963_WriteIndex(0x00b8);
    ssd1963_WriteData(0x0000);
    ssd1963_WriteData(0x0001);
    
    ssd1963_WriteIndex(0x00ba);
    ssd1963_WriteData(0x0001);
    
    
    
    GPIO_SetBits(LCD_CTRL_PORT_CS,LCD_CTRL_PIN_CS);//Set_Cs;
    
    GPIO_ResetBits(LCD_CTRL_PORT_CS,LCD_CTRL_PIN_CS);//Clr_Cs;
    ssd1963_WriteIndex(0x2a);        //SET column address
    ssd1963_WriteData(0 / 0x0100);            //SET start column address=0
    ssd1963_WriteData(0 & 0x00FF);
    ssd1963_WriteData(481 / 0x0100);            //SET end column address=479
    ssd1963_WriteData(481 & 0x00FF);

    ssd1963_WriteIndex(0x2b);        //SET page address
    ssd1963_WriteData(0 / 0x0100);            //SET start page address=0
    ssd1963_WriteData(0 & 0x00FF);
    ssd1963_WriteData(272 / 0x0100);            //SET end page address=271
    ssd1963_WriteData(272 & 0x00FF);
    GPIO_SetBits(LCD_CTRL_PORT_CS,LCD_CTRL_PIN_CS);//Set_Cs;
    //Turn On the backlight
    ssd1963_BackLight(1);
}

/****************************************************************************
* void ssd1963_SetCursor(unsigned int x,unsigned int y)
* 
* Parameters: x      x coordonate
*             y      y coordonate
* Return:
*
* Example uf use: ssd1963_SetCursor(10,10);
****************************************************************************/
void ssd1963_SetCursor(unsigned int x,unsigned int y)
{
#if(LCD_Buffered)
  {
    cursor=482*y+x;
  }
#else
  {
    GPIO_ResetBits(LCD_CTRL_PORT_CS,LCD_CTRL_PIN_CS);//Clr_Cs;
    ssd1963_WriteIndex(0x2a);        //SET column address
    ssd1963_WriteData(x / 0x0100);            //SET start column address=0
    ssd1963_WriteData(x & 0x00FF);
    ssd1963_WriteData(0x01);            //SET end column address=479
    ssd1963_WriteData(0xDF);

    ssd1963_WriteIndex(0x2b);        //SET page address
    ssd1963_WriteData(y / 0x0100);            //SET start page address=0
    ssd1963_WriteData(y & 0x00FF);
    ssd1963_WriteData(0x01);            //SET end page address=271
    ssd1963_WriteData(0x0F);
    GPIO_SetBits(LCD_CTRL_PORT_CS,LCD_CTRL_PIN_CS);//Set_Cs;
  }
#endif
}

/****************************************************************************
* void ssd1963_SetWindows(unsigned int StartX,unsigned int StartY,unsigned int EndX,unsigned int EndY)
* 
* Parameters: StartX     StartX coordonate
*             StartY     StartY coordonate
*             EndX       EndX coordonate
*             EndY       EndY coordonate
* Return:
* 
* Example uf use: ssd1963_SetWindows(0,0,100,100);
****************************************************************************/
void ssd1963_SetWindows(unsigned int StartX,unsigned int StartY,unsigned int EndX,unsigned int EndY)
{
#if(LCD_Buffered)
  {
    LCD_Window_StartX=StartX;
    LCD_Window_StartY=StartY;
    LCD_Window_EndX=EndX;
    LCD_Window_EndY=EndY;
    ssd1963_SetCursor(StartX,StartY);
    cursor_at_end_of_first_line = (482*LCD_Window_StartY+LCD_Window_StartX)+(LCD_Window_EndX-LCD_Window_StartX);    
  }
#else
  {
    GPIO_ResetBits(LCD_CTRL_PORT_CS,LCD_CTRL_PIN_CS);//Clr_Cs;
    ssd1963_WriteIndex(0x2a);        //SET column address
    ssd1963_WriteData(StartX / 0x0100);            //SET start column address=0
    ssd1963_WriteData(StartX & 0x00FF);
    ssd1963_WriteData(EndX / 0x0100);            //SET end column address=479
    ssd1963_WriteData(EndX & 0x00FF);

    ssd1963_WriteIndex(0x2b);        //SET page address
    ssd1963_WriteData(StartY / 0x0100);            //SET start page address=0
    ssd1963_WriteData(StartY & 0x00FF);
    ssd1963_WriteData(EndY / 0x0100);            //SET end page address=271
    ssd1963_WriteData(EndY & 0x00FF);
    GPIO_SetBits(LCD_CTRL_PORT_CS,LCD_CTRL_PIN_CS);//Set_Cs;
  }
#endif
}

/****************************************************************************
* void ssd1963_Clear(unsigned int dat)
* 
* Parameters: dat     Pixel color
* Return:
* 
* Example uf use: ssd1963_Clear(0xFFFF);
****************************************************************************/
void ssd1963_Clear(unsigned int dat)
{
#if(LCD_Buffered)
  {
    ssd1963_SetWindows(0, 0, 479, 271);
    for(int i=0;i<130560;i++)
        LCD_WriteBuff(dat);
   
  }
#else
  {
  long  i;

  ssd1963_SetWindows(0, 0, 479, 271);
  GPIO_ResetBits(LCD_CTRL_PORT_CS,LCD_CTRL_PIN_CS);//Clr_Cs; 
  ssd1963_WriteIndex(0x002c);
  GPIO_SetBits(LCD_CTRL_PORT_RS,LCD_CTRL_PIN_RS);//Set_Rs;
  
  for(i=0;i<130560;i++)
  {
      ssd1963_WriteData(dat);
  }
 

  GPIO_SetBits(LCD_CTRL_PORT_CS,LCD_CTRL_PIN_CS);//Set_Cs;
  }
#endif
}

/****************************************************************************
* void ssd1963_ClearZone(unsigned int x,unsigned int y,unsigned int dX, unsigned int dY,unsigned int Color)
* 
* Parameters: x     StartX coordonate
*             y     StartY coordonate
*             dX       EndX coordonate
*             dY       EndY coordonate
*             Color     Color of the pixels
* 
* Example uf use: ssd1963_ClearZone(6, 111, 468, 156, 0x7777);
****************************************************************************/
void ssd1963_ClearZone(unsigned int x,unsigned int y,unsigned int dX, unsigned int dY,unsigned int Color)
{
#if(LCD_Buffered)
  {
    static unsigned int i, j;
    ssd1963_SetWindows(x, y, (x+dX), (y+dY));
    for (i=0; i<dX; i++)
        for(j=0; j<dY; j++)
            LCD_WriteBuff(Color);    
  }
#else
  {
    static unsigned int i, j;

    ssd1963_SetWindows(x, y, (x+dX-1), (y+dY-1));

    GPIO_ResetBits(LCD_CTRL_PORT_CS,LCD_CTRL_PIN_CS);//Clr_Cs;
    ssd1963_WriteIndex(0x002c);
    GPIO_SetBits(LCD_CTRL_PORT_RS,LCD_CTRL_PIN_RS);//Set_Rs;
  
    for (i=0; i<dX; i++)
        for(j=0; j<dY; j++)
            ssd1963_WriteData(Color);    
    
    GPIO_SetBits(LCD_CTRL_PORT_CS,LCD_CTRL_PIN_CS);//Set_Cs;
  }
#endif
}

/****************************************************************************
* void ssd1963_SetPoint(unsigned int x,unsigned int y,unsigned int point)
*
* Parameters: x     StartX coordonate
*             y     StartY coordonate
*             point     Color of the pixels
*
* Example uf use: ssd1963_SetPoint(10,20,0xFFFF);
****************************************************************************/
void ssd1963_SetPoint(unsigned int x,unsigned int y,unsigned int point)
{
#if(LCD_Buffered)
  {
    //if ( (x>479)||(y>271) ) return;
    ssd1963_SetCursor(x,y);
    LCD_WriteBuff(point);
  }
#else
  {
  if ( (x>479)||(y>271) ) return;

  ssd1963_SetCursor(x,y);
  
  GPIO_ResetBits(LCD_CTRL_PORT_CS,LCD_CTRL_PIN_CS);//Clr_Cs;
  ssd1963_WriteIndex(0x002c);
  GPIO_SetBits(LCD_CTRL_PORT_RS,LCD_CTRL_PIN_RS);//Set_Rs;
  ssd1963_WriteData(point);
  GPIO_SetBits(LCD_CTRL_PORT_CS,LCD_CTRL_PIN_CS);//Set_Cs;
  }
#endif
}

/****************************************************************************
* void ssd1963_DrawPicture(unsigned int StartX,unsigned int StartY,unsigned int EndX,unsigned int EndY,unsigned int *pic)
*
* Parameters: StartX     StartX coordonate
*             StartY     StartY coordonate
*             EndX       EndX coordonate
*             EndY       EndY coordonate
*             *pic       Pointer to the array with the image
*
* Example uf use: ssd1963_DrawPicture(100,100,160,160,Icon_Start);
****************************************************************************/
void ssd1963_DrawPicture(unsigned int StartX,unsigned int StartY,unsigned int EndX,unsigned int EndY,unsigned int* pic)
{
#if(LCD_Buffered)
  {
    unsigned int  i;
    ssd1963_SetWindows(StartX,StartY,EndX,EndY);
    ssd1963_SetCursor(StartX,StartY);
    for (i=0;i<(EndX*EndY);i++)  
      LCD_WriteBuff(*pic++);  
  }
#else
  {
  unsigned int  i;
  ssd1963_SetWindows(StartX,StartY,EndX,EndY);
  ssd1963_SetCursor(StartX,StartY);
  
  GPIO_ResetBits(LCD_CTRL_PORT_CS,LCD_CTRL_PIN_CS);//Clr_Cs;
  ssd1963_WriteIndex(0x002C);
  GPIO_SetBits(LCD_CTRL_PORT_RS,LCD_CTRL_PIN_RS);//Set_Rs;
  for (i=0;i<(EndX*EndY);i++)
  {
      ssd1963_WriteData(*pic++);
  }
  GPIO_SetBits(LCD_CTRL_PORT_CS,LCD_CTRL_PIN_CS);//Set_Cs;
  }
#endif
}

/****************************************************************************
* void ssd1963_PutChar(unsigned int x,unsigned int y,unsigned char c,unsigned int charColor,unsigned int bkColor)
*
* Parameters: x     x coordonate
*             y     y coordonate
*             c     character
*             charColor     color of the char
*             bkColor       color of the background
*
* Example uf use: ssd1963_PutChar(10,10,'a',0x0000,0xffff);
****************************************************************************/
void ssd1963_PutChar(unsigned int x,unsigned int y,unsigned char c,unsigned int charColor,unsigned int bkColor)
{
#if(LCD_Buffered)
  {
    static unsigned int i=0;
    static unsigned int j=0;  
    static unsigned char tmp_char=0;  
    static unsigned int k;
    for (i=0;i<16;i++)
  {
      k=c-0x20;
      k=k*16+i;
      tmp_char=ascii_8x16[k];
    for (j=0;j<8;j++)
    {
      if ( (tmp_char >> 7-j) & 0x01 == 0x01)
        {
          ssd1963_SetPoint(x+j,y+i,charColor); // �ַ���ɫ
        }
        else
        {
          if(bkColor!=Transparent)
            ssd1963_SetPoint(x+j,y+i,bkColor); // ������ɫ
        }
    }
  }
  }
#else
  {
  static unsigned int i=0;
  static unsigned int j=0;  
  static unsigned char tmp_char=0;  
  static unsigned int k;

  for (i=0;i<16;i++)
  {
      k=c-0x20;
      k=k*16+i;
      tmp_char=ascii_8x16[k];
    for (j=0;j<8;j++)
    {
      if ( (tmp_char >> 7-j) & 0x01 == 0x01)
        {
          ssd1963_SetPoint(x+j,y+i,charColor); // �ַ���ɫ
        }
        else
        {
          if(bkColor!=Transparent)
            ssd1963_SetPoint(x+j,y+i,bkColor); // ������ɫ
        }
    }
  }
 }
#endif
}


/****************************************************************************
* void ssd1963_PutText(unsigned int x,unsigned int y,unsigned char *pString,unsigned int charColor,unsigned int bkColor)
*
* Parameters: x     x coordonate
*             y     y coordonate
*             *pString     pointer to the array with text
*             charColor     color of the char
*             bkColor       color of the background
*
* Example uf use: ssd1963_PutText(10,10,txt,0x0000,0xffff);
****************************************************************************/
void ssd1963_PutText(unsigned int x,unsigned int y,char *pString,unsigned int charColor,unsigned int bkColor)
{
    static unsigned int xorg;

    xorg = x;

    while (*pString != 0) {
        if (*pString == '\n') {
            y += 18;
            x = xorg;
        }
        else {
            ssd1963_PutChar(x, y, *pString, charColor, bkColor);
            x += 8;
        }
        pString++;
    }
}
/****************************************************************************
* void ssd1963_Test()
*
* Parameters:
*
* Example uf use: ssd1963_Test();
****************************************************************************/
void ssd1963_Test()
{
#if(LCD_Buffered)
  {
  }
#else
  {
  unsigned char  R_data,G_data,B_data,i,j;

	ssd1963_SetCursor(0x00, 0x0000);
	ssd1963_WriteRegister(0x0050,0x00);//ˮƽ GRAM��ʼλ��
	ssd1963_WriteRegister(0x0051,239);//ˮƽGRAM��ֹλ��
	ssd1963_WriteRegister(0x0052,0);//��ֱGRAM��ʼλ��
	ssd1963_WriteRegister(0x0053,319);//��ֱGRAM��ֹλ��
	GPIO_ResetBits(LCD_CTRL_PORT_CS,LCD_CTRL_PIN_CS);//Clr_Cs; 
	ssd1963_WriteIndex(0x0022);
	GPIO_SetBits(LCD_CTRL_PORT_RS,LCD_CTRL_PIN_RS);//Set_Rs;
    R_data=0;G_data=0;B_data=0;     
    for(j=0;j<50;j++)//��ɫ��ǿ��
    {
        for(i=0;i<240;i++)
            {R_data=i/8;ssd1963_WriteData(R_data<<11|G_data<<5|B_data);
        }
    }
    R_data=0x1f;G_data=0x3f;B_data=0x1f;
    for(j=0;j<50;j++)
    {
        for(i=0;i<240;i++)
            {
            G_data=0x3f-(i/4);
            B_data=0x1f-(i/8);
            ssd1963_WriteData(R_data<<11|G_data<<5|B_data);
			}
    }
//----------------------------------
    R_data=0;G_data=0;B_data=0;
    for(j=0;j<50;j++)//��ɫ��ǿ��
    {
        for(i=0;i<240;i++)
            {G_data=i/4;
			ssd1963_WriteData(R_data<<11|G_data<<5|B_data);
        }
    }

    R_data=0x1f;G_data=0x3f;B_data=0x1f;
    for(j=0;j<50;j++)
    {
        for(i=0;i<240;i++)
            {
            R_data=0x1f-(i/8);
            B_data=0x1f-(i/8);
            ssd1963_WriteData(R_data<<11|G_data<<5|B_data);
		}
    }
//----------------------------------
 
    R_data=0;G_data=0;B_data=0;
    for(j=0;j<60;j++)//��ɫ��ǿ��
    {
        for(i=0;i<240;i++)
            {B_data=i/8;
            ssd1963_WriteData(R_data<<11|G_data<<5|B_data);
        }
    } 

    B_data=0; 
    R_data=0x1f;G_data=0x3f;B_data=0x1f;

    for(j=0;j<60;j++)
    {
        for(i=0;i<240;i++)
            {
            G_data=0x3f-(i/4);
            R_data=0x1f-(i/8);
            ssd1963_WriteData(R_data<<11|G_data<<5|B_data);
		}
    }	  
	GPIO_SetBits(LCD_CTRL_PORT_CS,LCD_CTRL_PIN_CS);//Set_Cs;
  }
#endif
}

/****************************************************************************
* void ssd1963_WriteIndex(unsigned int idx)
*
* Parameters: idx   index to be written
*
* Example uf use: ssd1963_WriteIndex(0x0000);
****************************************************************************/
void ssd1963_WriteIndex(unsigned int idx)
{
    GPIO_ResetBits(LCD_CTRL_PORT_RS,LCD_CTRL_PIN_RS);//Clr_Rs;
    GPIO_SetBits(LCD_CTRL_PORT_RD,LCD_CTRL_PIN_RD);//Set_nRd;
    ssd1963_Write(idx);//LCD_Data_L_IO = (idx&0x00ff);
    //LCD_Data_H_IO = (idx/0x0100);
    /*GPIOD->ODR=idx&0x00FF;
    GPIOD->ODR|=((idx/0x0100)<<8);*/
    GPIO_ResetBits(LCD_CTRL_PORT_WR,LCD_CTRL_PIN_WR);//Clr_nWr;
    GPIO_SetBits(LCD_CTRL_PORT_WR,LCD_CTRL_PIN_WR);//Set_nWr;
    GPIO_SetBits(LCD_CTRL_PORT_RS,LCD_CTRL_PIN_RS);//Set_Rs;
}

/****************************************************************************
* void ssd1963_WriteData(unsigned int data)
*
* Parameters: data   data to be written
*
* Example uf use: ssd1963_WriteData(0x1030)
****************************************************************************/
void ssd1963_WriteData(unsigned int data)
{
  ssd1963_Write(data);//&0x00ff;
  //GPIOD->ODR|=((data/0x0100)<<8);
   /* LCD_Data_L_IO = (data&0x00ff);
    LCD_Data_H_IO = (data/0x0100);*/
    GPIO_ResetBits(LCD_CTRL_PORT_WR,LCD_CTRL_PIN_WR);//Clr_nWr;
    GPIO_SetBits(LCD_CTRL_PORT_WR,LCD_CTRL_PIN_WR);//Set_nWr;
}


/****************************************************************************
* void ssd1963_WriteRegister(unsigned int index,unsigned int data)
*
* Parameters: index     index to be written
*             data      data to be written
*
* Example uf use: ssd1963_WriteRegister(0x0000,0x0001);
****************************************************************************/
void ssd1963_WriteRegister(unsigned int index,unsigned int data)
{
 /************************************************************************
  **                                                                    **
  ** nCS       ----\__________________________________________/-------  **
  ** RS        ------\____________/-----------------------------------  **
  ** nRD       -------------------------------------------------------  **
  ** nWR       --------\_______/--------\_____/-----------------------  **
  ** DB[0:15]  ---------[index]----------[data]-----------------------  **
  **                                                                    **
  ************************************************************************/
    GPIO_ResetBits(LCD_CTRL_PORT_CS,LCD_CTRL_PIN_CS);//Clr_Cs;
    GPIO_ResetBits(LCD_CTRL_PORT_RS,LCD_CTRL_PIN_RS);//Clr_Rs;
    GPIO_SetBits(LCD_CTRL_PORT_RD,LCD_CTRL_PIN_RD);//Set_nRd;
    ssd1963_Write(index);
    /*GPIOD->ODR=(index&0x00ff);
    GPIOD->ODR|=((index/0x0100)<<8);*/
    /*LCD_Data_L_IO = (index&0x00ff);
    LCD_Data_H_IO = (index/0x0100);*/
    
    GPIO_ResetBits(LCD_CTRL_PORT_WR,LCD_CTRL_PIN_WR);//Clr_nWr;
    GPIO_SetBits(LCD_CTRL_PORT_WR,LCD_CTRL_PIN_WR);//Set_nWr;
    GPIO_SetBits(LCD_CTRL_PORT_RS,LCD_CTRL_PIN_RS);//Set_Rs;

    ssd1963_Write(data);
    /*GPIOD->ODR=(data&0x00ff);
    GPIOD->ODR|=((data/0x0100)<<8);*/
    /*LCD_Data_L_IO = (data&0x00ff);
    LCD_Data_H_IO = (data/0x0100);*/
    GPIO_ResetBits(LCD_CTRL_PORT_WR,LCD_CTRL_PIN_WR);//Clr_nWr;
    GPIO_SetBits(LCD_CTRL_PORT_WR,LCD_CTRL_PIN_WR);//Set_nWr;
    GPIO_SetBits(LCD_CTRL_PORT_CS,LCD_CTRL_PIN_CS);//Set_Cs;
  
}

/****************************************************************************
* void ssd1963_Reset()
*
* Parameters:
*
* Example uf use: ssd1963_Reset();
****************************************************************************/

void ssd1963_Reset()
{
  
  /***************************************
   **                                   **
   **  -------\______________/-------   **
   **         | <---Tres---> |          **
   **                                   **
   **  Tres: Min.1ms                    **
   ***************************************/
    
  	GPIO_SetBits(LCD_CTRL_PORT_RST,LCD_CTRL_PIN_RST);;//Set_Rst;;
    ssd1963_Delay(50000);
  	GPIO_ResetBits(LCD_CTRL_PORT_RST,LCD_CTRL_PIN_RST);//Clr_Rst;
    ssd1963_Delay(50000);
  	GPIO_SetBits(LCD_CTRL_PORT_RST,LCD_CTRL_PIN_RST);//Set_Rst;
    ssd1963_Delay(50000);
}

/****************************************************************************
* void ssd1963_BackLight(unsigned char status)
*
* Parameters: status    status of the backlight
*
* Example uf use: ili9320_BackLight(1);
****************************************************************************/
void ssd1963_BackLight(unsigned char status)
{
  if ( status >= 1 )
  {
    GPIO_SetBits(LCD_CTRL_PORT_LEDA,LCD_CTRL_PIN_LEDA);
   ;// Lcd_Light_ON;
  }
  else
  {
    GPIO_ResetBits(LCD_CTRL_PORT_LEDA,LCD_CTRL_PIN_LEDA);
   ;// Lcd_Light_OFF;
  }
}

/****************************************************************************
* void ssd1963_Delay(unsigned long nCount)
*
* Parameters: nCount    delay length
*
* Example uf use: ssd1963_Delay(10000);
****************************************************************************/
void ssd1963_Delay(unsigned long nCount)
{
  for(; nCount != 0; nCount--);
}

/****************************************************************************
* void ssd1963_PutLine(unsigned int x,unsigned int y,unsigned char axe, unsigned int length,unsigned int Color)
*
* Parameters: x         x coordonate of the begin of the line
*             y         y coordonate of the begin of the line
*             axe       the axe
*             length    length of the line
*             Color     color of line pixels
*
* Example uf use: ssd1963_PutLine(5, 110, 'X', 470, Black);
****************************************************************************/
void ssd1963_PutLine(unsigned int x,unsigned int y,unsigned char axe, unsigned int length,unsigned int Color)
{
    if(axe == 'X') {
        for(;length>0;length--) {
            ssd1963_SetPoint(x++,y,Color);
        }
    }
    else
        if(axe == 'Y'){
            for(;length>0;length--) {
                ssd1963_SetPoint(x,y++,Color);
            }
        }
}

void LCD_Circle(int Xpos,int Ypos, int Radius,unsigned int Color)
{ //algo d'Andres
  int  D;/* Decision Variable */
  int  CurX;/* Current X Value */
  int  CurY;/* Current Y Value */

  D = Radius - 1;
  CurX = 0;
  CurY = Radius;
  while (CurY >= CurX)  {
    ssd1963_SetPoint( Xpos + CurX, Ypos + CurY,Color);
    ssd1963_SetPoint(Xpos + CurX, Ypos - CurY,Color);
    ssd1963_SetPoint(Xpos - CurX, Ypos + CurY,Color);
    ssd1963_SetPoint(Xpos - CurX, Ypos - CurY,Color);
    ssd1963_SetPoint(Xpos + CurY, Ypos + CurX,Color);
    ssd1963_SetPoint(Xpos + CurY, Ypos - CurX,Color);
    ssd1963_SetPoint(Xpos - CurY, Ypos + CurX,Color);
    ssd1963_SetPoint(Xpos - CurY, Ypos - CurX,Color);
    if (D >= 2 * CurX)
    {
      D = D - 2 * CurX - 1;
      CurX++;
    }
    else if (D <= (2*(Radius-CurY)))
    {
      D = D + 2 * CurY - 1;
      CurY--;
    }
    else
    {
    	 D += 2 * (CurY - CurX - 1);
    	 CurY--;
    	 CurX++;
    }

  }
}

void LCD_Fill_Circle(int Xpos, int Ypos, int Radius,unsigned int Color)
{
	while(Radius >= 0){
		LCD_Circle(Xpos,Ypos,Radius,Color);
		Radius--;
	}
}

void ssd1963_Write(int data)
{
  
  GPIOA->ODR&=0x30;//0b0000 0000 0011 0000
  GPIOA->ODR|=(data&0xFFCF);//0b1111 1111 1100 1111
 
  GPIOB->ODR&=0xFFCF;
  GPIOB->ODR|=(data&0x30);
  wait(3);

 /* GPIO_ResetBits(GPIOA,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15);
  GPIO_ResetBits(GPIOB,GPIO_Pin_4|GPIO_Pin_5);
  
  GPIO_SetBits(GPIOA,data&(GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15));
  GPIO_SetBits(GPIOB,data&(GPIOB,GPIO_Pin_4|GPIO_Pin_5));
 */
 
  /*
  GPIO_WriteBit(LCD_DATA_PORT_DB0,LCD_DATA_PIN_DB0,(data&(1<<0))>>0);
  GPIO_WriteBit(LCD_DATA_PORT_DB1,LCD_DATA_PIN_DB1,(data&(1<<1))>>1);
  GPIO_WriteBit(LCD_DATA_PORT_DB2,LCD_DATA_PIN_DB2,(data&(1<<2))>>2);
  GPIO_WriteBit(LCD_DATA_PORT_DB3,LCD_DATA_PIN_DB3,(data&(1<<3))>>3);
  GPIO_WriteBit(LCD_DATA_PORT_DB4,LCD_DATA_PIN_DB4,(data&(1<<4))>>4);
  GPIO_WriteBit(LCD_DATA_PORT_DB5,LCD_DATA_PIN_DB5,(data&(1<<5))>>5);
  GPIO_WriteBit(LCD_DATA_PORT_DB6,LCD_DATA_PIN_DB6,(data&(1<<6))>>6);
  GPIO_WriteBit(LCD_DATA_PORT_DB7,LCD_DATA_PIN_DB7,(data&(1<<7))>>7);
  GPIO_WriteBit(LCD_DATA_PORT_DB8,LCD_DATA_PIN_DB8,(data&(1<<8))>>8);
  GPIO_WriteBit(LCD_DATA_PORT_DB9,LCD_DATA_PIN_DB9,(data&(1<<9))>>9);
  GPIO_WriteBit(LCD_DATA_PORT_DB10,LCD_DATA_PIN_DB10,(data&(1<<10))>>10);
  GPIO_WriteBit(LCD_DATA_PORT_DB11,LCD_DATA_PIN_DB11,(data&(1<<11))>>11);
  GPIO_WriteBit(LCD_DATA_PORT_DB12,LCD_DATA_PIN_DB12,(data&(1<<12))>>12);
  GPIO_WriteBit(LCD_DATA_PORT_DB13,LCD_DATA_PIN_DB13,(data&(1<<13))>>13);
  GPIO_WriteBit(LCD_DATA_PORT_DB14,LCD_DATA_PIN_DB14,(data&(1<<14))>>14);
  GPIO_WriteBit(LCD_DATA_PORT_DB15,LCD_DATA_PIN_DB15,(data&(1<<15))>>15);*/
  
}
void LCD_WriteBuff(unsigned int data)
{
  ImageToWrite[cursor++]=data;  
  if(cursor==cursor_at_end_of_first_line+((int)((cursor-cursor_at_end_of_first_line)/482))*482)
    cursor+=(482-(LCD_Window_EndX-LCD_Window_StartX));  
}

void LCD_Refresh()
{
#if(LCD_Buffered)
    GPIO_ResetBits(LCD_CTRL_PORT_CS,LCD_CTRL_PIN_CS);//Clr_Cs; 
    ssd1963_WriteIndex(0x002c);
    GPIO_SetBits(LCD_CTRL_PORT_RS,LCD_CTRL_PIN_RS);//Set_Rs;
  
    for (long i=0; i<482*272; i++)   
    {      
          ssd1963_WriteData(LCD_buff[i]);      
    }

  GPIO_SetBits(LCD_CTRL_PORT_CS,LCD_CTRL_PIN_CS);//Set_Cs;  
  
#endif
}
  static int xcoord;
void Clean_LCD_Buff()
{
  ImageToWrite = LCD_buff;
  for(long i=0;i<481*273;i++)
  {
   LCD_buff[i]=0;
   LCD_RshMsk[i]=1;
  }
    
 /*ssd1963_SetWindows(10,50,160,210);
    for (long i=0; i<150*150; i++)
    {
            LCD_WriteBuff(0xFFFF);
            
            //wait(100);
            
    }
   LCD_Refresh();*/
/*while(1)
{
  ssd1963_SetPoint(50,0,0xFFFF);
  ssd1963_SetPoint(50,1,Green);
  ssd1963_SetPoint(50,20,Red);
      LCD_Refresh();
     // wait(1);
}*/
}

