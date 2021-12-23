#include "base.h" 
static u8 fac_us=0;
void delay_init(u8 SYSCLK) 
{ 
	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);//SysTickƵ��Ϊ HCLK STM32
	fac_us=SYSCLK; 
}
void delay_ns (u8 t) 
{ 
	do { ; } 
	while (--t); 
}
void delay_us(u32 nus) 
{ 
	u32 ticks; 
	u32 told,tnow,tcnt=0; 
	u32 reload=SysTick->LOAD; //LOAD��ֵ 
	ticks=nus*fac_us; //��Ҫ�Ľ����� 
	told=SysTick->VAL; //�ս�?ʱ�ļ�����ֵ 
	while(1) 
	{ 
		tnow=SysTick->VAL; 
		if(tnow!=told) 
		{ 
			if(tnow<told)tcnt+=told-tnow; //��?ע��?��SYSTICK��?���ݼ� �ļ������Ϳ�����. 
			else tcnt+=reload-tnow+told; 
			told=tnow; 
			if(tcnt>=ticks)break; //ʱ�䳬��/����Ҫ�ӳٵ�ʱ��,���˳�. 
			} 
	}; 
}
//��ʱnms 
//nms:Ҫ��ʱ��ms�� 
void delay_ms(u16 nms) 
{ 
	u32 i; 
	for(i=0;i<nms;i++) 
	delay_us(1000); 
}
