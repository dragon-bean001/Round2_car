#include "motor.h"
void Motor_init()
{
	ftm_pwm_init(ftm3,ftm_ch1,50,1950);//��ʼ��ftm0ģ�飬0ͨ��Ϊ50HZ��ռ�ձ�Ϊ�ٷ�֮50��Ĭ�Ͼ���Ϊ1000 ���Ŷ�Ӧ�鿴MK60DN10_port_cfg.h
	ftm_pwm_init(ftm3,ftm_ch2,50,1950);
	ftm_pwm_init(ftm3,ftm_ch3,50,1950);
	ftm_pwm_init(ftm3,ftm_ch4,50,1950);
}
void Motor34_speed(uint16 motor3,uint16 motor4)
{
	   ftm_pwm_duty(ftm3,ftm_ch1,motor3); //motor3
		 ftm_pwm_duty(ftm3,ftm_ch2,motor4);//motor4
		 
}
void Motor12_speed(uint16 motor1,uint16 motor2)
{
		 ftm_pwm_duty(ftm3,ftm_ch3,motor1);//motor1
		 ftm_pwm_duty(ftm3,ftm_ch4,motor2);//motor2
}
