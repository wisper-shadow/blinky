/*
 * UART_Config.h
 *
 *  Created on: 2017��5��31��
 *      Author: Arthur
 */

#ifndef UART_CONFIG_UART_CONFIG_H_
#define UART_CONFIG_UART_CONFIG_H_

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

#define MSG_STX 0x7E
#define MSG_LED_ID 0x04
#define MSG_LED_LENGTH 5

void ConfigureUART0(void);
void ConfigureUART1(void);

#endif /* UART_CONFIG_UART_CONFIG_H_ */
