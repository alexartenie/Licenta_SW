#include <main.h>
//#include "ff.h"

#define TEXT_ALIGN_LEFT 0
#define TEXT_ALIGN_CENTER 1
#define TEXT_ALIGN_RIGHT 2
#define TEXT_ALIGN_TOP 3
#define TEXT_ALIGN_BOTTOM 4

typedef struct
{
  short added;
  int x;
  int y;
  int dx;
  int dy;
  int back_color;
  int frame_color;
  char* text;
  int text_color;
  int Text_Align_X;
  int Text_Align_Y;
}Button;

#if LCD_Buffered
  int LCD_Buffer[480*272];
#endif

void Draw_Button_Frame(Button*);

void LCD_Draw_Rectangle(int x,int y,int dx,int dy,int color)
{
#if LCD_Buffered
  {
    for (int i=0; i<dx; i++)
        for(int j=0; j<dy; j++)
            LCD_Buffer[i][j]=color;
  }
#else
    ssd1963_ClearZone(x,y,dx,dy,color);
#endif
}

void Add_Button(Button* B)
{
 if(B->added!=1)
  {
      char txt[20];
      sprintf(txt,"size:%d",sizeof(B->text));
      ssd1963_PutText(20,20,txt,Black,White);
      Draw_Button_Frame(B);
      LCD_Draw_Rectangle(B->x,B->y,B->dx,B->dy,B->back_color);
      switch(B->Text_Align_X)
      {
        case TEXT_ALIGN_LEFT:   switch(B->Text_Align_Y)
                                {
                                  case TEXT_ALIGN_TOP:
                                            ssd1963_PutText(B->x+1,B->y+1,B->text,B->text_color,Transparent);break;
                                  case TEXT_ALIGN_CENTER:
                                            ssd1963_PutText(B->x+1,B->y+B->dy/2-7,B->text,B->text_color,Transparent);break;
                                  case TEXT_ALIGN_BOTTOM:
                                            ssd1963_PutText(B->x+1,B->y+B->dy-14,B->text,B->text_color,Transparent);break;
                                }break;
        case TEXT_ALIGN_CENTER: switch(B->Text_Align_Y)
                                {
                                  case TEXT_ALIGN_TOP:
                                            ssd1963_PutText(B->x+(B->dx/2)-sizeof(B->text)/2*7,B->y+1,B->text,B->text_color,Transparent);break;
                                  case TEXT_ALIGN_CENTER:
                                            ssd1963_PutText(B->x+(B->dx/2)-sizeof(B->text)/2*7,B->y+B->dy/2-7,B->text,B->text_color,Transparent);break;
                                  case TEXT_ALIGN_BOTTOM:
                                            ssd1963_PutText(B->x+(B->dx/2)-sizeof(B->text)/2*7,B->y+B->dy-14,B->text,B->text_color,Transparent);break;
                                }break;
        case TEXT_ALIGN_RIGHT:  switch(B->Text_Align_Y)
                                {
                                  case TEXT_ALIGN_TOP:
                                            ssd1963_PutText(B->x+B->dx-sizeof(B->text)*8,B->y+1,B->text,B->text_color,Transparent);break;
                                  case TEXT_ALIGN_CENTER:
                                            ssd1963_PutText(B->x+B->dx-sizeof(B->text)*8,B->y+B->dy/2-7,B->text,B->text_color,Transparent);break;
                                  case TEXT_ALIGN_BOTTOM:
                                            ssd1963_PutText(B->x+B->dx-sizeof(B->text)*8,B->y+B->dy-14,B->text,B->text_color,Transparent);break;
                                }break;
        default:;
      }
     //ssd1963_PutText(B->x+(B->dx/2)-sizeof(B->text)/2*7,B->y+B->dy/2-8,B->text,B->text_color,Transparent);
      B->added=1;
  }
}

void Init_Button(Button* B)
{
  B->x=0;
  B->y=0;
  B->dx=75;
  B->dy=25;
  B->back_color=Blue;
  B->frame_color=Red;
  B->text="Button";
  B->text_color=White;
  B->Text_Align_X=TEXT_ALIGN_CENTER;
  B->Text_Align_Y=TEXT_ALIGN_CENTER;
}

