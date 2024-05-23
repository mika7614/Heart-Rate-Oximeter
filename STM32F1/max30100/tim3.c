#include "tim3.h"
#include "MAX30100_PulseOximeter.h"

void TIM3_IRQHandler(void)
{
	if(TIM_GetFlagStatus(TIM3,TIM_IT_Update)==SET)
	{
		TIM_ClearFlag(TIM3, TIM_IT_Update);
		POupdate();					//��������
	}
}

void Time3_Init(u16 psc,u16 arr)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	//��ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	//���ö�ʱ�� ��Ƶ  ����		
	TIM_TimeBaseInitStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = arr - 1;
	TIM_TimeBaseInitStructure.TIM_Prescaler = psc - 1;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);
	
	TIM_ARRPreloadConfig(TIM3, ENABLE);//װ��ֵ Ԥװ��ʹ��

	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
	NVIC_SetPriority(TIM3_IRQn, 1);
	NVIC_EnableIRQ(TIM3_IRQn);
	TIM_Cmd(TIM3,ENABLE);//ʹ�ܶ�ʱ��
}

