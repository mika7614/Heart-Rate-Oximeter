#include "delay.h"


vu32 RunTime = 0;
vu32 LedRun[2] = {0,500};
vu32 MAXRun[2] = {0, 10};
void SysTick_Handler(void)//ϵͳ�δ�ʱ���жϷ�����
{
	RunTime++;
	LedRun[0]++;
	MAXRun[0]++;
}

//ϵͳ�δ�ʱ����ʼ��
void SysTick_Init(uint32_t tick)
{
	SysTick_Config(tick);
}

//ms������ʱ
void Delay_ms(uint32_t time)
{
	uint32_t Time = RunTime + time;
	while(RunTime < Time)
	{}	
}

//us��ʱ
void Delay_us(uint32_t time)
{
	while(time--)
		delay_1us();
}

