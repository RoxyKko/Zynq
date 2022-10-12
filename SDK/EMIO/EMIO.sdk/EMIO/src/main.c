/*
 * main.c
 *
 *  Created on: 2022��10��12��
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
#define MIO11_KEY 11
#define MIO12_KEY 12

#define EMIO_PWM 54
#define EMIO_KEY 55

XGpioPs_Config *ConfigPtr;

XGpioPs Gpio;

uint8_t LEDmode = 0;

//������
void runLED()
{
	XGpioPs_WritePin(&Gpio, MIO0_LED, 1);
	XGpioPs_WritePin(&Gpio, MIO7_LED, 0);
	XGpioPs_WritePin(&Gpio, MIO8_LED, 0);

	//��ʱ
	usleep(200000);

	XGpioPs_WritePin(&Gpio, MIO0_LED, 0);
	XGpioPs_WritePin(&Gpio, MIO7_LED, 1);
	XGpioPs_WritePin(&Gpio, MIO8_LED, 0);

	//��ʱ
	usleep(200000);

	XGpioPs_WritePin(&Gpio, MIO0_LED, 0);
	XGpioPs_WritePin(&Gpio, MIO7_LED, 0);
	XGpioPs_WritePin(&Gpio, MIO8_LED, 1);

	//��ʱ
	usleep(200000);
}

//������
void BreatLED()
{
	int a;
	int b = 401;
	for(a=1; a<b; a++)
	{
		XGpioPs_WritePin(&Gpio, MIO7_LED, 0);
		XGpioPs_WritePin(&Gpio, MIO8_LED, 1);
		usleep(a);
		XGpioPs_WritePin(&Gpio, MIO7_LED, 1);
		XGpioPs_WritePin(&Gpio, MIO8_LED, 0);
		usleep(b-a);
	}
	for(a=b; a>0; a--)
	{
		XGpioPs_WritePin(&Gpio, MIO7_LED, 0);
		XGpioPs_WritePin(&Gpio, MIO8_LED, 1);
		usleep(a);
		XGpioPs_WritePin(&Gpio, MIO7_LED, 1);
		XGpioPs_WritePin(&Gpio, MIO8_LED, 0);
		usleep(b-a+1);
	}
}

void PWM()
{

}


int main()
{

	printf("GPIO EMIO TEST!\n\r");

	/*��ʼ��GPIO����*/

	//��������ID��������������Ϣ
	ConfigPtr = XGpioPs_LookupConfig(GPIO_DEVICE_ID);

	//��ʼ��GPIO����
	XGpioPs_CfgInitialize(&Gpio, ConfigPtr, ConfigPtr->BaseAddr);

	/*����GPIO����Ϊ��� 0������ 1�����*/
	XGpioPs_SetDirectionPin(&Gpio, MIO0_LED, 1);
	XGpioPs_SetDirectionPin(&Gpio, MIO7_LED, 1);
	XGpioPs_SetDirectionPin(&Gpio, MIO8_LED, 1);
	XGpioPs_SetDirectionPin(&Gpio, MIO11_KEY, 0);
	XGpioPs_SetDirectionPin(&Gpio, MIO12_KEY, 0);

	XGpioPs_SetDirectionPin(&Gpio, EMIO_PWM, 1);
	XGpioPs_SetDirectionPin(&Gpio, EMIO_KEY, 0);
	/*�������ʹ��  0���ر� 1����*/
	XGpioPs_SetOutputEnablePin(&Gpio, MIO0_LED, 1);
	XGpioPs_SetOutputEnablePin(&Gpio, MIO7_LED, 1);
	XGpioPs_SetOutputEnablePin(&Gpio, MIO8_LED, 1);

	XGpioPs_SetOutputEnablePin(&Gpio, EMIO_PWM, 1);


	/*д���ݵ�GPIO���� 0���͵�ƽ 1���ߵ�ƽ */
	XGpioPs_WritePin(&Gpio, MIO0_LED, 1);
	XGpioPs_WritePin(&Gpio, MIO7_LED, 1);
	XGpioPs_WritePin(&Gpio, MIO8_LED, 1);

	XGpioPs_WritePin(&Gpio, EMIO_PWM, 1);


	while(1)
	{
		//����1����LEDģʽ
		if (XGpioPs_ReadPin(&Gpio, MIO11_KEY) == 0)
		{
			LEDmode++;
			LEDmode%=2;
		}
		//����2����PWM״̬
		if (XGpioPs_ReadPin(&Gpio, MIO12_KEY) == 0)
		{
			LEDmode++;
			LEDmode%=2;
		}



		if (LEDmode == 0)
		{
			printf("now is runLED\r\n");
			//������
			runLED();
		}
		else
		{
			printf("now is BreatLED\r\n");
			//������
			BreatLED();
		}

	}

	return 0;
}

