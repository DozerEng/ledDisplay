/**
 * File:   initializeHardware.h
 * Author: mpill
 *
 * Created on May 11, 2020, 12:35 PM
 */

#ifndef INITIALIZEHARDWARE_H
#define	INITIALIZEHARDWARE_H

#include "globals.h" 



// switch position defines
#define BUTTON_PRESSED  0
#define BUTTON_RELEASED 1

void initializeHardware(void);
void set_osc_p18f45k22_16MHz(void);

#endif	/* INITIALIZEHARDWARE_H */

