#include "led.h"

//LED灯初始化
void Led_Config(void)
{
	//定义一个结构体
	GPIO_InitTypeDef GPIO_InitStructure;
	//开时钟
	RCC_APB2PeriphClockCmd(LED1_CLK, ENABLE);
	//结构体赋值
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_InitStructure.GPIO_Pin = LED1_PIN;
	GPIO_Init(LED1_PORT, &GPIO_InitStructure);
}

//开灯
//GPIOx  IO端口
//pin		 端口位：管脚
void Led_ON(GPIO_TypeDef* GPIOx, uint16_t pin)
{
	GPIO_ResetBits(GPIOx, pin);
}

//关灯
//GPIOx  IO端口
//pin		 端口位：管脚
void Led_OFF(GPIO_TypeDef* GPIOx, uint16_t pin)
{
	GPIO_SetBits(GPIOx, pin);
}

//翻转灯
void Led1_Toggle(void)
{
	static u8 count = 0;
	switch(count++)
	{
		case 0:Led_ON(LED1_PORT, LED1_PIN);break;
		case 1:Led_OFF(LED1_PORT, LED1_PIN);break;
	}	
	count %= 2;
}
