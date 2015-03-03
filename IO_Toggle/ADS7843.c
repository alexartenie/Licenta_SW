
//#include <p32xxxx.h>
//include <plib.h>
#include "ADS7843.h"
#include <touch.h>

int Touch_Counter=0;
signed int TouchY, TouchX;
signed int Touch_Buffer[2][10];



void Touch_Init(void)		// Initialises the touch screen
{

//    if(TouchStat==1)	return;		// Already initialised and operating
/*
	if(TouchStat==2)	// Currently in sleep mode. Need to disable CN interrupts before continuing with normal initialise.
	{
		// Disables only the change notice pin being used	
//		mCNOpen(CN_ON | CN_IDLE_CON, Touch_PenIRQ_CN_Disable, CN_PULLUP_DISABLE_ALL);	

		// Disables all change notice pins. Comment out if using for other functions
		mCNClose();
		ConfigIntCN(CHANGE_INT_OFF);
	}
*/

//		Buzzer_ODC = 1;					//Sets open drain output for the buzzer
//		Buzzer_TRIS = 0;				// Sets the buzzer to an output
//		Buzzer = 1;

		TOUCH_CS_HIGH;					// Sets CS to a 1


//		OpenSPI2(FRAME_ENABLE_OFF|ENABLE_SDO_PIN|SPI_MODE8_ON|SPI_SMP_ON|SPI_CKE_OFF|CLK_POL_ACTIVE_HIGH|MASTER_ENABLE_ON|SEC_PRESCAL_4_1|PRI_PRESCAL_4_1, SPI_ENABLE);

//		OpenTimer1(T1_ON | T1_SOURCE_INT | T1_PS_1_8, 15000);	// opens the timer 1 interrupt to read the touch screen at about 40 Hz
//                ConfigIntTimer1(T1_INT_ON | T1_INT_PRIOR_7);
//  		INTEnableSystemMultiVectoredInt();

//		TouchStat = 1;
		

}



