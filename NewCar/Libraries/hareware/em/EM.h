#ifndef _EM_H
#define _EM_H

#include "headfile.h"
#include "misc.h"
#include "common.h"

typedef struct 
{
	float KpPos;												//正向P系数
	float KiPos;												//正向I系数						
	float KdPos;												//正向D系数
		
	float Kp_OUT;												//P输出
	float Kp_OUT_His;
	float Ki_OUT;												//I输出
	float Kd_OUT;												//D输出

	float E_k;													//这一次与目标的差值
	float E_k_1;												//上一次的差值（用于微分）
	float E_k_2;												//上两次的差值
	float E_k_S;												//累加的差值（用于积分）

	float P_max;												//P最大值系数
	float I_max;												//I最大值系数
	float D_max;												//D最大值系数

	float PID_out;												//PID输出
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






