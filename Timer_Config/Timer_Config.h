/*
 * Timer_config.h
 *
 *  Created on: 2017Äê5ÔÂ25ÈÕ
 *      Author: Arthur
 */

#ifndef TIMER_CONFIG_TIMER_CONFIG_H_
#define TIMER_CONFIG_TIMER_CONFIG_H_

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "driverlib/rom.h"
#include "driverlib/gpio.h"
#include "driverlib/timer.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/interrupt.h"

void Timer0A_Init(void);
void intpriorityConfigure(void);

#endif /* TIMER_CONFIG_TIMER_CONFIG_H_ */
