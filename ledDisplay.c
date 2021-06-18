/** 
 * File:   ledDisplay.c
 * Author: mpill
 *
 * Created on May 11, 2020, 12:09 PM
 */

#include "ledDisplay.h"
#include "globals.h"
#include <xc.h>
#include <pic18f45k22.h>



/**
 * ititializeLedDisplay
 * 
 * 
 * 
 */



void initializeLedDisplay(void)
{
    //printf("Initializing LED display...\r\n");
    
      /* 
     * LED matrix port designations 
     *      - SER_0 is always used and SER_1 thru SER6 allow segmentation of the 
     *      shift registers allowing parallel data into the 7 shift registers
     */
    SR_SER_PORT = ALL_LED_OFF;
    SR_SER_TRIS = PORT_DIGITAL;
    
    /* Control pin set up */
    SR_CONTROL = ALL_LED_OFF;
    SR_CNTL_TRIS = PORT_OUTPUT;
    ANSELC = PORT_DIGITAL;    
    
    /**
     * SRCLK interrupt configuration
     *      Shift register storage clock signal.
     *      Data shifts on the internal register on every clock signal 4
     *      Uses high priority interrupts
     */
    TRISBbits.RB0 = PIN_INPUT;
    ANSELB = PIN_DIGITAL;
    // Ensures interrupt flags are cleared
    INTCONbits.INT0IF = 0;
    // Enable interrupts on INT0 (RB0))
    INTCONbits.INT0IE = 1;
    // Sets interrupts on rising edge for 1, falling edge for 0
    INTCON2bits.INTEDG0 = 0;
  
    clearLedDisplay();
    
    //printf("LED display successfully initialized.\n\r");
}



/**
 * clearLedDisplay
 * 
 */
void clearLedDisplay(void)
{
    // Clear shift registers and set initial states
    SR_SER_PORT = ALL_LED_OFF;
    SR_OE = SR_ENABLE;
    __delay_ms(2);
    SR_SRCLR = SR_ENABLE;
    __delay_ms(2);
    SR_SRCLR = SR_DISABLE;
}

/**
 * clearLedDisplay
 * 
 */

void printLedDisplay(LedDisplay buffer)
{
    
    
    
    
    
    
    
    // Clear shift registers and set initial states
    SR_SER_PORT = ALL_LED_OFF;
    SR_OE = SR_ENABLE;
    __delay_ms(2);
    SR_SRCLR = SR_ENABLE;
    __delay_ms(2);
    SR_SRCLR = SR_DISABLE;
}

