#include "usart1.h"
#include "stdio.h"

//PA9  PA10
void USART1_Config(u32 brr)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	//��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	//�ṹ�帳ֵ
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	//��ʼ��USART1  ������brr �򿪷��ͺͽ�����  ����żУ��  һ��ֹͣλ  8������λ
	USART_InitStructure.USART_BaudRate = brr;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_Init(USART1, &USART_InitStructure);
	USART_Cmd(USART1,ENABLE);//ʹ��USART1
}

//��������
void Usart_SendByte(u8 byte)
{
	while(USART_GetFlagStatus(USART1,USART_FLAG_TC) == RESET);
	USART_SendData(USART1, byte);
}

//��������
u8 Usart_RecvByte(void)
{
	while(USART_GetFlagStatus(USART1,USART_FLAG_RXNE) == RESET);
	return USART_ReceiveData(USART1);
}

//printf����ʵ��

int fputc(int c, FILE * stream)
{
	Usart_SendByte(c);
	return c;
}


