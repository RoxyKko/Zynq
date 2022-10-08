/*
 * main.c
 *
 *  Created on: 2022年10月8日
 *      Author: NJY_r
 */

#include "stdio.h"
#include "xparameters.h"
#include "xgpiops.h"
#include "sleep.h"

#define GPIO_DEVICE_ID  	XPAR_XGPIOPS_0_DEVICE_ID

//核心板上PS端LED
#define MIO0_LED 0
#define MIO7_LED 7
#define MIO8_LED 8

XGpioPs_Config *ConfigPtr;

XGpioPs Gpio;

int main()
{

	printf("GPIO MIO TEST!\n\r");

	/*初始化GPIO驱动*/

	//根据器件ID查找器件配置信息
	ConfigPtr = XGpioPs_LookupConfig(GPIO_DEVICE_ID);

	//初始化GPIO驱动
	XGpioPs_CfgInitialize(&Gpio, ConfigPtr, ConfigPtr->BaseAddr);

	/*设置GPIO方向为输出 0：输入 1：输出*/
	XGpioPs_SetDirectionPin(&Gpio, MIO0_LED, 1);
	XGpioPs_SetDirectionPin(&Gpio, MIO7_LED, 1);
	XGpioPs_SetDirectionPin(&Gpio, MIO8_LED, 1);
	/*设置输出使能  0：关闭 1：打开*/
	XGpioPs_SetOutputEnablePin(&Gpio, MIO0_LED, 1);
	XGpioPs_SetOutputEnablePin(&Gpio, MIO7_LED, 1);
	XGpioPs_SetOutputEnablePin(&Gpio, MIO8_LED, 1);

	/*写数据到GPIO引脚 0：低电平 1：高电平 */
	XGpioPs_WritePin(&Gpio, MIO0_LED, 1);
	XGpioPs_WritePin(&Gpio, MIO7_LED, 1);
	XGpioPs_WritePin(&Gpio, MIO8_LED, 1);

	while(1)
	{
		//电亮
		XGpioPs_WritePin(&Gpio, MIO0_LED, 1);
		XGpioPs_WritePin(&Gpio, MIO7_LED, 0);
		XGpioPs_WritePin(&Gpio, MIO8_LED, 1);
		//延时
		usleep(200000);
		//熄灭
		XGpioPs_WritePin(&Gpio, MIO0_LED, 0);
		XGpioPs_WritePin(&Gpio, MIO7_LED, 1);
		XGpioPs_WritePin(&Gpio, MIO8_LED, 0);
		//延时
		usleep(200000);
	}

	return 0;
}
