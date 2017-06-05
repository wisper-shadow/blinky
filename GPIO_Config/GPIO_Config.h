/*
 * GPIO_Config.h
 *
 *  Created on: 2017Äê5ÔÂ25ÈÕ
 *      Author: Arthur
 */

#ifndef GPIO_CONFIG_GPIO_CONFIG_H_
#define GPIO_CONFIG_GPIO_CONFIG_H_

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

void GPIO_Init(void);
void ConfigureGPIOD(void);

#endif /* GPIO_CONFIG_GPIO_CONFIG_H_ */
