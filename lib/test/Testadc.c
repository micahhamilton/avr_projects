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
