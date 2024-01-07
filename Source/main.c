#define STDIO

#ifdef STDLIB
	#include <stdlib.h>
#endif

#ifdef STDIO
	#include <stdio.h>
#endif

#include "adc.h"
#include "lcd.h"

#define SIZE 6
#define BASE 10
#define PREC 2

int main(void)
{
	initADC();
	initLCD();
	
	char str[SIZE];
	int8_t iNum = -73;
	float fNum = 3.14;
	
#ifdef STDLIB
	itoa(iNum, str, BASE);
	dtostrf(fNum, 0, PREC, str);
#endif
	
#ifdef STDIO
	sprintf(str, "%d", iNum);
	sprintf(str, "%.2f", fNum);
#endif
	
	startADC();
	
	while(1)
	{
		if(isReadyADC())
		{
			sprintf(str, "%.2fV", readADC());
			
			setCursor(1, 0);
			displayLCD(str);
			
			restartADC();
		}
	}
}
