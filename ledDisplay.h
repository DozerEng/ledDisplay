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


typedef struct ledDisplay {
    uint32_t row[2];
    uint8_t col;
} LedDisplay;

LedDisplay initializeLedDisplay(const uint32_t colCount, const uint32_t rowCount);

#endif	/* LEDDISPLAY_H */

