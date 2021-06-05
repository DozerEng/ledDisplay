/**
 * File:   initializeHardware.h
 * Author: mpill
 *
 * Created on May 11, 2020, 12:35 PM
 */

#ifndef INITIALIZEHARDWARE_H
#define	INITIALIZEHARDWARE_H

#define _XTAL_FREQ 16000000

#define   SWITCHES			PORTB
#define   SWITCH_MASK       0x03
#define   SWITCH_0          PORTBbits.RB0
#define   SWITCH_1          PORTBbits.RB1

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
#define   SR_RCLK       LATCbits.LATC0  // Shift register clock (Latch)
#define   SR_SRCLK      LATCbits.LATC1  // Storage register clock
#define   SR_SRCLR      LATCbits.LATC2  // Clear
#define   SR_OE         LATCbits.LATC3  // Output enable

#define   SR_RCLK_MASK  0x01
#define   SR_SRCLK_MASK 0x02
#define   SR_SRCLR_MASK 0x04
#define   SR_OE_MASK    0x08

// The following are for SR_SRCLR and SR_OE
#define   SR_ENABLE     0
#define   SR_DISABLE    1

#define   LED_ON    	1
#define   LED_OFF		0
#define   ALL_LED_ON    0xFF
#define   ALL_LED_OFF   0x00

#define PIN_INPUT       1
#define PIN_OUTPUT      0
#define PORT_INPUT      0xFF
#define PORT_OUTPUT 	0x00
#define PIN_ANALOG      1
#define PIN_DIGITAL     0
#define PORT_ANALOG     0xFF
#define PORT_DIGITAL 	0x00

#define TRUE  1
#define FALSE 0

//switch position defines
#define BUTTON_PRESSED  0
#define BUTTON_RELEASED 1

void initializeHardware(void);
void set_osc_p18f45k22_16MHz(void);

#endif	/* INITIALIZEHARDWARE_H */