void Move_Button(Button* B,int X_new,int Y_new)
{
  if(B->added==1)
  {
  if((B->x>=2)&&(B->y>=2))
    LCD_Draw_Rectangle(B->x-2,B->y-2,B->dx+4,B->dy+4,Background_Color);
  else if(B->x<2)
          LCD_Draw_Rectangle(B->x,B->y-2,B->dx+2,B->dy+4,Background_Color);
        else if(B->y<2)
                 LCD_Draw_Rectangle(B->x-2,B->y,B->dx+4,B->dy+2,Background_Color);
             else if((B->x<2)&&(B->y<2))
                      LCD_Draw_Rectangle(B->x,B->y,B->dx+2,B->dy+2,Background_Color);
   
    B->x=X_new;
    B->y=Y_new;
        
    Draw_Button_Frame(B);
    LCD_Draw_Rectangle(B->x,B->y,B->dx,B->dy,B->back_color);
    ssd1963_PutText(B->x,B->y,B->text,B->text_color,B->back_color);
    B->added=1;
  }
}

void Draw_Button_Frame(Button* B)
{
  if((B->x>=2)&&(B->y>=2))
  {
    LCD_Draw_Rectangle(B->x-2,B->y-2,B->dx+4,B->dy+4,B->frame_color);
  }
  else if(B->x<2)
          LCD_Draw_Rectangle(B->x,B->y-2,B->dx+2,B->dy+4,B->frame_color);
        else if(B->y<2)
                 LCD_Draw_Rectangle(B->x-2,B->y,B->dx+4,B->dy+2,B->frame_color);
             else if((B->x<2)&&(B->y<2))
                      LCD_Draw_Rectangle(B->x,B->y,B->dx+2,B->dy+2,B->frame_color);
}

void LCD_Refresh()
{
#if LCD_Buffered
    ssd1963_SetWindows(0, 0, 67, 119);

    GPIO_ResetBits(GPIOC,LCD_CTRL_PIN_CS);//Clr_Cs;
    ssd1963_WriteIndex(0x002c);
    GPIO_SetBits(GPIOC,LCD_CTRL_PIN_RS);//Set_Rs;
  
    for (int i=0; i<67; i++)
        for(int j=0; j<119; j++)
            ssd1963_WriteData(LCD_Buffer[i][j]);
#endif
}

void Draw_Image(int x,int y,int dx,int dy,unsigned long img[],int Transparency)
{
  /*for (int i = y; i <y + dy; i++)
        for (int j = x; j < x+dx; j++) {
         // if(Transparency==1)
            if((img[j-x + (i-y) * dx])<=0xFFFF-Transparency)
              ssd1963_SetPoint(j, i, img[j-x + (i-y) * dx]);
         // if(Transparency==0)
           // ssd1963_SetPoint(j, i, img[j-x + (i-y) * dx]);
        }*/
  
  
   unsigned int  i;
  //ssd1963_SetWindows(x,y,EndX,EndY);
  ssd1963_SetCursor(x,y);
  
  GPIO_ResetBits(LCD_CTRL_PORT_CS,LCD_CTRL_PIN_CS);//Clr_Cs;
  ssd1963_WriteIndex(0x002C);
  GPIO_SetBits(LCD_CTRL_PORT_RS,LCD_CTRL_PIN_RS);//Set_Rs;
  for (i=0;i<(dx*dy);i++)
  {
      ssd1963_WriteData(img[i]);
  }
  GPIO_SetBits(LCD_CTRL_PORT_CS,LCD_CTRL_PIN_CS);//Set_Cs;
}


void Menu_Enter()
{
  Button button1;
  button1.x=311;
  button1.x=311;
  button1.y=95;
  button1.dx=60;
  button1.dy=58;
  button1.text="ON/OFF";
  button1.back_color=-16256;
  Add_Button(&button1);
}

