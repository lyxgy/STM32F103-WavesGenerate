#include "sys.h"
#include <stdio.h>
#include <string.h>
#include "dac.h"
#include "usart.h"

// 命令处理函数
int main(void) {   
		SystemInit();
		uart_init(115200);
    dac_config_init(); 
		printf("DAC Waveform Generator Ready!\r\n");
    printf("Commands: WAVE:SINE,SQUARE,TRIANGLE\r\n");
    printf("          FREQ:100-50000\r\n");
    printf("          DUTY:1-100 (for square)\r\n");
    printf("          AMP:1-100\r\n");
    while(1) {
       
    }
}
