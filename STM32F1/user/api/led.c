#include "led.h"

//LED�Ƴ�ʼ��
void Led_Config(void)
{
	//����һ���ṹ��
	GPIO_InitTypeDef GPIO_InitStructure;
	//��ʱ��
	RCC_APB2PeriphClockCmd(LED1_CLK, ENABLE);
	//�ṹ�帳ֵ
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_InitStructure.GPIO_Pin = LED1_PIN;
	GPIO_Init(LED1_PORT, &GPIO_InitStructure);
}

//����
//GPIOx  IO�˿�
//pin		 �˿�λ���ܽ�
void Led_ON(GPIO_TypeDef* GPIOx, uint16_t pin)
{
	GPIO_ResetBits(GPIOx, pin);
}

//�ص�
//GPIOx  IO�˿�
//pin		 �˿�λ���ܽ�
void Led_OFF(GPIO_TypeDef* GPIOx, uint16_t pin)
{
	GPIO_SetBits(GPIOx, pin);
}

//��ת��
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
