#ifndef _MOTOR_H
#define _MOTOR_H
#include "headfile.h"
#include "misc.h"
#include "common.h"

void Motor_init(void);
void Motor12_speed(uint16 motor1,uint16 motor2);
void Motor34_speed(uint16 motor3,uint16 motor4);

#endif
