#include <stdint.h>
#include <stdbool.h>
#include <string.h>
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
#include "WS2812/WS2812.h"
#include "Timer_Config/Timer_Config.h"
#include "GPIO_Config/GPIO_Config.h"
#include "UART_Config/UART_Config.h"

uint8_t LED_table[][3]={			//G,R,B
		{0x28,0x00,0x00},
		{0x50,0x00,0x00},
		{0x78,0x00,0x00},
		{0xA0,0x00,0x00},
		{0xC8,0x00,0x00},
		{0xF0,0x00,0x00},
		{0xF0,0x28,0x00},
		{0xC8,0x50,0x00},
		{0xA0,0x78,0x00},
		{0x78,0xA0,0x00},
		{0x50,0xC8,0x00},
		{0x28,0xF0,0x00},
		{0x00,0xF0,0x28},
		{0x00,0xC8,0x50},
		{0x00,0xA0,0x78},
		{0x00,0x78,0xA0},
		{0x00,0x50,0xC8},
		{0x00,0x28,0xF0},
		{0x00,0x00,0xF0},
		{0x00,0x00,0xC8},
		{0x00,0x00,0xA0},
		{0x00,0x00,0x78},
		{0x00,0x00,0x50},
		{0x00,0x00,0x28},
};

uint8_t RGB_Reset[] = {0x00,0x00,0x00};
uint8_t RGB_Single[] = {0x00,0x00,0x00};

uint8_t sys_flag = 0;
uint8_t RGB_flag = 0;
uint8_t RGB_flag2 = 0;

uint8_t rx_buffer = 0x00;
uint8_t Rx_Buffer_LEDCtrl[5];

uint8_t LEDCtrl_flag = 0;
uint8_t start_receive_LEDCtrl = 0;
uint8_t LEDCtrl_Buffer[5];

bool is_LEDCtrl = false;

int main(void)
{
	uint8_t i,j,k=0;
	SysCtlClockSet(SYSCTL_SYSDIV_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

	GPIO_Init();
	ConfigureGPIOD();
	ConfigureUART0();
	ConfigureUART1();
	intpriorityConfigure();
//	Timer0A_Init();

    while(1)
    {
    	if(sys_flag)
    		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, 0);
    	else
    		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, GPIO_PIN_1);

		switch(LEDCtrl_Buffer[2])
		{
			case 0x00:
			
			for(i=0;i<24;i++)
				for (j=0;j<3;j++)
					Send_Hex(RGB_Reset[j]);
			Send_Reset();
			SysCtlDelay(SysCtlClockGet()/400);
			break;
			
			case 0x01:
			for(i=0;i<24;i++)
				for(j=0;j<3;j++)
					Send_Hex(LED_table[(i+k)%24][j]);
			k++;
			if(k == 24)
				k=0;
			Send_Reset();
			SysCtlDelay(SysCtlClockGet()/400);
			SysCtlDelay(SysCtlClockGet()/72);
			break;
			
			case 0x02:
			if(!RGB_flag2 && (RGB_Single[0] != 0x00 || RGB_Single[1] != 0x00 || RGB_Single[2] != 0x00 || RGB_flag != 0))
			{
				RGB_flag2 = 1;
				RGB_Single[0] = 0x00;
				RGB_Single[1] = 0x00;
				RGB_Single[2] = 0x00;
			}
			for(i=0;i<24;i++)
				for (j=0;j<3;j++)
					Send_Hex(RGB_Single[j]);
			Send_Reset();
			if(RGB_flag == 0)
				RGB_Single[1]++;
			if(RGB_flag == 1)
				RGB_Single[1]--;
			if(RGB_Single[1] == 0xff)
				RGB_flag = 1;
			if(RGB_Single[1] == 0x00)
			{
				RGB_flag = 0;
				RGB_flag2 = 0;
			}
			SysCtlDelay(SysCtlClockGet()/400);
			break;
			
			case 0x03:
			if(!RGB_flag2 && (RGB_Single[0] != 0x00 || RGB_Single[1] != 0x00 || RGB_Single[2] != 0x00 || RGB_flag != 0))
			{
				RGB_flag2 = 1;
				RGB_Single[0] = 0x00;
				RGB_Single[1] = 0x00;
				RGB_Single[2] = 0x00;
			}
			for(i=0;i<24;i++)
				for (j=0;j<3;j++)
					Send_Hex(RGB_Single[j]);
			Send_Reset();
			if(RGB_flag == 0)
				RGB_Single[0]++;
			if(RGB_flag == 1)
				RGB_Single[0]--;
			if(RGB_Single[0] == 0xff)
				RGB_flag = 1;
			if(RGB_Single[0] == 0x00)
			{
				RGB_flag = 0;
				RGB_flag2 = 0;
			}
			SysCtlDelay(SysCtlClockGet()/400);
			break;
			
			case 0x04:
			if(!RGB_flag2 && (RGB_Single[0] != 0x00 || RGB_Single[1] != 0x00 || RGB_Single[2] != 0x00 || RGB_flag != 0))
			{
				RGB_flag2 = 1;
				RGB_Single[0] = 0x00;
				RGB_Single[1] = 0x00;
				RGB_Single[2] = 0x00;
			}
			for(i=0;i<24;i++)
				for (j=0;j<3;j++)
					Send_Hex(RGB_Single[j]);
			Send_Reset();
			if(RGB_flag == 0)
				RGB_Single[2]++;
			if(RGB_flag == 1)
				RGB_Single[2]--;
			if(RGB_Single[2] == 0xff)
				RGB_flag = 1;
			if(RGB_Single[2] == 0x00)
			{
				RGB_flag = 0;
				RGB_flag2 = 0;
			}
			SysCtlDelay(SysCtlClockGet()/400);
			break;
			
			default:
			break;
		}
    }
}

