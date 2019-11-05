#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    volatile int i = 0;

    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    P1DIR |= BIT0;
    P4DIR |= BIT7;

    P1OUT &= ~BIT0;
    P4OUT &= ~BIT7;

    while (1)
    {
        P1OUT ^= BIT0;
        P4OUT ^= BIT7;
        for(i = 10000; i > 0; i--);
    }

    return 0;
}
