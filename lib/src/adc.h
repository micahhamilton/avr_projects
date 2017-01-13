#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>

#include <macro.h>

#include "mock_avrio.h"

/*############DELETEME##################*/
#define F_CPU           8000000UL

#define TRUE            0x01
#define FALSE           0x00

/* ADC min and max cpu speeds (atmega 168/328) */
#define ADC_MAX_CPU     20000000UL
#define ADC_MIN_CPU     100000UL

/* ADC reference voltage */
#define ADC_AREF          0x00
#define ADC_VCC_REF       0x40
#define ADC_INTERNAL_REF  0xC0   /* internal 1.1 volt ref */

/* ADC result left/right adjust */
#define ADC_RIGHT_ADJUST_RESULT         ~(1 << ADLAR)
#define ADC_LEFT_ADJUST_RESULT          (1<<ADLAR)

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
#define ADC_MIN_FREQUENCY               50000 
#define ADC_CYCLES_PER_CONVERSION       13

/* prescaler defines */
#define ADC_MAX_PRESCALER         0x07
#define ADC_MIN_PRESCALER         0x01 

/* function like macros */
#define adc_enable                        (sbit(ADCSRA, ADEN))
#define adc_disable                       (cbit(ADCSRA, ADEN))
#define adc_start_conversion              (sbit(ADCSRA, ADSC))
#define adc_auto_trigger_enable           (sbit(ADCSRA, ADATE))
#define adc_auto_trigger_disable          (cbit(ADCSRA, ADATE))
#define adc_clear_interrupt_flag          (sbit(ADCSRA, ADIF))   /* write logical 1 to clear */
#define adc_interrupt_enable              (sbit(ADCSRA, ADIE))
#define adc_interrupt_disable             (cbit(ADCSRA, ADIE))
#define adc_clear_ref                     (ADMUX &= ~((1<<REFS1)|(1<<REFS0)))
#define adc_set_ref(ref)                  (ADMUX |= ref)
#define adc_result_right_adj              (cbit(ADMUX,ADLAR))
#define adc_result_left_adj               (sbit(ADMUX, ADLAR))
#define adc_set_prescaler(k)              (ADCSRA |= k)

typedef struct ADC_ADC_Config
{
  uint8_t ref;
  uint8_t result_alignment;
  uint8_t fast_prescaler;
  uint8_t slow_prescaler;
  uint16_t fast_convert_us;
  uint16_t slow_convert_us;
  uint8_t speed;
}ADC_Config;

/* adc_prescaler_frequency: finds prescaler vlaues for *
 * fastest and slowest adc clk frequencies and calcs   *
 * minimum conversion time (in microseconds) for fast  *
 * and slow conversions stores result in ADC_Config    *
 * struct                                              */
extern void adc_calculate_prescaler(ADC_Config *config);

extern void adc_config_default_params(ADC_Config *config);

extern void adc_config(ADC_Config *config);

/* adc_prescaler_select:                              *
 * selects prescaler for fast or slow conversion time *
 * slow is better for resolution... assumes F_CPU is  *
 * defined                                            *
 * choose: ADC_FAST_CONVERSION or ADC_SLOW_CONVERSION *
 * returns: approx. minimum conversion time in usec.  */
extern uint8_t adc_prescaler_select(uint8_t convert_spd);

extern uint8_t ADC_initModule (const ADC_Config *config);

#endif
