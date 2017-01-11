#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>

#include <macro.h>

#include "mock_avrio.h"

/*############DELETEME##################*/
#define F_CPU           8000000UL

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

/* conversion speed for prescaler selection */
#define ADC_FAST_CONVERSION             0x01
#define ADC_SLOW_CONVERSION             0x00
#define ADC_MAX_FREQUENCY               200000 
#define ADC_MIN_PERIOD                  1.0 / ADC_MAX_FREQUENCY
#define ADC_MIN_FREQUENCY               50000 
#define ADC_MAX_PERIOD                  1.0 / ADC_MIN_FREQUENCY
#define ADC_CYCLES_PER_CONVERSION       13

/* prescaler defines */
#define ADC_MAX_PRESCALER         0x07
#define ADC_MIN_PRESCALER         0x01 

/* function like macros */
#define adc_enable                  (sbit(ADCSRA, ADEN))
#define adc_disable                 (cbit(ADCSRA, ADEN))
#define adc_start_conversion        (sbit(ADCSRA, ADSC))
#define adc_auto_trigger_enable     (sbit(ADCSRA, ADATE))
#define adc_clear_interrupt_flag    (sbit(ADCSRA, ADIF))   /* write logical 1 to clear */
#define adc_interrupt_enable        (sbit(ADCSRA, ADIE))

typedef struct ADC_ADC_Config
{
  uint8_t ref;
} ADC_Config;

/* adc_prescaler_select:                              *
 * selects prescaler for fast or slow conversion time *
 * slow is better for resolution... assumes F_CPU is  *
 * defined                                            *
 * choose: ADC_FAST_CONVERSION or ADC_SLOW_CONVERSION *
 * returns: approx. minimum conversion time in usec.  */
extern uint8_t adc_prescaler_select(uint8_t convert_spd);

extern uint8_t ADC_initModule (const ADC_Config *config);

#endif
