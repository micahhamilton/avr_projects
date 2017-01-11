#include "adc.h"
#include <stdio.h>

extern uint8_t adc_prescaler_select(uint8_t convert_spd)
{
  /* limit to valid cpu speeds for adc */
  if (F_CPU <= 20000000 && F_CPU >= 100000) {

    /* valid prescalers for 168/328 are 2, 4, 8, 16,     *
     * 32, 64, and 128 each corresponding to the a       *
     * consecutive number using the 3 least significant  * 
     * bits of ADCSRA.                                   */
    uint8_t i = ADC_MIN_PRESCALER, k = 1 << ADC_MIN_PRESCALER;

    /* find fastest frequncy that fits within adc frequency tolerance */
    if (convert_spd == ADC_FAST_CONVERSION)
      while (F_CPU / k > ADC_MAX_FREQUENCY) {
        k = (k << 1);
        ++i;
      } 
    /* else find slowest frequency that fits adc frequency tolerance */  
    else {
      i = ADC_MAX_PRESCALER;
      k = 1 << ADC_MAX_PRESCALER;
      while (F_CPU / k < ADC_MIN_FREQUENCY) {
        k = (k >> 1);
        --i;
      }
    }
    sbits(ADCSRA, i);
    /* return the approx. minimum conversion time in microseconds */
    return (uint8_t)(((double)k / F_CPU) * ADC_CYCLES_PER_CONVERSION * 1000000);
  } else {
    /* for now undefined state: disable adc and return -1 */
    adc_disable;
    return -1;
  }
}

extern uint8_t ADC_initModule(const ADC_Config *config)
{
  switch (config->ref) {
    case 0x00:
      printf("you are in my mode\n");
      return 0x00;
    case 0x01:
      printf("you ain't in my mode\n");
      return 0x01;
  }

  return 0x01;
}
