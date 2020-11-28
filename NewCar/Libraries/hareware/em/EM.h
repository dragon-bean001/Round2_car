#ifndef _EM_H
#define _EM_H

#include "headfile.h"
#include "misc.h"
#include "common.h"

typedef struct 
{
	float KpPos;												//����Pϵ��
	float KiPos;												//����Iϵ��						
	float KdPos;												//����Dϵ��
		
	float Kp_OUT;												//P���
	float Kp_OUT_His;
	float Ki_OUT;												//I���
	float Kd_OUT;												//D���

	float E_k;													//��һ����Ŀ��Ĳ�ֵ
	float E_k_1;												//��һ�εĲ�ֵ������΢�֣�
	float E_k_2;												//�����εĲ�ֵ
	float E_k_S;												//�ۼӵĲ�ֵ�����ڻ��֣�

	float P_max;												//P���ֵϵ��
	float I_max;												//I���ֵϵ��
	float D_max;												//D���ֵϵ��

	float PID_out;												//PID���
}PID_t;

extern PID_t ELE_PID_Direction;
#define EM_left_max   50000.0f
#define EM_right_max  50000.0f
#define EM_mid_max 55000.0f

void EM_init(void);
void EM_store(void);
void EM_get(void);
void EM_dectect(void);
float PID_Direction_Pos_Neg(PID_t * pid,float newE_k);
void Round_Detect(void);

#endif