void Draw_Line(int x1,int y1,int x2,int y2,int color)
{
  if((x2>=x1)&&(y2>=y1))//Both Pozitive
  {
  float dx=x2-x1;
  float dy=y2-y1;
  float Dyx=dy/dx;
  float Dxy=dx/dy;
  float y=y1;
  float x=x1;
  for(int i=x1;i<=x2;i++)
    ssd1963_SetPoint(i,y+=Dyx,color);
  for(int j=y1;j<=y2;j++)
    ssd1963_SetPoint(x+=Dxy,j,color);
  }
  else if((x2>=x1)&&(y2<y1))//X-positive,Y-negative
  {
  float dx=x2-x1;
  float dy=y1-y2;
  float Dyx=dy/dx;
  float Dxy=dx/dy;
  float y=y2;
  float x=x1;
  for(int i=x1;i<=x2;i++)
    ssd1963_SetPoint(i,y+=Dyx,color);
 /* for(int j=y2;j<=y1;j++)
    ssd1963_SetPoint(x+=Dxy,j,color);*/
  }
  else if((x2<x1)&&(y2>=y1))
  {
  float dx=x2-x1;
  float dy=y2-y1;
  float Dyx=dy/dx;
  float Dxy=dx/dy;
  float y=y1;
  float x=x1;
  for(int i=x1;i<x2;i++)
    ssd1963_SetPoint(i,y+=Dyx,color);
  for(int j=y1;j<y2;j++)
    ssd1963_SetPoint(x+=Dxy,j,color);
  }
  else if((x2<x1)&&(y2<y1))
  {
  float dx=x2-x1;
  float dy=y2-y1;
  float Dyx=dy/dx;
  float Dxy=dx/dy;
  float y=y1;
  float x=x1;
  for(int i=x1;i<x2;i++)
    ssd1963_SetPoint(i,y+=Dyx,color);
  for(int j=y1;j<y2;j++)
    ssd1963_SetPoint(x+=Dxy,j,color);
  }
  
}

void ReadImageSD(char* name)
{
  
}

void LCD_SD_Mount()
{
  char print[20];
 // TerminalSend("Start init sd\n");
  sprintf(print,"Start init sd");
  ssd1963_PutText(20,200,print,Black,White);
   // mount the file system, using logical disk 0.
      rc = f_mount(0, &fatfs);
      if(rc != FR_OK)
      {
         // TerminalSend("f_mount error\n");
          sprintf(print,"f_mount error");
          ssd1963_PutText(20,220,print,Black,White);
         // return 0;
      }
      else
      {
    	 // TerminalSend("f_mount success!\n");
          sprintf(print,"f_mount success!");
          ssd1963_PutText(20,240,print,Black,White);
      }
}

void LCD_SD_CreateFile(char* name)
{
  char print[20];
  rc = f_open(&fil, "lol.txt", FA_CREATE_ALWAYS | FA_WRITE);
  if(rc != FR_OK)
  {
     // TerminalSend("f_open error\n");
      sprintf(print,"f_open error");
      ssd1963_PutText(20,200,print,Black,White);
      //return 0;
   }
   else
   {
     // TerminalSend("new file created\n");
      sprintf(print,"new file created");
      ssd1963_PutText(20,220,print,Black,White);
    }
}

void LCD_SD_Write(char buffer[])
{  

  char print[20];
  //TerminalSend("writing to file\n");
  sprintf(print,"writing to file");
  ssd1963_PutText(180,200,print,Black,White);
         for(int i = 0 ; i < 10000 ; i++)
         {
           
         	rc = f_write(&fil, print, 20,/* (UINT)gets((char *)buffer),*/ &bw);             
         	if(rc != FR_OK)
         	{
         		  //TerminalSend("f_write error\n");
                          sprintf(print,"f_write error   ");
                          ssd1963_PutText(20,200,print,Black,White);
         		return;
         	}
         }
         //TerminalSend("done writing\n");
         sprintf(print,"done writing");
         ssd1963_PutText(20,200,print,Black,White);
}


























































