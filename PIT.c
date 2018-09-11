/*
 * PIT.c
 *
 *  Created on: Sep 11, 2018
 *      Author: LuisFernando
 */

#include "MK64F12.h"
#include "PIT.h"

void decToHexa(uint32 value)
{
	uint8 hex[100];
	uint32 i = 0;
	while(FALSE != value)
	{
		/**Temporal var to store remainder**/
		uint32 temp = 0;
		/**Store remainder in temp var**/
		temp = value % 16;
		/****/
		if(temp < 10)
		{
			hex[i] = temp + 48;
			i++;
		}
		else
		{
			hex[i] = temp + 55;
			i++;
		}
		value = value/16;
	}
}

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
