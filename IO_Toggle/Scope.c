#include <main.h>

void Scope_Clear_Path(int);
void Draw_Scope_Grid();
void Draw_Scope_Window();
void Activate_Scope()
{
  if(Scope_Active==0)
  {
    Scope_Active=1;
    sample_counter=0;
    last_sample_count=0;
    Scope_ADC_init();
    
      Draw_Scope_Window();
    TIM_ScopeTrig_init(Scope_Sample_Rate);
  }
}

void DeActivate_Scope()
{
  Scope_Active=0;
}

void ADC_IRQ()
{
   //sample_counter++;
    
   
   sample_buff[sample_counter++]=ADC_GetConversionValue(ADC1);
   /*static int b;
   char print[20];
   sprintf(print,"ADC IRQ:%d",sample_counter);
   ssd1963_PutText(20,170,print,Black,White);*/
   
  // if(sample_counter>=10)
    // LCD_Refresh_task();
   /*{
     
    for(int i=0;i<sample_counter;i++)
    {
      y=(sample_buff[i]-20)*10;
      x+=Scope_X_Step;
      LCD_Draw_Rectangle(x,y,Scope_Dot_Size,Scope_Dot_Size,ScopeA_Color);
      if(Scope_Use_Interpolation)
      {
        Draw_Line(x_old,y_old,x,y,ScopeA_Color);
        
      }
      if(Scope_Autoclear)
        Scope_Clear_Path(x);
      if(x>475)
        x=0;
    }
    x_old=x;
    y_old=y;
    char print[20];
    sprintf(print,"Samples:%d",x);
    ssd1963_PutText(20,200,print,Black,Transparent);
    sample_counter=0;
      //LCD_Refresh_task();
   }*/
  
  
 // static int x,y,x_old,y_old;
      
     // ADC_ClearITPendingBit(ADC1,ADC_IT_EOC);     
      //char value[10];
      //int a=ADC_GetConversionValue(ADC1);
      //sprintf(value,"ADC:%d",a);   
      //ssd1963_PutText(10, 85, value, Yellow, Black);
   
}

void Scope_Clear_Path(int X)
{
  static int last_clear_rectangle;
  int Divs=((int)(X/Scope_Grid+1))*Scope_Grid;
  if((X+Scope_Dot_Size+3+Scope_Grid)<Scope_Window_dX-2)
  {
    
    LCD_Draw_Rectangle(X+Scope_Dot_Size+3,4,Scope_Grid,Scope_Window_dY-7,Black);
    last_clear_rectangle=X;
    
  for(int i=3;i<Scope_Window_dY-2;i+=Scope_Grid)
    ssd1963_PutLine(X+Scope_Dot_Size+3,i,'X',Scope_Grid,Scope_Grid_Color);
  
  ssd1963_PutLine(Divs+3,3,'Y',Scope_Window_dY-6,Scope_Grid_Color);
  }
}
                    
void Draw_Scope_Grid()
{
  for(int x=3;x<Scope_Window_dX-3;x+=Scope_Grid)
  {
    ssd1963_PutLine(x,3,'Y',Scope_Window_dY-6,Scope_Grid_Color);
  }
    for(int y=3;y<Scope_Window_dY-3;y+=Scope_Grid)    
      ssd1963_PutLine(3,y,'X',Scope_Window_dX-6,Scope_Grid_Color);
      
}

