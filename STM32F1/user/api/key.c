#include "key.h"
#include "delay.h"

//按键的初始化
void Key_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(KEY1_CLK | KEY2_CLK | KEY3_CLK | KEY4_CLK, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = KEY1_PIN;
	GPIO_Init(KEY1_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = KEY2_PIN;
	GPIO_Init(KEY2_PORT, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = KEY3_PIN;
	GPIO_Init(KEY3_PORT, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = KEY4_PIN;
	GPIO_Init(KEY4_PORT, &GPIO_InitStructure);
}


//KEY1按下返回1
//KEY2按下返回2
//KEY3按下返回3
//KEY4按下返回4
//没有按下返回0
u8 Get_KeyValue(void)
{
	u8 keyvalue = 0;
	if(GPIO_ReadInputDataBit(KEY1_PORT,KEY1_PIN) == Bit_RESET)
	{
		Delay_ms(10);
		if(GPIO_ReadInputDataBit(KEY1_PORT,KEY1_PIN) == Bit_RESET)
		{
			while(GPIO_ReadInputDataBit(KEY1_PORT,KEY1_PIN) == Bit_RESET);
			keyvalue = 1;
		}
	}
	if(GPIO_ReadInputDataBit(KEY2_PORT,KEY2_PIN) == Bit_RESET)
	{
		Delay_ms(10);
		if(GPIO_ReadInputDataBit(KEY2_PORT,KEY2_PIN) == Bit_RESET)
		{
			while(GPIO_ReadInputDataBit(KEY2_PORT,KEY2_PIN) == Bit_RESET);
			keyvalue = 2;
		}
	}
	if(GPIO_ReadInputDataBit(KEY3_PORT,KEY3_PIN) == Bit_RESET)
	{
		Delay_ms(10);
		if(GPIO_ReadInputDataBit(KEY3_PORT,KEY3_PIN) == Bit_RESET)
		{
			while(GPIO_ReadInputDataBit(KEY3_PORT,KEY3_PIN) == Bit_RESET);
			keyvalue = 3;
		}
	}
	if(GPIO_ReadInputDataBit(KEY4_PORT,KEY4_PIN) == Bit_RESET)
	{
		Delay_ms(10);
		if(GPIO_ReadInputDataBit(KEY4_PORT,KEY4_PIN) == Bit_RESET)
		{
			while(GPIO_ReadInputDataBit(KEY4_PORT,KEY4_PIN) == Bit_RESET);
			keyvalue = 4;
		}
	}
	return keyvalue;
}

