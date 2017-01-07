#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>
#include <macro.h>
#include "mock_avrio.h"

#define TRUE            0x01
#define FALSE           0x00

/* ADC reference voltage */
#define VCC_REF         0x00
#define AVCC_REF        0x01
#define INTERNAL_REF    0x02   /* internal 1.1 volt ref */

/* ADC channel */
#define ADC_CH0         0x00
#define ADC_CH1         0x01
#define ADC_CH2         0x02
#define ADC_CH3         0x03
#define ADC_CH4         0x04
#define ADC_CH5         0x05
#define ADC_CH6         0x06
#define ADC_CH7         0x07
#define ADC_CH8         0x08
#define VBG_READ        0x0E  /* 1.1V (VBG) */
#define GND_READ        0x0F  /* 0V (GND) */

/* function like macros */
#define adc_enable      (sbit(ADCSRA, ADEN))
#define adc_disable     (cbit(ADCSRA, ADEN))

typedef struct ADC_ADC_Config
{
  uint8_t ref;
} ADC_Config;

extern uint8_t ADC_initModule (const ADC_Config *config);
#endif