void Draw_Scope_Window()
{
  if(Scope_Grid_Enabled)
      Draw_Scope_Grid();
   //Draw Signal Frame
  ssd1963_PutLine(0,0,'X',Scope_Window_dX,Blue);
  ssd1963_PutLine(2,2,'X',Scope_Window_dX-4,Blue);
  ssd1963_PutLine(2,Scope_Window_dY-2,'X',Scope_Window_dX-4,Blue);
  ssd1963_PutLine(0,Scope_Window_dY,'X',Scope_Window_dX,Blue);
  
  ssd1963_PutLine(0,0,'Y',Scope_Window_dY,Blue);
  ssd1963_PutLine(2,2,'Y',Scope_Window_dY-4,Blue);
  ssd1963_PutLine(Scope_Window_dX-2,2,'Y',Scope_Window_dY-4,Blue);
  ssd1963_PutLine(Scope_Window_dX,0,'Y',Scope_Window_dY,Blue);
     
  //Draw Setup Frame
  ssd1963_PutLine(Scope_Window_dX+1,0,'X',480-(Scope_Window_dX+1),Blue);
  ssd1963_PutLine(Scope_Window_dX+3,2,'X',478-(Scope_Window_dX+1)-2,Blue);
  ssd1963_PutLine(Scope_Window_dX+3,Scope_Window_dY-2,'X',478-(Scope_Window_dX+1)-2,Blue);
  ssd1963_PutLine(Scope_Window_dX+1,Scope_Window_dY,'X',480-(Scope_Window_dX+1),Blue);
  
  ssd1963_PutLine(Scope_Window_dX+1,0,'Y',Scope_Window_dY,Blue);
  ssd1963_PutLine(Scope_Window_dX+3,3,'Y',Scope_Window_dY-5,Blue);
  ssd1963_PutLine(477,3,'Y',Scope_Window_dY-5,Blue);
  ssd1963_PutLine(479,0,'Y',Scope_Window_dY,Blue);
  
  //Draw Measurement Frame
  ssd1963_PutLine(0,Scope_Window_dY+1,'X',Scope_Window_dX,Blue);
  ssd1963_PutLine(2,Scope_Window_dY+3,'X',Scope_Window_dX-4,Blue);
  ssd1963_PutLine(2,269,'X',Scope_Window_dX-4,Blue);
  ssd1963_PutLine(0,271,'X',Scope_Window_dX,Blue);
  
  ssd1963_PutLine(0,Scope_Window_dY+1,'Y',271-Scope_Window_dY,Blue);
  ssd1963_PutLine(2,Scope_Window_dY+3,'Y',271-Scope_Window_dY-4,Blue);
  ssd1963_PutLine(Scope_Window_dX-2,Scope_Window_dY+3,'Y',271-Scope_Window_dY-2,Blue);
  ssd1963_PutLine(Scope_Window_dX,Scope_Window_dY+1,'Y',271-Scope_Window_dY,Blue);
  
  //Draw Menu Frame
  ssd1963_PutLine(Scope_Window_dX+1,Scope_Window_dY+1,'X',480-Scope_Window_dX,Blue);
  ssd1963_PutLine(Scope_Window_dX+3,Scope_Window_dY+3,'X',480-Scope_Window_dX,Blue);
  ssd1963_PutLine(Scope_Window_dX+3,269,'X',480-Scope_Window_dX,Blue);
  ssd1963_PutLine(Scope_Window_dX+1,271,'X',480-Scope_Window_dX,Blue);
  
  ssd1963_PutLine(Scope_Window_dX+1,Scope_Window_dY+1,'Y',271-Scope_Window_dY,Blue);
  ssd1963_PutLine(Scope_Window_dX+3,Scope_Window_dY+3,'Y',271-Scope_Window_dY-3,Blue);
  ssd1963_PutLine(477,Scope_Window_dY+3,'Y',271-Scope_Window_dY-1,Blue);
  ssd1963_PutLine(479,Scope_Window_dY+1,'Y',271-Scope_Window_dY,Blue);
  
  //Menu Text
  char menu_txt[5];
  sprintf(menu_txt,"MENU");
  ssd1963_PutText(405,245,menu_txt,Yellow,Black);
  
  //Volt Setup Button
  Button But_Volt;
  Init_Button(&But_Volt);
  But_Volt.Text_Align_X=TEXT_ALIGN_CENTER;
  But_Volt.Text_Align_Y=TEXT_ALIGN_CENTER;
  But_Volt.x=391;
  But_Volt.y=10;
  But_Volt.dx=80;
  But_Volt.text="VOLT";
  Add_Button(&But_Volt);
  
   //Time Setup Button
  Button But_Time;
  Init_Button(&But_Time);
  But_Time.Text_Align_X=TEXT_ALIGN_CENTER;
  But_Time.Text_Align_Y=TEXT_ALIGN_CENTER;
  But_Time.x=391;
  But_Time.y=45;
  But_Time.dx=80;
  But_Time.text="TIME";
  Add_Button(&But_Time);
  
   //Trig Setup Button
  Button But_Trig;
  Init_Button(&But_Trig);
  But_Trig.Text_Align_X=TEXT_ALIGN_CENTER;
  But_Trig.Text_Align_Y=TEXT_ALIGN_CENTER;
  But_Trig.x=391;
  But_Trig.y=80;
  But_Trig.dx=80;
  But_Trig.text="TRIG";
  Add_Button(&But_Trig);
  
}




