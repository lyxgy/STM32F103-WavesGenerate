#include "smg.h"
#include "delay.h"

//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK NANO STM32开发板
//数码管驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2018/3/27
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2018-2028
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////  

//数码管驱动IO初始化
void LED_SMG_Init(void)
{

   GPIO_InitTypeDef  GPIO_InitStructure;

   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC|RCC_APB2Periph_AFIO, ENABLE);//使能PB,PC端口时钟
   GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);//关闭jtag，使能SWD，可以用SWD模式调试 PB4做普通IO口使用,否则不能当IO使用
   
   //74HC595  DS-PB3 LCLK-PB4 SCK-PB5
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5;//PB3、PB4、PB5
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
   GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIOB3/4/5

   //74HC138  A0-PC10 A1-PC11 A2-PC12
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12;
   GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化GPIOC10/11/12

   GPIO_ResetBits(GPIOB,GPIO_Pin_3|GPIO_Pin_5);
   GPIO_SetBits(GPIOB,GPIO_Pin_4);
   GPIO_ResetBits(GPIOC,GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12);

}
//74HC138驱动
//数码管位选
//num:要显示的数码管编号 0-7(共8个数码管)
void LED_Wei(u8 num)
{
    LED_A0=num&0x01;
	LED_A1=(num&0x02)>>1;
	LED_A2=(num&0x04)>>2;
}
//74HC595驱动
//数码管显示
//duan:显示的段码
//wei:要显示的数码管编号 0-7(共8个数码管)
void LED_Write_Data(u8 duan,u8 wei)
{
	u8 i;
	for( i=0;i<8;i++)//先送段
	{
		LED_DS=(duan>>i)&0x01;
		LED_SCK=0;
		delay_us(5);
		LED_SCK=1;
	}
    LED_Wei(wei);//后选中位
}
//74HC595驱动
//数码管刷新显示
void LED_Refresh(void)
{
	LED_LCLK=1;
	delay_us(5);
	LED_LCLK=0;
}

