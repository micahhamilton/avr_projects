#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>

/* ADC mode */
#define MY_MODE         0x00

typedef struct ADC_ADC_Config
{
  uint8_t mode;
} ADC_Config;

extern uint8_t ADC_initModule (const ADC_Config *config);

#endif
