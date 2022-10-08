/*
 * main.c
 *
 *  Created on: 2022��10��8��
 *      Author: NJY_r
 */

#include "stdio.h"
#include "xparameters.h"
#include "xgpiops.h"
#include "sleep.h"

#define GPIO_DEVICE_ID  	XPAR_XGPIOPS_0_DEVICE_ID

//���İ���PS��LED
#define MIO0_LED 0
#define MIO7_LED 7
#define MIO8_LED 8

XGpioPs_Config *ConfigPtr;

XGpioPs Gpio;

int main()
{

	printf("GPIO MIO TEST!\n\r");

	/*��ʼ��GPIO����*/

	//��������ID��������������Ϣ
	ConfigPtr = XGpioPs_LookupConfig(GPIO_DEVICE_ID);

	//��ʼ��GPIO����
	XGpioPs_CfgInitialize(&Gpio, ConfigPtr, ConfigPtr->BaseAddr);

	/*����GPIO����Ϊ��� 0������ 1�����*/
	XGpioPs_SetDirectionPin(&Gpio, MIO0_LED, 1);
	XGpioPs_SetDirectionPin(&Gpio, MIO7_LED, 1);
	XGpioPs_SetDirectionPin(&Gpio, MIO8_LED, 1);
	/*�������ʹ��  0���ر� 1����*/
	XGpioPs_SetOutputEnablePin(&Gpio, MIO0_LED, 1);
	XGpioPs_SetOutputEnablePin(&Gpio, MIO7_LED, 1);
	XGpioPs_SetOutputEnablePin(&Gpio, MIO8_LED, 1);

	/*д���ݵ�GPIO���� 0���͵�ƽ 1���ߵ�ƽ */
	XGpioPs_WritePin(&Gpio, MIO0_LED, 1);
	XGpioPs_WritePin(&Gpio, MIO7_LED, 1);
	XGpioPs_WritePin(&Gpio, MIO8_LED, 1);

	while(1)
	{
		//����
		XGpioPs_WritePin(&Gpio, MIO0_LED, 1);
		XGpioPs_WritePin(&Gpio, MIO7_LED, 0);
		XGpioPs_WritePin(&Gpio, MIO8_LED, 1);
		//��ʱ
		usleep(200000);
		//Ϩ��
		XGpioPs_WritePin(&Gpio, MIO0_LED, 0);
		XGpioPs_WritePin(&Gpio, MIO7_LED, 1);
		XGpioPs_WritePin(&Gpio, MIO8_LED, 0);
		//��ʱ
		usleep(200000);
	}

	return 0;
}