//void Timer0AIntHandler(void)
//{
//	TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
//	if(sys_flag)
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, 0);
//	else
//		GPIOPinWrite(GPIO_PORTD_BASE, GPIO_PIN_1, GPIO_PIN_1);
//}

void GPIODIntHandler(void)
{
	unsigned int Status;
	Status=GPIOIntStatus(GPIO_PORTD_BASE,true);
	GPIOIntClear(GPIO_PORTD_BASE,Status);

	if(GPIOPinRead(GPIO_PORTD_BASE,GPIO_PIN_2))
	{
		SysCtlDelay(SysCtlClockGet() / 10000);
		if(GPIOPinRead(GPIO_PORTD_BASE,GPIO_PIN_2))
		{
			sys_flag = !sys_flag;
//			while(!GPIOPinRead(GPIO_PORTD_BASE,GPIO_PIN_2));
		}
	}
}

void UART0IntHandler(void)
{
	uint32_t ui32Status;
	ui32Status = UARTIntStatus(UART0_BASE, true);
	UARTIntClear(UART0_BASE, ui32Status);

	RGB_flag2 = 0;

	while(UARTCharsAvail(UART0_BASE))
	{
		rx_buffer = UARTCharGetNonBlocking(UART0_BASE);
		if(rx_buffer == MSG_STX)
		{
			LEDCtrl_flag = 0;
			start_receive_LEDCtrl = 1;
		}
		if(start_receive_LEDCtrl == 1)
		{
			Rx_Buffer_LEDCtrl[LEDCtrl_flag++] = rx_buffer;
			if(LEDCtrl_flag == MSG_LED_LENGTH && Rx_Buffer_LEDCtrl[1] == MSG_LED_ID)
			{
				memcpy(LEDCtrl_Buffer,Rx_Buffer_LEDCtrl,MSG_LED_LENGTH);
				is_LEDCtrl = true;
			}
			if(LEDCtrl_flag >= MSG_LED_LENGTH)
			{
				LEDCtrl_flag = 0;
				start_receive_LEDCtrl = 0;
				memset(Rx_Buffer_LEDCtrl,0,5);
			}
		}
	}
}

void UART1IntHandler(void)
{
    uint32_t ui32Status;
    ui32Status = UARTIntStatus(UART1_BASE, true);
    UARTIntClear(UART1_BASE, ui32Status);

    RGB_flag2 = 0;

    while(UARTCharsAvail(UART1_BASE))
    {
        rx_buffer = UARTCharGetNonBlocking(UART1_BASE);
        if(rx_buffer == MSG_STX)
        {
            LEDCtrl_flag = 0;
            start_receive_LEDCtrl = 1;
        }
        if(start_receive_LEDCtrl == 1)
        {
            Rx_Buffer_LEDCtrl[LEDCtrl_flag++] = rx_buffer;
            if(LEDCtrl_flag == MSG_LED_LENGTH && Rx_Buffer_LEDCtrl[1] == MSG_LED_ID)
            {
                memcpy(LEDCtrl_Buffer,Rx_Buffer_LEDCtrl,MSG_LED_LENGTH);
                is_LEDCtrl = true;
            }
            if(LEDCtrl_flag >= MSG_LED_LENGTH)
            {
                LEDCtrl_flag = 0;
                start_receive_LEDCtrl = 0;
                memset(Rx_Buffer_LEDCtrl,0,5);
            }
        }
    }
}
