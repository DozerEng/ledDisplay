/** 
 * File:   initializeHardware.c
 * Author: mpill
 *
 * Created on May 11, 2020, 12:09 PM
 */

#include <xc.h>
#include <pic18f45k22.h>

#include <stdio.h>
#include <stdlib.h>

#include "initializeHardware.h"
#include "ledDisplay.h"

// initializeHardware:**********************************************************
// Function Name: initializeHardware
// Parameters: None 
// Return: None 
// Description: Sets initial ports and interrupts. Calls both USART initialization functions
// 
// 
// ****************************************************************************

void initializeHardware(void)
{
    //printf("\n\rInitializing PIC18F45K22...\r\n");
    set_osc_p18f45k22_16MHz();
    
    initializeLedDisplay();

    /* Enable interrupt priority */
    RCONbits.IPEN = 1;


    /* Enable all high priority interrupts */
    INTCONbits.GIEH = 1;
    //printf("PIC18F45K22 initialized successfully\r\n");
}// eo initializeHardware: ==============================================



// set_osc_p18f45k22_16MHz:**********************************************************
// Function Name: set_osc_p18f45k22_16MHz
// Parameters: None 
// Return: None 
// Description: Sets PIC oscillator speed to 16MHz
// 
// 
// ****************************************************************************

void set_osc_p18f45k22_16MHz(void) {
	OSCCON =  0b01110011; 					// Sleep on slp cmd, HFINT 4MHz, INT OSC Blk
/*              ||||||||
                ||||||| ------------------- SCS<1:0>: System Clock Select bit 1x = Internal oscillator block
                |||||| --------------------               01 = Secondary (SOSC) oscillator
                ||||||                                    00 = Primary clock (determined by FOSC<3:0> in CONFIG1H).
                |||||| 
                ||||| --------------------- bit 2 HFIOFS: HFINTOSC Frequency Stable bit
                |||||                                     1 = HFINTOSC is stable
                |||||                                     0 = HFINTOSC is not stable
                |||| ---------------------- bit 3 OSTS: Oscillator Start-up Time-out Status bit
                ||||                                      1 = Device is running from the clock defined by FOSC<3:0> of the CONFIG1H register
                ||||                                      0 = Device is running from the internal oscillator (HFINTOSC, MFINTOSC or LFINTOSC)
                ||| ----------------------- bits 4:6 
                |||                               RCF<2:0>: Internal RC Oscillator Frequency Select bits
                |||                                       111 = HFINTOSC ? (16 MHz) 
                |||                                       110 = HFINTOSC/2 ? (8 MHz) 
                |||                                       101 = HFINTOSC/4 ? (4 MHz) 
                |||                                       100 = HFINTOSC/8 ? (2 MHz) 011 = HFINTOSC/16 ? (1 MHz)(3)
                |||                                   If  INTSRC = 0 and MFIOSEL = 0: 
                |||                                       010 = HFINTOSC/32 ? (500 kHz) 
                |||                                       001 = HFINTOSC/64 ? (250 kHz) 
                |||                                       000 = LFINTOSC ? (31.25 kHz)
                |||                                   If  INTSRC = 1 and MFIOSEL = 0: 
                |||                                       010 = HFINTOSC/32 ? (500 kHz) 
                |||                                       001 = HFINTOSC/64 ? (250 kHz) 
                |||                                       000 = HFINTOSC/512 ? (31.25 kHz)
                |||                                   If  INTSRC = 0 and MFIOSEL = 1: 
                |                                         010 = MFINTOSC ? (500 kHz) 
                |                                         001 = MFINTOSC/2 ? (250 kHz) 
                |                                         000 = LFINTOSC ? (31.25 kHz)
                |                                     If INTSRC = 1 and MFIOSEL = 1: 
                |                                         010 = MFINTOSC ? (500 kHz)
                |                                         001 = MFINTOSC/2 ? (250 kHz) 
                |                                         000 = MFINTOSC/16 ? (31.25 kHz)
                |                                         1 = MFINTOSC is used in place of HFINTOSC frequencies of 500 kHz, 250 kHz and 31.25 kHz
                |                                         0 = MFINTOSC is not used                                      
				 -------------------------- bit 7 IDLEN: Idle Enable bit
                                                          1 = Device enters Idle mode on SLEEP instruction
                                                          0 = Device enters Sleep mode on SLEEP instruction
*/

	OSCCON2 = 0b00000100;					// PLL No, CLK from OSC, MF off, Sec OSC off, Pri OSC
/*              ||||||||
                ||||||| ------------------- bit 0 LFIOFS: LFINTOSC Frequency Stable bit
                |||||||                                   1 = LFINTOSC is stable
                |||||||                                   0 = LFINTOSC is not stable
                |||||| -------------------- bit 1 MFIOFS: MFINTOSC Frequency Stable bit
                ||||||                                    1 = MFINTOSC is stable
                ||||||                                    0 = MFINTOSC is not stable
                ||||| --------------------- bit 2 PRISD: Primary Oscillator Drive Circuit Shutdown bit
                |||||                                     1 = Oscillator drive circuit on
                |||||                                     0 = Oscillator drive circuit off (zero power)
                |||| ---------------------- bit 3 SOSCGO(1): Secondary Oscillator Start Control bit
                ||||                                      1 = Secondary oscillator is enabled.
                ||||                                      0 = Secondary oscillator is shut off if no other sources are requesting it.
                ||| ----------------------- bit 4 MFIOSEL: MFINTOSC Select bit      
                |||                                       1 = MFINTOSC is used in place of HFINTOSC frequencies of 500 kHz, 250 kHz and 31.25 kHz
                |||                                       0 = MFINTOSC is not used
                || ------------------------ bit 5 Unimplemented: Read as ?0?. 
                | ------------------------- bit 6 SOSCRUN: SOSC Run Status bit
                |                                         1 = System clock comes from secondary SOSC                                       
                |                                         0 = System clock comes from an oscillator, other than SOSC                                    
				 ---------------------------bit 7 PLLRDY: PLL Run Status bit
                                                          1 = System clock comes from 4xPLL
                                                          0 = System clock comes from an oscillator, other than 4xPLL
*/

	OSCTUNE = 0x80;							// PLL disabled, Default factory freq tuning
	while (OSCCONbits.HFIOFS != 1); 	// wait for osc to become stable
    
    //printf("Oscillator set to 16 MHz\r\n");
}
