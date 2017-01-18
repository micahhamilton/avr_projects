/* SREG – AVR Status Register */
unsigned char *sreg;
#define SREG (*(volatile unsigned char *)&sreg)
#define I           0x07        /* Global Interrupt Enable */
#define T           0x06        /* Bit Copy Storage */
#define H           0x05        /* Half Carry Flag */
#define S           0x04        /* Sign Bit */
#define V           0x03        /* Two's Complement Overflow Flag */
#define N           0x02        /* Negative Flag */
#define Z           0x01        /* Zero Flag */
#define C           0x00        /* Carry Flag */

/* TODO Clock Suff Here */



/* SMCR - Sleep Mode Control Register */
unsigned char *smcr;
#define SMCR (*(volatile unsigned char *)&smcr)




#define SM2         0x03
#define SM1         0x02
#define SM0         0x01
#define SE          0x00

/* PRR - Power Reduction Register */
unsigned char *prr;
#define PRR (*(volatile unsigned char *)&prr)
#define PRTWI       0x07
#define PRTIM2      0x06
#define PRTIM0      0x05

#define PRTIM1      0x03
#define PRSPI       0x02
#define PRUSART0    0x01
#define PRADC       0x00

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

/* ADCSRB – ADC Control and Status Register B */
unsigned char *adcsrb;
#define ADCSRB (*(volatile unsigned char *)&adcsrb)

#define ACME        0x06



#define ADTS2       0x02
#define ADTS1       0x01
#define ADTS0       0x00

/* DIDR0 – Digital Input Disable Register 0 */


#define ADC5D       0x05
#define ADC4D       0x04
#define ADC3D       0x03
#define ADC2D       0x02
#define ADC1D       0x01
#define ADC0D       0x00


