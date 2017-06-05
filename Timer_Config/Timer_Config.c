/*
 * Timer_config.c
 *
 *  Created on: 2017Äê5ÔÂ25ÈÕ
 *      Author: Arthur
 */

#include "Timer_Config.h"

void Timer0A_Init(void)
{
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
	TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC);
	TimerLoadSet(TIMER0_BASE, TIMER_A, SysCtlClockGet());
	IntEnable(INT_TIMER0A);
	TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
	TimerEnable(TIMER0_BASE, TIMER_A);
}

void intpriorityConfigure(void)
{
//	IntPrioritySet(INT_TIMER0A,0x00);		//00000000
	IntPrioritySet(INT_GPIOD,0x40);			//01000000
	IntPrioritySet(INT_UART0,0x20);			//00100000
	IntPrioritySet(INT_UART1,0x60);         //01100000
}
