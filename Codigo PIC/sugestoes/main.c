//Samuel Balula & Pedro Ribeiro 2014
#include <p30F4011.h>		//defines dspic registers
#include <stdio.h>		//standart IO library C
#include <libpic30.h>		//C30 compiler definitions
#include <uart.h>		//UART (serial port) function and utilities library
#include <timer.h>		//timer library
#include <string.h>
#include <math.h>

#include "uart2.h"
#include "io.h"
//#include "timer2.h"
#include "timer3.h"
#include "timer4.h"
//#include "oc.h"
//#include "ic.h"
#include "delays.h"
#include "todo.h"
#include "adc.h"
#include "spi.h"

int main() {

    int a;
    init_UART2();
    init_io();

    //calculaseno();

    init_TMR2();
    //init_ADC();
    //init_TMR3();
    //init_TMR4();
    init_OC2();
    //init_SPI1();
    duty = 180;


    while (1) {
        pull_UART2();
        OC2RS = 332+358*duty/90; //Duty Time
    }


}

