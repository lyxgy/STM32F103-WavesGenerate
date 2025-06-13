#include "led.h"

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
    
 void LED_GPIO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    
    GPIO_InitStructure.GPIO_Pin = LED_PINS;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    
    GPIO_SetBits(GPIOC, LED_PINS);
}

void Set_LED_State(uint16_t pin, uint8_t state)
{
    if (state) {
        GPIO_ResetBits(GPIOC, pin);
    } else {
        GPIO_SetBits(GPIOC, pin);
    }
}


void LED_Flow(FlowDirection direction, uint16_t delay_ms)
{
	
    static const uint16_t leds[] = {
        LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN,
        LED5_PIN, LED6_PIN, LED7_PIN, LED8_PIN
    };
    const int count = sizeof(leds) / sizeof(leds[0]);
    
    int i; 
    
    switch (direction) {
        case LEFT_TO_RIGHT:
            for (i = 0; i < count; i++) {
                Set_LED_State(leds[i], 1);
                Delay_ms(delay_ms);
                Set_LED_State(leds[i], 0);
            }
            break;
            
        case RIGHT_TO_LEFT:
            for (i = count - 1; i >= 0; i--) {
                Set_LED_State(leds[i], 1);
                Delay_ms(delay_ms);
                Set_LED_State(leds[i], 0);
            }
            break;
            
        case CENTER_OUT:
            for (i = 3; i >= 0; i--) {
                Set_LED_State(leds[i], 1);
                Set_LED_State(leds[7-i], 1);
                Delay_ms(delay_ms);
                Set_LED_State(leds[i], 0);
                Set_LED_State(leds[7-i], 0);
            }
            break;
            
        case OUT_CENTER:
            for (i = 0; i < 4; i++) {
                Set_LED_State(leds[i], 1);
                Set_LED_State(leds[7-i], 1);
                Delay_ms(delay_ms);
                Set_LED_State(leds[i], 0);
                Set_LED_State(leds[7-i], 0);
            }
            break;
    }
}

void LED_Running_Lights(void)
{
    while (1) {
        LED_Flow(LEFT_TO_RIGHT, 100);
        LED_Flow(RIGHT_TO_LEFT, 100);
        LED_Flow(CENTER_OUT, 150);
        LED_Flow(OUT_CENTER, 150);
    }
}

void Delay_ms(uint32_t n)
{
    uint32_t i; 
    for (i = 0; i < n * 8000; i++);
}
