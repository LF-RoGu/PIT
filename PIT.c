/*
 * PIT.c
 *
 *  Created on: Sep 11, 2018
 *      Author: LuisFernando
 */

#include "MK64F12.h"
#include "PIT.h"

void PIT_delay(PIT_Timer_t pitTimer,float systemClock ,float perior)
{
	/**Es necesario hacer un cast para pasar del numero float a entero, y de ahi a hexa**/
	float cycles = perior/systemClock;
	cycles = (uint32)cycles;
	PIT_LDVAL = decToHexa(cycles);
}

void PIT_clockGating(void);

uint8 PIT_getIntrStutus(void);

void PIT_clear(void);
