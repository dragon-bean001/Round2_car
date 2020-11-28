#include "headfile.h"

uint8 key_interrupt_flag;//按键中断标志位
uint8 key_value_last;//上一个键值
uint8 key_value;//当前键值

void Key_init(void)//按键初始化
{
	port_init (D0, IRQ_EITHER | PF | ALT1 | PULLUP );	//初始化 D1 管脚，下降沿触发中断，带无源滤波器，复用功能为GPIO并设置为输入 ，上拉电阻
	port_init (D1, IRQ_EITHER | PF | ALT1 | PULLUP );
	port_init (D2, IRQ_EITHER | PF | ALT1 | PULLUP );
	set_irq_priority(PORTD_IRQn,2);						//设置优先级
	enable_irq(PORTD_IRQn);								//打开PORTD中断开关
	EnableInterrupts;									//打开总的中断开关

	key_value=7;																//啥都不按的情况，本来应该怎样，但是好像硬件有问题，没按的时候是5
	key_interrupt_flag=0;												//按键中断标志位，在多个文件传递
}

void Key_select(void)
{
	if(key_interrupt_flag==1)
	{
		key_interrupt_flag=0;											//清除按键按下的标志
		OLED_Print_Num1(60,3,key_value);
		switch(key_value)
		{
			case UP: ELE_PID_Direction.KpPos+=0.2f;break;
			case DOWN: ELE_PID_Direction.KpPos-=0.2f;break;
			case MID: ELE_PID_Direction.KdPos-=0.2f;break;
			case RIGHT: ELE_PID_Direction.KdPos+=0.2f;break;
			
		}		
	}	
}
