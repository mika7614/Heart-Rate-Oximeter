#include "boxing.h"
#include "Lcd_Driver.h"
#include "MAX30100_PulseOximeter.h"

u32 Sum[10] = {0}, Average_Val = 0;
u8 Sum_Count = 0;
char Deffience_Val = 0;
//将心率值滤波处理
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
	static u16	rate_y, rate_y_old;			//心电图纵坐标参数
	static u16  rate_x = 5;        			//心电图横坐标起始位置参数
	Gui_DrawLine(Rate_Diagram.StartX,Rate_Diagram.StartY,Rate_Diagram.StartX,Rate_Diagram.HighY+Rate_Diagram.StartY,BLACK);
	Gui_DrawLine(Rate_Diagram.StartX,Rate_Diagram.HighY+Rate_Diagram.StartY,Rate_Diagram.HighX + Rate_Diagram.StartX,Rate_Diagram.HighY+Rate_Diagram.StartY,BLACK);
	if(Value < 120)
	{
		rate_y = (Rate_Diagram.HighY + Rate_Diagram.StartY) - Value;	//当前心电图纵坐标
		if(rate_x < Rate_Diagram.HighX)
		{
			rate_x += Rate_Diagram.SpeedX;									//更新心电图横坐标
//			for(int i=0; i<Rate_Diagram.SpeedX; i++)
				Gui_DrawLine(rate_x-0, Rate_Diagram.StartY,rate_x-0, Rate_Diagram.HighY+Rate_Diagram.StartY, Rate_Diagram.Back_Color);//清除上一次线段
			Gui_DrawLine((rate_x - Rate_Diagram.SpeedX),rate_y_old,rate_x,rate_y,Rate_Diagram.Line_Color);		//绘制波形图
		}
		else	
		{
			rate_x = Rate_Diagram.StartX;
			Gui_DrawLine((rate_x),rate_y_old,rate_x,rate_y,Rate_Diagram.Line_Color);		//绘制波形图
		}
		
		rate_y_old = rate_y;		//记录上一次的纵坐标
	}

}

