/** 
 * File:   ledDisplay.h
 * Author: Michael Pillon
 *
 * Created on May 11, 2020, 12:09 PM
 */
#include "stdint.h"

#ifndef LED_DISPLAY_H
#define	LED_DISPLAY_H


#define DISPLAY_COL_COUNT   54
#define DISPLAY_ROW_COUNT   18


#define   SRCLK_MASK        0x01
#define   SR_SRCLK          PORTBbits.RB0  // Storage register clock

#define   SR_SER_TRIS   TRISD
#define   SR_SER_PORT   LATD
#define   SR_SER_0      LATDbits.LATD0
#define   SR_SER_1      LATDbits.LATD1
#define   SR_SER_2      LATDbits.LATD2
#define   SR_SER_3      LATDbits.LATD3
#define   SR_SER_4      LATDbits.LATD1
#define   SR_SER_5      LATDbits.LATD2
#define   SR_SER_6      LATDbits.LATD3

#define   SR_CNTL_TRIS  TRISC
#define   SR_CONTROL    LATC
#define   SR_OE         LATCbits.LATC0  // Output enable
#define   SR_RCLK       LATCbits.LATC1  // Shift register clock (Latch)
#define   SR_SRCLR      LATCbits.LATC2 // Clear

#define   SR_RCLK_MASK  0x01
#define   SR_SRCLR_MASK 0x02
#define   SR_OE_MASK    0x04

// The following are for SR_SRCLR and SR_OE
#define   SR_ENABLE     0
#define   SR_DISABLE    1
#

#define   LED_ON    	1
#define   LED_OFF		0
#define   ALL_LED_ON    0xFF
#define   ALL_LED_OFF   0x00

/*
 * 18 x 54 grid of LEDs warrants 18 rows x 7 columns x 8 bits per column
 * This leaves 2 extra bits which can be used for timing
 * Shift registers shift LED states in from left to right meaning
 * the 2 bits furthest to the right and the first 2 bits into the buffer.
 * This leads to the following process:
 *  - 2 zero bits for first 2 clock cycles of row
 *  - 54 data bits
 *  - 
 * 
 * 
 */
typedef struct ledDisplay {
    uint8_t pixels[18][7]; 
//    {
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 },
//        { 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000 }
//    }
} LedDisplay;




void initializeLedDisplay(void);
void clearLedDisplay(void);
void printLedDisplay(LedDisplay buffer);


#endif	/* LEDDISPLAY_H */

