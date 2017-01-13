/* What to consider when configuring the atmega 168/328 10-bit adc *
 * 
 * number of channels: 6 when using dual inline packacge else 8
 *
 * internal voltage reference (1.1V or AVcc) or external reference
 *
 * power reduction adc bit (PRADC) must be disabled by writing a logical
 * zero to enable the adc
 *
 * input channel is selected by writing to the mux bits in ADMUX
 *
 * The ADC is enabled by setting the ADC Enable bit, ADEN in ADCSRA.
 * Voltage reference and input channel selections will not go into effect
 * until ADEN is set. The ADC does not consume power when ADEN is cleared,
 * so it is recommended to switch off the ADC before entering power 
 * saving sleep modes
 * void adc_enable()
 * {
 *
 * }
 * void adc_disable()
 * {
 *
 * }
 *
 * The ADC generates a 10-bit result which is presented in the ADC
 * Data Registers, ADCH and ADCL. By default, the result is presented
 * right adjusted, but can optionally be presented left adjusted by
 * setting the ADLAR bit in ADMUX.
 */
#include "unity.h"
#include "adc.h"
#include "mock_avrio.h"
#include "macro.h"


void test_adc_enable__should_set__bit(void)
{
  uint8_t i;
  clr_byte(ADCSRA);
  adc_enable;
  i = (1 << ADEN);
  TEST_ASSERT_EQUAL_HEX8(i, ADCSRA);
  clr_byte(ADCSRA);
  ADCSRA |= 0x0f;
  adc_enable;
  i = 0x0f;
  i |= (1 << ADEN);
  TEST_ASSERT_EQUAL_HEX8(i, ADCSRA);
}

void test_adc_disable__should_clear__bit(void)
{
  uint8_t i;
  clr_byte(ADCSRA);
  adc_enable;
  i = (1 << ADEN);
  TEST_ASSERT_EQUAL_HEX8(i, ADCSRA);
  adc_disable;
  i = 0x00;
  TEST_ASSERT_EQUAL_HEX8(i, ADCSRA);
  clr_byte(ADCSRA);
}

void test_adc_start_conversion_should_set_bit(void)
{
  uint8_t i;
  clr_byte(ADCSRA);
  adc_start_conversion;
  i = (1<<ADSC);
  TEST_ASSERT_EQUAL_HEX8(i, ADCSRA);
  clr_byte(ADCSRA);
}

void test_adc_auto_trigger_enable_should_set_bit(void)
{
  uint8_t i;
  clr_byte(ADCSRA);
  adc_auto_trigger_enable;
  i = (1 << ADATE);
  TEST_ASSERT_EQUAL_HEX8(i, ADCSRA);
  clr_byte(ADCSRA);
}

/* logical 1 to clear interrupt flag */
void test_adc_clear_interrupt_flag_should_set_bit(void)
{
  uint8_t i;
  clr_byte(ADCSRA);
  adc_clear_interrupt_flag;
  i = (1 << ADIF);
  TEST_ASSERT_EQUAL_HEX8(i, ADCSRA);
  clr_byte(ADCSRA);
}

void test_adc_interrupt_enable_should_set_bit(void)
{
  uint8_t i;
  clr_byte(ADCSRA);
  adc_interrupt_enable;
  i = (1 << ADIE);
  TEST_ASSERT_EQUAL_HEX8(i, ADCSRA);
  clr_byte(ADCSRA);
}

void test_adc_calculate_prescaler_should_set_prescale_params(void)
{
  /******************* BELOW VALIDATED USING EXTERNAL PROGRAM ***********************/
  /*   valid between max and min cpu frequencys for ADC 100,000 - 20,000,000 Hz     */
  int fps, sps, fct, sct, ps_a;     /* ps_a = actual prescale value */

  fps = ADC_MIN_PRESCALER;
  ps_a = (1 << ADC_MIN_PRESCALER);  /* (1 << 1) = 0x02 */

  /* find fast convert values for given F_CPU */
  while (F_CPU / ps_a > ADC_MAX_FREQUENCY) {
    ps_a = (ps_a << 1);
    ++fps;
  }
  fct = (int)(((double)ps_a / F_CPU) * ADC_CYCLES_PER_CONVERSION * 1000000);

  sps = ADC_MAX_PRESCALER;
  ps_a = (1 << ADC_MAX_PRESCALER);   /* (1 << 7) = 128 */

  /* find slow convert values for given F_CPU */
  while (F_CPU / ps_a < ADC_MIN_FREQUENCY) {
    ps_a = (ps_a >> 1);
    --sps;
  }
  sct = (int)(((double)ps_a / F_CPU) * ADC_CYCLES_PER_CONVERSION * 1000000);
  /******************** ABOVE VALIDATED USING EXTERNAL PROGRAM ***********************/  

  ADC_Config config;
  adc_calculate_prescaler(&config);
  TEST_ASSERT_EQUAL_HEX8(fps, config.fast_prescaler);
  TEST_ASSERT_EQUAL_HEX8(sps, config.slow_prescaler);
  TEST_ASSERT_EQUAL_INT(sct, config.slow_convert_us);
  TEST_ASSERT_EQUAL_INT(fct, config.fast_convert_us);
}

void test_adc_config_default_params_should_set_default_adc_params(void)
{
  ADC_Config config;  
  adc_config_default_params(&config);
  TEST_ASSERT_EQUAL_HEX8(ADC_VCC_REF, config.ref); 
  TEST_ASSERT_EQUAL_HEX8(ADC_RIGHT_ADJUST_RESULT, config.result_alignment); 
  TEST_ASSERT_EQUAL_HEX8(ADC_SLOW_CONVERSION, config.speed); 

  //adc_config_default_params(&config);
  //TEST_ASSERT_EQUAL_HEX8((ADMUX |= ADC_VCC_REF), config.ref);
  //TEST_ASSERT_EQUAL_HEX8(ADCSRA, config.slow_prescaler);
}

void test_adc_init_module_should_set_adc_register_using_default_values(void)
{
  ADMUX = 0x00;
  ADCSRA = 0x00;
  ADC_Config config;  
  adc_config_default_params(&config);
  adc_init_module(&config);
  TEST_ASSERT_EQUAL_HEX8(0x40, ADMUX);
  TEST_ASSERT_EQUAL_HEX8(0x87, ADCSRA);
}

int main(void)
{
  UNITY_BEGIN();
  RUN_TEST(test_adc_enable__should_set__bit);
  RUN_TEST(test_adc_disable__should_clear__bit);
  RUN_TEST(test_adc_start_conversion_should_set_bit);
  RUN_TEST(test_adc_auto_trigger_enable_should_set_bit);
  RUN_TEST(test_adc_clear_interrupt_flag_should_set_bit);
  RUN_TEST(test_adc_interrupt_enable_should_set_bit);
  if(F_CPU <= ADC_MAX_CPU && F_CPU >= ADC_MIN_CPU)
    RUN_TEST(test_adc_calculate_prescaler_should_set_prescale_params);
  RUN_TEST(test_adc_config_default_params_should_set_default_adc_params);
  RUN_TEST(test_adc_init_module_should_set_adc_register_using_default_values);
  return UNITY_END();
}
