#ifndef H_DEES_MACROS_H
#define H_DEES_MACROS_H

#define clr_low_nib(sfr)      (sfr &= 0xf0)
#define clr_hi_nib(sfr)       (sfr &= 0x0f)
#define clr_byte(sfr)         (sfr &= 0x00)
#define sbit(sfr, b)          (sfr |= (1 << b))
#define cbit(sfr, b)          (sfr &= ~(1 << b))
#define sbits(sfr, n)         (sfr |= n)
#define cbits(sfr, n)         (sfr &= ~n)

#endif
