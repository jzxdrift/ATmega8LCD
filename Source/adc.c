#include <avr/io.h>
#include <stdbool.h>

#define VREF		5
#define ADC_BITS	_BV(10)

void initADC(void)
{
	ADCSRA |= _BV(ADEN) | _BV(ADFR);
	ADCSRA |= _BV(ADPS1) | _BV(ADPS0);		/*8 prescaler*/
	
	ADMUX |= _BV(REFS0);
	ADMUX |= _BV(MUX0);
}

void startADC(void)
{
	ADCSRA |= _BV(ADSC);
}

bool isReadyADC(void)
{
	return bit_is_set(ADCSRA, ADIF);
}

float readADC(void)
{
	return (float)ADC * VREF / ADC_BITS;
}

void restartADC(void)
{
	ADCSRA |= _BV(ADIF);
}
