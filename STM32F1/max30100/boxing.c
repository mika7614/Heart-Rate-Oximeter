#include "boxing.h"
#include "Lcd_Driver.h"
#include "MAX30100_PulseOximeter.h"

u32 Sum[10] = {0}, Average_Val = 0;
u8 Sum_Count = 0;
char Deffience_Val = 0;
//������ֵ�˲�����
float Average_filtering(void)
{
	Sum[Sum_Count] = rawIRValue;
	u16 irvalue = Sum[Sum_Count];
	Sum_Count++;
	Sum_Count %= 10;
	Average_Val = (Sum[0]+Sum[1]+Sum[2]+Sum[3]+Sum[4]+Sum[5]+Sum[6]+Sum[7]+Sum[8]+Sum[9])/10;
	if(irvalue < Average_Val)
		Deffience_Val = Average_Val - irvalue;
	else
		Deffience_Val = irvalue - Average_Val;	
	return Deffience_Val * 0.3 + 0.5;
}

//	HighY; HighX; StartX; StartY; SpeedX; Back_Color; Line_Color;
__DIAGRAM Rate_Diagram = {120,120,5,5,1,WHITE,RED};
void Draw_Diagram(u16 Value)
{
	static u16	rate_y, rate_y_old;			//�ĵ�ͼ���������
	static u16  rate_x = 5;        			//�ĵ�ͼ��������ʼλ�ò���
	Gui_DrawLine(Rate_Diagram.StartX,Rate_Diagram.StartY,Rate_Diagram.StartX,Rate_Diagram.HighY+Rate_Diagram.StartY,BLACK);
	Gui_DrawLine(Rate_Diagram.StartX,Rate_Diagram.HighY+Rate_Diagram.StartY,Rate_Diagram.HighX + Rate_Diagram.StartX,Rate_Diagram.HighY+Rate_Diagram.StartY,BLACK);
	if(Value < 120)
	{
		rate_y = (Rate_Diagram.HighY + Rate_Diagram.StartY) - Value;	//��ǰ�ĵ�ͼ������
		if(rate_x < Rate_Diagram.HighX)
		{
			rate_x += Rate_Diagram.SpeedX;									//�����ĵ�ͼ������
//			for(int i=0; i<Rate_Diagram.SpeedX; i++)
				Gui_DrawLine(rate_x-0, Rate_Diagram.StartY,rate_x-0, Rate_Diagram.HighY+Rate_Diagram.StartY, Rate_Diagram.Back_Color);//�����һ���߶�
			Gui_DrawLine((rate_x - Rate_Diagram.SpeedX),rate_y_old,rate_x,rate_y,Rate_Diagram.Line_Color);		//���Ʋ���ͼ
		}
		else	
		{
			rate_x = Rate_Diagram.StartX;
			Gui_DrawLine((rate_x),rate_y_old,rate_x,rate_y,Rate_Diagram.Line_Color);		//���Ʋ���ͼ
		}
		
		rate_y_old = rate_y;		//��¼��һ�ε�������
	}

}

