#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"

#define LED1_CLK	RCC_APB2Periph_GPIOB
#define LED1_PORT	GPIOB
#define LED1_PIN	GPIO_Pin_6


void Led_Config(void);
void Led_ON(GPIO_TypeDef* GPIOx, uint16_t pin);
void Led_OFF(GPIO_TypeDef* GPIOx, uint16_t pin);
void Led1_Toggle(void);
void Led2_Toggle(void);
void Led3_Toggle(void);
void Led4_Toggle(void);
#endif
