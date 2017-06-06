/*
 * WS2812.c
 *
 *  Created on: 2017Äê5ÔÂ22ÈÕ
 *      Author: Arthur
 */

#include "WS2812.h"

void Send_Code_0(void)
{
	GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, GPIO_PIN_0);
	SysCtlDelay(1);
	GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 0);
	SysCtlDelay(4);
}

void Send_Code_1(void)
{
	GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, GPIO_PIN_0);
	SysCtlDelay(6);
	GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_0, 0);
	SysCtlDelay(1);
}

void Send_Reset(void)
{
	SysCtlDelay(SysCtlClockGet()/400);
}

void Send_Hex(uint8_t hex)
{
	if((hex >> 7)%2)
		Send_Code_1();
	else
		Send_Code_0();

	if((hex >> 6)%2)
		Send_Code_1();
	else
		Send_Code_0();

	if((hex >> 5)%2)
		Send_Code_1();
	else
		Send_Code_0();

	if((hex >> 4)%2)
		Send_Code_1();
	else
		Send_Code_0();

	if((hex >> 3)%2)
		Send_Code_1();
	else
		Send_Code_0();

	if((hex >> 2)%2)
		Send_Code_1();
	else
		Send_Code_0();

	if((hex >> 1)%2)
		Send_Code_1();
	else
		Send_Code_0();

	if((hex >> 0)%2)
		Send_Code_1();
	else
		Send_Code_0();
}
