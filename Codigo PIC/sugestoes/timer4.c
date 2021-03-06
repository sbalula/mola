#include <timer.h>
#include "timer4.h"
#include "todo.h"
#include "io.h"
#include <stdio.h>



void init_TMR4(void) {

    T4CON = 0; // Clear the Timer 2 configuration
    TMR4 = 0x0000; // Sets timer value to zero
    PR4 = 5000; // Timer Period

    IEC1bits.T4IE = 1; //Enable interrupt
    T4CONbits.TCKPS = 1; // internal Tcy divider
    IFS1bits.T4IF = 0;
    T4CONbits.TON = 1;
}

//Timer Interrupt handler
void __attribute__((interrupt, no_auto_psv)) _T4Interrupt(void) {
    IFS1bits.T4IF = 0; //Clears interrupt flag
    T3CONbits.TON=1;
}