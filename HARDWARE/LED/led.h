#ifndef __LED_H
#define __LED_H	 
#include "sys.h"
#include "stm32f10x.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK NANO STM32������
//LED��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2018/3/27
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2018-2028
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 

//#define LED0 PCout(0)	// PC0
//#define LED1 PCout(1)	// PC1
//#define LED2 PCout(2)	// PC2
//#define LED3 PCout(3)	// PC3
//#define LED4 PCout(4)	// PC4
//#define LED5 PCout(5)	// PC5
//#define LED6 PCout(6)	// PC6
//#define LED7 PCout(7)	// PC7

typedef enum {
    LEFT_TO_RIGHT,
    RIGHT_TO_LEFT,
    CENTER_OUT,
    OUT_CENTER
} FlowDirection;

#define LED1_PIN  GPIO_Pin_0
#define LED2_PIN  GPIO_Pin_1
#define LED3_PIN  GPIO_Pin_2
#define LED4_PIN  GPIO_Pin_3
#define LED5_PIN  GPIO_Pin_4
#define LED6_PIN  GPIO_Pin_5
#define LED7_PIN  GPIO_Pin_6
#define LED8_PIN  GPIO_Pin_7

#define LED_PINS (LED1_PIN | LED2_PIN | LED3_PIN | LED4_PIN | \
                 LED5_PIN | LED6_PIN | LED7_PIN | LED8_PIN)



void LED_GPIO_Init(void);
void Set_LED_State(uint16_t pin, uint8_t state);
void LED_Flow(FlowDirection direction, uint16_t delay_ms);
void LED_Running_Lights(void);
void Delay_ms(uint32_t n);
		 				    
#endif
