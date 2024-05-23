#ifndef __KEY_H
#define __KEY_H

#include "stm32f10x.h"

#define KEY1_CLK	RCC_APB2Periph_GPIOA
#define KEY1_PIN	GPIO_Pin_0
#define KEY1_PORT	GPIOA

#define KEY2_CLK	RCC_APB2Periph_GPIOB
#define KEY2_PIN	GPIO_Pin_3
#define KEY2_PORT	GPIOB

#define KEY3_CLK	RCC_APB2Periph_GPIOB
#define KEY3_PIN	GPIO_Pin_4
#define KEY3_PORT	GPIOB

#define KEY4_CLK	RCC_APB2Periph_GPIOB
#define KEY4_PIN	GPIO_Pin_5
#define KEY4_PORT	GPIOB



void Key_Config(void);
u8 Get_KeyValue(void);



#endif
