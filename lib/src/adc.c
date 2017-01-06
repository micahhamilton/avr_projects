#include "adc.h"
#include <stdio.h>

extern uint8_t ADC_initModule(const ADC_Config *config)
{
  switch (config->mode) {
    case MY_MODE:
      printf("you are in my mode\n");
      return 0x00;
    case 0x01:
      printf("you ain't in my mode\n");
      return 0x01;
  }

  return 0x01;
}
