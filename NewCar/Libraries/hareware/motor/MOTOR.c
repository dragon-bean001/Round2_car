#include "motor.h"
void Motor_init()
{
	ftm_pwm_init(ftm3,ftm_ch1,50,1950);//初始化ftm0模块，0通道为50HZ，占空比为百分之50，默认精度为1000 引脚对应查看MK60DN10_port_cfg.h
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
