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

void test_adc_prescaler_select_should_return_minimum_sample_time(void)
{
  clr_byte(ADCSRA);
  int t = adc_prescaler_select(ADC_FAST_CONVERSION);
  TEST_ASSERT_EQUAL_HEX8(104, t);

  TEST_ASSERT_EQUAL_HEX8(6, ADCSRA);
}

void test_adc_prescaler_frequency_should_set_prescale_params(void)
{
  ADC_Config config;
  adc_prescaler_frequency(&config);
  TEST_ASSERT_EQUAL_HEX8(0x06, config.fast_prescaler);
  TEST_ASSERT_EQUAL_HEX8(0x07, config.slow_prescaler);
  TEST_ASSERT_EQUAL_INT(208, config.slow_convert_us);
  TEST_ASSERT_EQUAL_INT(104, config.fast_convert_us);
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
  RUN_TEST(test_adc_prescaler_select_should_return_minimum_sample_time);
  RUN_TEST(test_adc_prescaler_frequency_should_set_prescale_params);
  return UNITY_END();
}
