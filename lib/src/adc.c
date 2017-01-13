#include "adc.h"
#include <stdio.h>


extern void adc_calculate_prescaler(ADC_Config *config)
{
  uint8_t i = ADC_MIN_PRESCALER;
  uint8_t k = (1 << ADC_MIN_PRESCALER);

  /* limit to valid cpu speeds for adc */
  if (F_CPU <= ADC_MAX_CPU && F_CPU >= ADC_MIN_CPU) {
    while (F_CPU / k > ADC_MAX_FREQUENCY) {
      k = (k << 1);
      ++i;
    } 
    config->fast_prescaler = i;
    config->fast_convert_us = (uint16_t)(((1.0*k) / F_CPU) * ADC_CYCLES_PER_CONVERSION * 1000000);

    /* find slowest frequency that fits adc frequency tolerance */  
    i = ADC_MAX_PRESCALER;
    k = (1 << ADC_MAX_PRESCALER);
    while (F_CPU / k < ADC_MIN_FREQUENCY) {
      k = (k >> 1);
      --i;
    }
    config->slow_prescaler = i;
    config->slow_convert_us = (uint16_t)(((1.0*k) / F_CPU) * ADC_CYCLES_PER_CONVERSION * 1000000);
  } else {
    config->slow_prescaler = config->fast_prescaler =  ADC_MAX_PRESCALER;
    config->slow_convert_us = config->fast_convert_us = ( uint16_t)(((1.0*ADC_MAX_PRESCALER) / F_CPU) * ADC_CYCLES_PER_CONVERSION * 1000000);
  }
}

extern void adc_config_default_params(ADC_Config *config)
{
  config->ref = ADC_VCC_REF;
  config->result_alignment = ADC_RIGHT_ADJUST_RESULT;
  config->speed = ADC_SLOW_CONVERSION;
  config->auto_trigger = FALSE;
  config->interrupt_driven = FALSE;
  adc_calculate_prescaler(config);
} 

extern void adc_init_module(const ADC_Config *config)
{
  adc_disable;
  adc_clear_ref;
  adc_clear_prescaler;

  adc_set_ref(config->ref);

  if (config->result_alignment == ADC_RIGHT_ADJUST_RESULT)
    adc_result_right_adj;
  else
    adc_result_left_adj;

  if (ADC_FAST_CONVERSION)
    adc_set_prescaler(config->fast_prescaler);
  else
    adc_set_prescaler(config->slow_prescaler);

  if (config->auto_trigger)
    adc_auto_trigger_enable;
  else
    adc_auto_trigger_disable;

  if (config->interrupt_driven)
    adc_interrupt_enable;
  else
    adc_interrupt_disable;
} 

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
