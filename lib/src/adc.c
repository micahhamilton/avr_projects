#include "adc.h"
#include <stdio.h>

extern uint8_t adc_prescaler_select(uint8_t convert_spd)
{
  /*uint8_t i = 1, k = 2;
  if (convert_spd == ADC_FAST_CONVERSION)
    while (F_CPU/k < ADC_MAX_FREQUENCY) {
      k = (k << 1);
      ++i;
    }
  else {
    i = 7;
    k = 128;
    while (F_CPU/k > ADC_MIN_FREQUENCY) {
      k = (k >> 1);
      --i;
    }
   }  */
  return 7;
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
