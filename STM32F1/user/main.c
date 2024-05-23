#include "main.h"
#include "delay.h"
#include "led.h"
#include "key.h"
#include "usart1.h"
#include "stdio.h"
#include "rtc.h"
#include "Lcd_Driver.h"
#include "MAX30100_PulseOximeter.h"
#include "tim3.h"
#include "boxing.h"

int main(void)
{
	NVIC_SetPriorityGrouping(NVIC_PriorityGroup_2);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
	SysTick_Init(72000);
	Led_Config();
	Key_Config();
	USART1_Config(9600);
	printf("USART1 is ok\r\n");
	if(RTC_Init() == 1)
	{
		printf("RTC Init error\r\n");
	}
	else
	{
		RTC_Set(2020,4,24,10,44,00);
	}
	Lcd_Init();
	SPO2_Init();
	Time3_Init(72, 10000);
	
	
  while (1)
  {
		if(LedRun[0] > LedRun[1])
		{
			Led1_Toggle();
//			printf("心率：%d\r\n",HeartRate);
//			printf("血氧：%d%%\r\n",SPO2);
			LedRun[0] = 0;
		}
		if(MAXRun[0] > MAXRun[1])
		{
			printf("%d\r\n",rawIRValue);//原始的红外ad值打印
			Draw_Diagram(Average_filtering());
			MAXRun[0] = 0;
		}

	}
}
