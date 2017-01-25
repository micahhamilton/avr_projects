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

/* SPH and SPL – Stack Pointer High and Stack Pointer Low Register */
unsigned char *sph;
#define SPH (*(volatile unsigned char *)&sph)
#define SP15        0x07
#define SP14        0x06
#define SP13        0x05
#define SP12        0x04
#define SP11        0x03
#define SP10        0x02
#define SP9         0x01
#define SP8         0x00

unsigned char *spl;
#define SPL (*(volatile unsigned char *)&spl)
#define SP7         0x07
#define SP6         0x06
#define SP5         0x05
#define SP4         0x04
#define SP3         0x03
#define SP2         0x02
#define SP1         0x01
#define SP0         0x00

/* EEARH and EEARL – The EEPROM Address Register */
unsigned char *eearh;
#define EEARH (*(volatile unsigned char *)&eearh)






#define EEAR9       0x01
#define EEAR8       0x00

unsigned char *eearl;
#define EEARL (*(volatile unsigned char *)&eearl)
#define EEAR7       0x07
#define EEAR6       0x06
#define EEAR5       0x05
#define EEAR4       0x04
#define EEAR3       0x03
#define EEAR2       0x02
#define EEAR1       0x01
#define EEAR0       0x00

/* EEDR – The EEPROM Data Register */
unsigned char *eedr;
#define EEDR (*(volatile unsigned char *)&eedr)

/* EECR – The EEPROM Control Register */
unsigned char *eecr;
#define EECR (*(volatile unsigned char *)&EECR)


#define EEPM1       0x05   /* programming mode bit-1 */
#define EEPM0       0x04   /* programming mode bit-0 */
#define EERIE       0x03   /* EEPROM Ready Interrupt Enable */
#define EEMPE       0x02   /* EEPROM Master Write Enable */
#define EEPE        0x01   /* EEPROM Write Enable */
#define EERE        0x00   /* EEPROM Read Enable */

/* GPIOR2 – General Purpose I/O Register 2 */
unsigned char *gpior2;
#define GPIOR2 (*(volatile unsigned char *)&gpior2)

/* GPIOR1 – General Purpose I/O Register 1 */
unsigned char *gpior1;
#define GPIOR1 (*(volatile unsigned char *)&gpior1)

/* GPIOR0 – General Purpose I/O Register 0 */
unsigned char *gpior0;
#define GPIOR0 (*(volatile unsigned char *)&gpior0)

/* System Clock */

/* OSCCAL – Oscillator Calibration Register */
unsigned char *osccal;
#define OSCCAL (*(volatile unsigned char *)&osccal)
#define CAL7        0x07
#define CAL6        0x06
#define CAL5        0x05
#define CAL4        0x04
#define CAL3        0x03
#define CAL2        0x02
#define CAL1        0x01
#define CAL0        0x00

/* CLKPR – Clock Prescale Register */
unsigned char *clkpr;
#define CLKPR (*(volatile unsigned char *)&clkpr)
#define CLKPCE      0x07    /* Clock Prescaler Change Enable */



#define CLKPS3      0x03    /* Clock Prescaler Select Bits 3 */
#define CLKPS2      0x02    /* Clock Prescaler Select Bits 2 */
#define CLKPS1      0x01    /* Clock Prescaler Select Bits 1 */
#define CLKPS0      0x00    /* Clock Prescaler Select Bits 0 */

/* Power Management and Sleep Modes */

/* SMCR - Sleep Mode Control Register */
unsigned char *smcr;
#define SMCR (*(volatile unsigned char *)&smcr)




#define SM2         0x03   /* Sleep Mode Select Bit 2 */
#define SM1         0x02   /* Sleep Mode Select Bit 1 */
#define SM0         0x01   /* Sleep Mode Select Bit 0 */
#define SE          0x00   /* Sleep Enable */

/* MCUCR – MCU Control Register */
unsigned char *mcucr;
#define MCUCR (*(volatile unsigned char *)&mcucr)

#define BODS        0x06   /* BOD Sleep */
#define BODSE       0x05   /* BOD Sleep Enable */
#define PUD         0x04   /* ??? */


#define IVSEL       0x01   /* ??? */
#define IVCE        0x00   /* ??? */

/* PRR - Power Reduction Register */
unsigned char *prr;
#define PRR (*(volatile unsigned char *)&prr)
#define PRTWI       0x07   /* Power Reduction TWI */
#define PRTIM2      0x06   /* Power Reduction Timer/Counter2 */
#define PRTIM0      0x05   /* Power Reduction Timer/Counter0 */

#define PRTIM1      0x03   /* Power Reduction Timer/Counter1 */
#define PRSPI       0x02   /* Power Reduction Serial Peripheral Interface */
#define PRUSART0    0x01   /* Power Reduction USART0 */
#define PRADC       0x00   /* Power Reduction ADC */

/* Reset Status */

/* MCUSR – MCU Status Register */
unsigned char *mcusr;
#define MCUSR (*(volatile unsigned char *)&mcusr)




#define WDRF        0x03   /* Watchdog System Reset Flag */
#define BORF        0x02   /* Brown-out Reset Flag */
#define EXTRF       0x01   /* External Reset Flag */
#define PORF        0x00   /* Power-on Reset Flag */

/* WDTCSR – Watchdog Timer Control Register */
unsigned char *wdtcsr;
#define WDTCSR (*(volatile unsigned char *)&wdtcsr)
#define WDIF        0x07   /* Watchdog Interrupt Flag */
#define WDIE        0x06   /* Watchdog Interrupt Enable */
#define WDP3        0x05   /* Watchdog Timer Prescaler 3 */
#define WDCE        0x04   /* Watchdog Change Enable */
#define WDE         0x03   /* Watchdog System Reset Enable */
#define WDP2        0x02   /* Watchdog Timer Prescaler 2 */
#define WDP1        0x01   /* Watchdog Timer Prescaler 1 */
#define WDP0        0x00   /* Watchdog Timer Prescaler 0 */

/* TODO Interrupt Registers */

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


