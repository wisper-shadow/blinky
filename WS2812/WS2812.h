/*
 * Timer_config.h
 *
 *  Created on: 2017Äê5ÔÂ25ÈÕ
 *      Author: Arthur
 */

#ifndef WS2812_WS2812_H_
#define WS2812_WS2812_H_

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "driverlib/rom.h"
#include "driverlib/gpio.h"
#include "driverlib/uart.h"
#include "driverlib/timer.h"
#include "utils/uartstdio.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/interrupt.h"

void Send_Code_0(void);
void Send_Code_1(void);
void Send_Reset(void);
void Send_Hex(uint8_t hex);

#endif /* WS2812_H_ */
