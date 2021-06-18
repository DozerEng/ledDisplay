/**
 * File:   main.c
 * Author: Michael Pillon
 *
 * Created on May 11, 2020, 12:08 PM
 */


#include <xc.h>
#include <pic18f45k22.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "pragmas.h"
#include "globals.h"
#include "initializeHardware.h"
#include "ledDisplay.h"

#define GO_TIME     true

/*
 main:
 Function Name: main
 Parameters: None 
 Return: None 
 Description: Uses ledDisplay.h to handle the graphics on a 52x18 LED panel
 */				
 


/**
 * Function Declarations
 */
void __interrupt(high_priority) highPriorityISR (void);
void __interrupt(low_priority) lowPriorityISR (void);


void main (void)
{
    initializeHardware();

    
    
    // SO Infinite Loop
    while (GO_TIME) {
//        
//        for(uint8_t i = 0; i < DISPLAY_ROW_COUNT; i++) {
//
//            SR_RCLK = 0;
//
//            for(uint8_t j = 0; j < (32); j++) {
//                // 1) set serial data pin
//                SR_SER_0 = (buffer[i][1] >> ii ) & 0x0001;
//                // 2) serial clock pulse
//                __delay_us(1); // Minimum < 100ns between pulses
//                SR_SRCLK = 1;
//                __delay_us(1);
//                SR_SRCLK = 0;
//                // 3) repeat 1-2 for all columns
//            }
//            
//            
//            
//            
//            
//            // 4) disable shift register
//            SR_OE = SR_DISABLE;
//            // 5) latch shift register and increment decade counter
//            SR_RCLK = 1;
//            __delay_us(1);
//
//            // 6) enable shift registers
//            SR_OE = SR_ENABLE;
//            // 7) repeat 1-6 for all rows
//            // 8) repeat 1-7 60 times a second (60Hz)
//
//        }
      }       // eo: Infinite loop
}//eo: main() ==================================================================




/**
 * Function Name: highPriorityISR
 * Parameters: None 
 * Return: None 
 * Description: Interrupt subroutine for high priority interrupts
 *      
 * 
 */

void __interrupt(high_priority) highPriorityISR (void)           // High priority interrupt
{
    /**
     * INT0 - SRCLK storage register clock signal for shift registers
     *  - Handles 1 pixel for each pulse of the clock signal
     */
    if (INTCONbits.INT0IF == 1 && INTCONbits.INT0IE == 1) { 
        // 
        static uint8_t buffer[18][7] = {
            { 0b10000000, 0b00000000, 0b01100000, 0b00000000, 0b00011000, 0b00000000, 0b00000110 },
            { 0b01000000, 0b00000000, 0b10010000, 0b00000000, 0b00100100, 0b00000000, 0b00001001 },
            { 0b00100000, 0b00000001, 0b00001000, 0b00000000, 0b01000010, 0b00000000, 0b00010000 },
            { 0b00010000, 0b00000010, 0b00000100, 0b00000000, 0b10000001, 0b00000000, 0b00100000 },
            { 0b00001000, 0b00000100, 0b00000010, 0b00000001, 0b00000000, 0b10000000, 0b01000000 },
            { 0b00000100, 0b00001000, 0b00000001, 0b00000010, 0b00000000, 0b01000000, 0b10000000 },
            { 0b00000010, 0b00010000, 0b00000000, 0b10000100, 0b00000000, 0b00100001, 0b00000000 },
            { 0b00000001, 0b00100000, 0b00000000, 0b01001000, 0b00000000, 0b00010010, 0b00000000 },
            { 0b00000000, 0b11000000, 0b00000000, 0b00110000, 0b00000000, 0b00001100, 0b00000000 },
            { 0b00000000, 0b11000000, 0b00000000, 0b00110000, 0b00000000, 0b00001100, 0b00000000 },
            { 0b00000001, 0b00100000, 0b00000000, 0b01001000, 0b00000000, 0b00010010, 0b00000000 },
            { 0b00000010, 0b00010000, 0b00000000, 0b10000100, 0b00000000, 0b00100001, 0b00000000 },
            { 0b00000100, 0b00001000, 0b00000001, 0b00000010, 0b00000000, 0b01000000, 0b10000000 },
            { 0b00001000, 0b00000100, 0b00000010, 0b00000001, 0b00000000, 0b10000000, 0b01000000 },
            { 0b00010000, 0b00000010, 0b00000100, 0b00000000, 0b10000001, 0b00000000, 0b00100000 },
            { 0b00100000, 0b00000001, 0b00001000, 0b00000000, 0b01000010, 0b00000000, 0b00010000 },
            { 0b01000000, 0b00000000, 0b10010000, 0b00000000, 0b00100100, 0b00000000, 0b00001001 },
            { 0b10000000, 0b00000000, 0b01100000, 0b00000000, 0b00011000, 0b00000000, 0b00000110 }
        };
        static uint8_t row = 0;
        static uint8_t col = 0;
        
        
        // Note: falling edge causes interrupt
        if(col < 54) {
//            uint8_t temp = (buffer[row][col/8] >> (col%8) ) & 0x01;
//            SR_SER_0 = temp;
            if(col%4 == 0){
                SR_SER_0 = 1;
            } else {
                SR_SER_0 = 0;
            }
            
            col++;
        } else if(col == 54) {
            SR_SER_0 = 0;
            SR_OE = SR_DISABLE;
            SR_RCLK = 1;
            col++;
        } else if(col >= 55) {
            SR_RCLK = 0;
            SR_OE = SR_ENABLE;
            col = 0;
            row++;
        }
        
         
        // Clear INT0 interrupt flag
        INTCONbits.INT0IF = 0;
    }
    
}

/**
 * Function Name: lowPriorityISR
 * Parameters: None 
 * Return: None 
 * Description: Interrupt subroutine for low priority interrupts
 *      - Handing SWITCH_1 interrupts
 *          - SWITCH_1 resets timeElapsed value to 0.0 seconds
 *          - Also resets values in Timer0 data registers 
 * 
 */

void __interrupt(low_priority) lowPriorityISR (void) {
    /**
     * INT1 - Push button RB1
     *  - Resets timeElapsed which is controlled by Timer0
     */
    if (INTCON3bits.INT1IF == 1 && INTCON3bits.INT1IE == 1) {
        // Clear INT1 interrupt flag
        INTCON3bits.INT1IF = 0;
        
    }
}