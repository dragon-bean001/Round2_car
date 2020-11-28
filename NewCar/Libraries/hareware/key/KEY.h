#ifndef _KEY_H
#define _KEY_H
#include "headfile.h"
#define get_key  gpio_get(D1)*2+gpio_get(D0)*1+gpio_get(D2)*4   //��ȡ�������
#define UP    				2   //����ֵ��7��û�а����κμ���Ҳ�����������Ŷ�Ϊ�ߵ�ƽ
#define DOWN   				6		//			*************
#define RIGHT   			4   //			*						*					  up
#define LEFT    			5		//			*	  oled  	*    left  mid  right
#define MID   				1		//      *						*					 down
#define KEY1  				0   //			*************
#define KEY2  				3  //key3��ʵ����Ч��
#define NONE				7
extern uint8 key_interrupt_flag;//�����жϱ�־λ
extern uint8 key_value_last;//��һ����ֵ
extern uint8 key_value;//��ǰ��ֵ

void Key_init(void);//������ʼ��
void Key_select(void);//�����жϺ���
#endif


