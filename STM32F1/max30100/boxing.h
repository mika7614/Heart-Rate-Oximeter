#ifndef _BOXING_H_
#define _BOXING_H_

#include "stm32f10x.h"

typedef struct Diagram{
	u8 HighY;						//����ϵ�ĸ߶�
	u8 HighX;						//����ϵ�Ŀ��
	u8 StartX;					
	u8 StartY;
	u8 SpeedX;
	u16 Back_Color;
	u16 Line_Color;
}__DIAGRAM;

float Average_filtering(void);
void Draw_Diagram(u16 Value);

#endif
