/********************************************
逐飞科技 总钻风-摄像头  历程
Designed by Fly Sir
软件版本:V1.1
最后更新:2016年5月3日
相关信息参考下列地址：
淘宝店：https://seekfree.taobao.com/
------------------------------------
软件版本： IAR 7.2 or MDK 5.17
目标核心： MK60DN512VLL10
============================================
MT9V032接线定义：
------------------------------------ 
    模块管脚            单片机管脚
    SDA(51的RX)         PTC17
    SCL(51的TX)         PTC16
	场中断(VSY)         PTC6
    像素中断(PCLK)      PTC18
    数据口(D0-D7)       PTC8-PTC15 

    串口  
    波特率 115200 
    数据位 8 
    校验位 无
    停止位 1位
    流控   无
	串口连接注意事项：切勿使用蓝牙等无线串口连接
    RX                  PTD3
    TX                  PTD2
============================================

分辨率是                188*120
摄像头参数设置可以到    SEEKFREE-->h_file-->SEEKFREE_MT9V032.h

总钻风-摄像头测试步骤：
1.下载程序到开发板
2.插上串口线或者USB转TTL
3.接好MT9V032模块接线
4.通电在TFT液晶上即可观看    
*********************************************/  
#include "headfile.h"



uint16 dat;

int main(void)
{
    get_clk();//上电后必须运行一次这个函数，获取各个频率信息，便于后面各个模块的参数设置
	  gpio_init(D15,GPO,1);
  //相关的库函数在 MK60DN10_ftm.c 里面
	//MK60DN共有三个FTM模块FTM0、FTM1、FTM2，每一个模块只能产生一个频率的PWM，意味着一个模块下所有的通道频率必须一致，
	//三个模块就只能产生三种不同频率的PWM。同一个模块不同通道占空比可以不一样。
	Motor_init();
	OLED_Init();   
	EM_init();
	Key_init();
	ELE_PID_Direction.KpPos=2.0f;
	ELE_PID_Direction.KdPos=1.0f;
   while(1)
	 {
		 EM_get();
		 EM_store();
		 Key_select();
		 
		 //systick_delay_ms(100);
		 EM_dectect();
		 Round_Detect();
		 
	 }
 }