unsigned int ReadTouchXY(void)
{
	Touch_Counter++;
        
	if(Touch_Counter==10)   {
            Touch_Counter = 0;
        }

//	unsigned int i;
//        unsigned int j;
	if(TOUCH_READ_INT_PIN == 1)
	{
		TouchY = 0;  
		TouchX = 0; 

		Touch_Buffer[0][0] = 0;
		Touch_Buffer[0][1] = 0;
		Touch_Buffer[0][2] = 0;
		Touch_Buffer[0][3] = 0;
		Touch_Buffer[0][4] = 0;
		Touch_Buffer[0][5] = 0;
		Touch_Buffer[0][6] = 0;
		Touch_Buffer[0][7] = 0;
		Touch_Buffer[0][8] = 0;
		Touch_Buffer[0][9] = 0; 
		Touch_Buffer[1][0] = 0;
		Touch_Buffer[1][1] = 0;
		Touch_Buffer[1][2] = 0;
		Touch_Buffer[1][3] = 0;
		Touch_Buffer[1][4] = 0;
		Touch_Buffer[1][5] = 0;
		Touch_Buffer[1][6] = 0;
		Touch_Buffer[1][7] = 0;
		Touch_Buffer[1][8] = 0;
		Touch_Buffer[1][9] = 0; 

		return 0; // A return of 0 means no touch is detected
	
	}
	else
	{
		TOUCH_INT_AS_OUTPUT;			// Sets the PenIRQ to an output
		TOUCH_INT_LOW;			// Drives the PenIRQ low so the diode is not forward biased

//		while(!Touch_Busy);				// Makes sure the touch screen isn't busy
			

	// Now the actual small bit of code to send the data
		TOUCH_CS_LOW;					// Sets CS to a 0
		TOUCH_SCK_LOW;
		PulseTouch_CLK();		
		TOUCH_MOSI_HIGH;
		PulseTouch_CLK();		
		TOUCH_MOSI_LOW;
		PulseTouch_CLK();		
		TOUCH_MOSI_LOW;
		PulseTouch_CLK();		
		TOUCH_MOSI_HIGH;
		PulseTouch_CLK();		
		TOUCH_MOSI_HIGH;
		PulseTouch_CLK();		
		TOUCH_MOSI_HIGH;
		PulseTouch_CLK();		
		TOUCH_MOSI_LOW;
		PulseTouch_CLK();		
		TOUCH_MOSI_LOW;
		PulseTouch_CLK();

		TDelay();
		TDelay();
		TDelay();

		Touch_Buffer[0][Touch_Counter] = Touch_Read()<<15;
		Touch_Buffer[0][Touch_Counter] += Touch_Read()<<14;
		Touch_Buffer[0][Touch_Counter] += Touch_Read()<<13;
		Touch_Buffer[0][Touch_Counter] += Touch_Read()<<12;
		Touch_Buffer[0][Touch_Counter] += Touch_Read()<<11;
		Touch_Buffer[0][Touch_Counter] += Touch_Read()<<10;
		Touch_Buffer[0][Touch_Counter] += Touch_Read()<<9;
		Touch_Buffer[0][Touch_Counter] += Touch_Read()<<8;
		Touch_Buffer[0][Touch_Counter] += Touch_Read()<<7;
		Touch_Buffer[0][Touch_Counter] += Touch_Read()<<6;
		Touch_Buffer[0][Touch_Counter] += Touch_Read()<<5;
		Touch_Buffer[0][Touch_Counter] += Touch_Read()<<4;
		Touch_Buffer[0][Touch_Counter] += Touch_Read()<<3;
		Touch_Buffer[0][Touch_Counter] += Touch_Read()<<2;
		Touch_Buffer[0][Touch_Counter] += Touch_Read()<<1;
		Touch_Buffer[0][Touch_Counter] += Touch_Read();

		Touch_Buffer[0][Touch_Counter]>>=3;
		Touch_Buffer[0][Touch_Counter] = 4096-Touch_Buffer[0][Touch_Counter];
		Touch_Buffer[0][Touch_Counter] -= 280;		// subtracts the offset					THESE ARE MEASURED CALIBRATION VALUES
		Touch_Buffer[0][Touch_Counter] *= 0.0936768;	// Multiplied by the range (320/(3696-280))		


		TDelay();
		TDelay();
		TDelay();


	// Now the actual small bit of code to send the data
		TOUCH_CS_LOW;					// Sets CS to a 0
		TOUCH_SCK_LOW;
		PulseTouch_CLK();		
		TOUCH_MOSI_HIGH;
		PulseTouch_CLK();		
		TOUCH_MOSI_HIGH;
		PulseTouch_CLK();		
		TOUCH_MOSI_LOW;
		PulseTouch_CLK();		
		TOUCH_MOSI_HIGH;
		PulseTouch_CLK();		
		TOUCH_MOSI_HIGH;
		PulseTouch_CLK();		
		TOUCH_MOSI_HIGH;
		PulseTouch_CLK();		
		TOUCH_MOSI_LOW;
		PulseTouch_CLK();		
		TOUCH_MOSI_LOW;
		PulseTouch_CLK();

		TDelay();
		TDelay();
		TDelay();

		Touch_Buffer[1][Touch_Counter] = Touch_Read()<<15;
		Touch_Buffer[1][Touch_Counter] += Touch_Read()<<14;
		Touch_Buffer[1][Touch_Counter] += Touch_Read()<<13;
		Touch_Buffer[1][Touch_Counter] += Touch_Read()<<12;
		Touch_Buffer[1][Touch_Counter] += Touch_Read()<<11;
		Touch_Buffer[1][Touch_Counter] += Touch_Read()<<10;
		Touch_Buffer[1][Touch_Counter] += Touch_Read()<<9;
		Touch_Buffer[1][Touch_Counter] += Touch_Read()<<8;
		Touch_Buffer[1][Touch_Counter] += Touch_Read()<<7;
		Touch_Buffer[1][Touch_Counter] += Touch_Read()<<6;
		Touch_Buffer[1][Touch_Counter] += Touch_Read()<<5;
		Touch_Buffer[1][Touch_Counter] += Touch_Read()<<4;
		Touch_Buffer[1][Touch_Counter] += Touch_Read()<<3;
		Touch_Buffer[1][Touch_Counter] += Touch_Read()<<2;
		Touch_Buffer[1][Touch_Counter] += Touch_Read()<<1;
		Touch_Buffer[1][Touch_Counter] += Touch_Read();

		Touch_Buffer[1][Touch_Counter]>>=3;
		Touch_Buffer[1][Touch_Counter] = 4096-Touch_Buffer[1][Touch_Counter];	// Inverts the x/y positions for me
		Touch_Buffer[1][Touch_Counter] -= 330;		// subtracts the offset				THESE ARE MEASURED CALIBRATION VALUES
		Touch_Buffer[1][Touch_Counter]*=0.0693641;	// Multiplied by the range (240/(3790-330))

		NOP;
		

		TOUCH_CS_HIGH;					// Sets CS to a 1
		TOUCH_INT_AS_INPUT;			// Sets the PenIRQ to an input

//		Temp = Touch_Buffer[0][Touch_Counter];
//		Temp1 = Touch_Buffer[1][Touch_Counter];

                
                int i;
		for( i=0; i!=10; i++)
		{
			if(Touch_Buffer[0][i]==0)   return 0;
		}
		TouchY = (Touch_Buffer[0][0] + Touch_Buffer[0][1] + Touch_Buffer[0][2] + Touch_Buffer[0][3] + Touch_Buffer[0][4] + Touch_Buffer[0][5] + Touch_Buffer[0][6] + Touch_Buffer[0][7] + Touch_Buffer[0][8] + Touch_Buffer[0][9])/10;

		TouchX = (Touch_Buffer[1][0] + Touch_Buffer[1][1] + Touch_Buffer[1][2] + Touch_Buffer[1][3] + Touch_Buffer[1][4] + Touch_Buffer[1][5] + Touch_Buffer[1][6] + Touch_Buffer[1][7] + Touch_Buffer[1][8] + Touch_Buffer[1][9])/10;
		
	}

}
void PulseTouch_CLK (void)
{
	TDelay();
	TOUCH_SCK_HIGH;
	TDelay();	
	TOUCH_SCK_LOW;
	TDelay();		
}

unsigned char temp;
unsigned char Touch_Read (void)
{
	TDelay();
	TOUCH_SCK_HIGH;
	TDelay();	
	temp = TOUCH_READ_MISO_PIN;
	TOUCH_SCK_LOW;
	TDelay();		
	return temp;
}


void TDelay(void)		// provides a small (~100ns) delay for the touch screen controller)
{
	NOP;
	NOP;
	NOP;
	NOP;
	NOP;
	NOP;
	NOP;
	NOP;
	NOP;
	NOP;
	NOP;
	NOP;
	NOP;
	NOP;
	NOP;
	NOP;
	NOP;
	NOP;
}

//void __ISR(_TIMER_1_VECTOR, ipl7) Timer1Handler(void)		// Timer 1 is set for about 40Hz and reads the touch screen coordinates every interrupt
//{
//	ReadTouchXY();
//    mT1ClearIntFlag();
//}
