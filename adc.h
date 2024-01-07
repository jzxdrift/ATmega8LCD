#ifndef ADC_H
#define ADC_H

#include <stdbool.h>

void initADC(void);
void startADC(void);
bool isReadyADC(void);
float readADC(void);
void restartADC(void);

#endif