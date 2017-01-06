#include "usart0.h"

extern uint8_t USART0_initModule (const USART0_Config *config)
{
  switch (config->mode) {
    // TODO change to constants instead of magic numbers!!!
    case USART0_NORMAL_ASYNCHRONOUS:
      /* normal asynchronous */
      //USART0_setBaud(config->baudRate,
       //              USUART0_NORMAL_ASYNC_FACTOR);
    case USART0_DOUBLE_SPEED_ASYNCHRONOUS:
      /* double speed asynchronous */
    case USART0_MASTER_SYNCHRONOUS:
      /* master synchronous */
    case USART0_SLAVE_SYNCHRONOUS:
      /* slave synchronous */
    case USART0_MASTER_SPI:
      /* master SPI */
    default:
      ;/* default config and exit */
  }
  return 0;
}
  // move to appropriate cases above and use constants
  // instead of config->mode!!!
  /* calculate baudrate parameters */

