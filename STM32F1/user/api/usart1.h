#ifndef __USART1_H
#define __USART1_H

#include "stm32f10x.h"


void USART1_Config(u32 brr);
void Usart_SendByte(u8 byte);
u8 Usart_RecvByte(void);

#endif
