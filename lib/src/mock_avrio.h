/* ADMUX – ADC Multiplexer Selection Register */
unsigned char *admux;
#define ADMUX (*(volatile unsigned char *)&admux)
#define REFS1       0x07
#define REFS0       0x06
#define ADLAR       0x05
#define MUX3        0x03
#define MUX2        0x02
#define MUX1        0x01
#define MUX0        0x00

/* ADCSRA – ADC Control and Status Register A */
unsigned char *adcsra;
#define ADCSRA (*(volatile unsigned char *)&adcsra)
#define ADEN        0x07
#define ADSC        0x06
#define ADATE       0x05
#define ADIF        0x04
#define ADIE        0x03
#define ADPS2       0x02
#define ADPS1       0x01
#define ADPS0       0x00

