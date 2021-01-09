#include "headfile.h"

uint8 key_interrupt_flag;//�����жϱ�־λ
uint8 key_value_last;//��һ����ֵ
uint8 key_value;//��ǰ��ֵ

void Key_init(void)//������ʼ��
{
	port_init (D0, IRQ_EITHER | PF | ALT1 | PULLUP );	//��ʼ�� D1 �ܽţ��½��ش����жϣ�����Դ�˲��������ù���ΪGPIO������Ϊ���� ����������
	port_init (D1, IRQ_EITHER | PF | ALT1 | PULLUP );
	port_init (D2, IRQ_EITHER | PF | ALT1 | PULLUP );
	set_irq_priority(PORTD_IRQn,2);						//�������ȼ�
	enable_irq(PORTD_IRQn);								//��PORTD�жϿ���
	EnableInterrupts;									//���ܵ��жϿ���

	key_value=7;																//ɶ�����������������Ӧ�����������Ǻ���Ӳ�������⣬û����ʱ����5
	key_interrupt_flag=0;												//�����жϱ�־λ���ڶ���ļ�����
}

void Key_select(void)
{
	unsigned char a[]="dir";
	if(key_interrupt_flag==1)
	{
		key_interrupt_flag=0;											//����������µı�־
		OLED_Print_Num1(60,3,key_value);
		switch(key_value)
		{
			case UP: ELE_PID_Direction.KpPos+=0.2f;break;
			case DOWN: ELE_PID_Direction.KpPos-=0.2f;break;
			case MID: ELE_PID_Direction.KdPos-=0.2f;break;
			case RIGHT: ELE_PID_Direction.KdPos+=0.2f;break;
			case KEY1: g_right_flag=!g_right_flag;OLED_P6x8Str(60,5,a);OLED_Print_Num1(80,5,g_right_flag);break;
			case KEY2: have_enter_curve=curve_flag=0;break;
		}		
	}	
}
