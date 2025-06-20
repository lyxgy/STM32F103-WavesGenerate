#include "sys.h"
#include "dac.h"
#include <stdio.h>
#include <string.h>
uint16_t sin_wave[64]={2048,2251,2453,2651,2843,3027,3201,3364,3513,3648,3767,3870,3953,4018,4064,4089,4094,4079,4044,3988,3914,3821,3710,3583,3440,3284,3115,2936,2748,2553,2353,2150,1945,1742,1542,1347,1159,980,811,655,512,385,274,181,107,51,16,1,6,31,77,142,225,328,447,582,731,894,1068,1252,1444,1642,1844,2047};

uint16_t triangle_wave[512]={0,16,32,48,64,80,96,112,128,144,160,176,192,208,224,240,256,272,288,305,321,337,353,369,385,401,417,433,449,465,481,497,513,529,545,561,577,593,609,625,641,657,673,689,705,721,737,753,769,785,801,817,833,849,865,882,898,914,930,946,962,978,994,1010,1026,1042,1058,1074,1090,1106,1122,1138,1154,1170,1186,1202,1218,1234,1250,1266,1282,1298,1314,1330,1346,1362,1378,1394,1410,1426,1442,1458,1475,1491,1507,1523,1539,1555,1571,1587,1603,1619,1635,1651,1667,1683,1699,1715,1731,1747,1763,1779,1795,1811,1827,1843,1859,1875,1891,1907,1923,1939,1955,1971,1987,2003,2019,2035,2052,2068,2084,2100,2116,2132,2148,2164,2180,2196,2212,2228,2244,2260,2276,2292,2308,2324,2340,2356,2372,2388,2404,2420,2436,2452,2468,2484,2500,2516,2532,2548,2564,2580,2596,2612,2628,2645,2661,2677,2693,2709,2725,2741,2757,2773,2789,2805,2821,2837,2853,2869,2885,2901,2917,2933,2949,2965,2981,2997,3013,3029,3045,3061,3077,3093,3109,3125,3141,3157,3173,3189,3205,3222,3238,3254,3270,3286,3302,3318,3334,3350,3366,3382,3398,3414,3430,3446,3462,3478,3494,3510,3526,3542,3558,3574,3590,3606,3622,3638,3654,3670,3686,3702,3718,3734,3750,3766,3782,3798,3815,3831,3847,3863,3879,3895,3911,3927,3943,3959,3975,3991,4007,4023,4039,4055,4071,4087,
	4087,4071,4055,4039,4023,4007,3991,3975,3959,3943,3927,3911,3895,3879,3863,3847,3831,3815,3798,3782,3766,3750,3734,3718,3702,3686,3670,3654,3638,3622,3606,3590,3574,3558,3542,3526,3510,3494,3478,3462,3446,3430,3414,3398,3382,3366,3350,3334,3318,3302,3286,3270,3254,3238,3222,3205,3189,3173,3157,3141,3125,3109,3093,3077,3061,3045,3029,3013,2997,2981,2965,2949,2933,2917,2901,2885,2869,2853,2837,2821,2805,2789,2773,2757,2741,2725,2709,2693,2677,2661,2645,2628,2612,2596,2580,2564,2548,2532,2516,2500,2484,2468,2452,2436,2420,2404,2388,2372,2356,2340,2324,2308,2292,2276,2260,2244,2228,2212,2196,2180,2164,2148,2132,2116,2100,2084,2068,2052,2035,2019,2003,1987,1971,1955,1939,1923,1907,1891,1875,1859,1843,1827,1811,1795,1779,1763,1747,1731,1715,1699,1683,1667,1651,1635,1619,1603,1587,1571,1555,1539,1523,1507,1491,1475,1458,1442,1426,1410,1394,1378,1362,1346,1330,1314,1298,1282,1266,1250,1234,1218,1202,1186,1170,1154,1138,1122,1106,1090,1074,1058,1042,1026,1010,994,978,962,946,930,914,898,882,865,849,833,817,801,785,769,753,737,721,705,689,673,657,641,625,609,593,577,561,545,529,513,497,481,465,449,433,417,401,385,369,353,337,321,305,288,272,256,240,224,208,192,176,160,144,128,112,96,80,64,48,32,16,0
};
uint16_t square_wave[512] = {
    4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,
    4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,
    4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,
    4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,
    4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,
    4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,
    4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,
    4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,
    4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,
    4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,
    4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,
    4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,
    4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,
    4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,
    4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,
    4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,4095,
    
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

uint16_t sawtooth_wave[512] = {
    0, 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120, 
    128, 136, 144, 152, 160, 168, 176, 184, 192, 200, 208, 216, 224, 232, 240, 248, 
    256, 264, 272, 280, 288, 296, 305, 313, 321, 329, 337, 345, 353, 361, 369, 377, 
    385, 393, 401, 409, 417, 425, 433, 441, 449, 457, 465, 473, 481, 489, 497, 505, 
    513, 521, 529, 537, 545, 553, 561, 569, 577, 585, 593, 601, 609, 617, 625, 633, 
    641, 649, 657, 665, 673, 681, 689, 697, 705, 713, 721, 729, 737, 745, 753, 761, 
    769, 777, 785, 793, 801, 809, 817, 825, 833, 841, 849, 857, 865, 873, 882, 890, 
    898, 906, 914, 922, 930, 938, 946, 954, 962, 970, 978, 986, 994, 1002, 1010, 1018, 
    1026, 1034, 1042, 1050, 1058, 1066, 1074, 1082, 1090, 1098, 1106, 1114, 1122, 1130, 1138, 1146, 
    1154, 1162, 1170, 1178, 1186, 1194, 1202, 1210, 1218, 1226, 1234, 1242, 1250, 1258, 1266, 1274, 
    1282, 1290, 1298, 1306, 1314, 1322, 1330, 1338, 1346, 1354, 1362, 1370, 1378, 1386, 1394, 1402, 
    1410, 1418, 1426, 1434, 1442, 1450, 1458, 1466, 1474, 1482, 1490, 1499, 1507, 1515, 1523, 1531, 
    1539, 1547, 1555, 1563, 1571, 1579, 1587, 1595, 1603, 1611, 1619, 1627, 1635, 1643, 1651, 1659, 
    1667, 1675, 1683, 1691, 1699, 1707, 1715, 1723, 1731, 1739, 1747, 1755, 1763, 1771, 1779, 1787, 
    1795, 1803, 1811, 1819, 1827, 1835, 1843, 1851, 1859, 1867, 1875, 1883, 1891, 1899, 1907, 1915, 
    1923, 1931, 1939, 1947, 1955, 1963, 1971, 1979, 1987, 1995, 2003, 2011, 2019, 2027, 2035, 2043, 
    2051, 2059, 2067, 2075, 2083, 2091, 2099, 2107, 2115, 2123, 2132, 2140, 2148, 2156, 2164, 2172, 
    2180, 2188, 2196, 2204, 2212, 2220, 2228, 2236, 2244, 2252, 2260, 2268, 2276, 2284, 2292, 2300, 
    2308, 2316, 2324, 2332, 2340, 2348, 2356, 2364, 2372, 2380, 2388, 2396, 2404, 2412, 2420, 2428, 
    2436, 2444, 2452, 2460, 2468, 2476, 2484, 2492, 2500, 2508, 2516, 2524, 2532, 2540, 2548, 2556, 
    2564, 2572, 2580, 2588, 2596, 2604, 2612, 2620, 2628, 2636, 2644, 2652, 2660, 2668, 2676, 2684, 
    2692, 2700, 2708, 2716, 2725, 2733, 2741, 2749, 2757, 2765, 2773, 2781, 2789, 2797, 2805, 2813, 
    2821, 2829, 2837, 2845, 2853, 2861, 2869, 2877, 2885, 2893, 2901, 2909, 2917, 2925, 2933, 2941, 
    2949, 2957, 2965, 2973, 2981, 2989, 2997, 3005, 3013, 3021, 3029, 3037, 3045, 3053, 3061, 3069, 
    3077, 3085, 3093, 3101, 3109, 3117, 3125, 3133, 3141, 3149, 3157, 3165, 3173, 3181, 3189, 3197, 
    3205, 3213, 3221, 3229, 3237, 3245, 3253, 3261, 3269, 3277, 3285, 3293, 3301, 3309, 3318, 3326, 
    3334, 3342, 3350, 3358, 3366, 3374, 3382, 3390, 3398, 3406, 3414, 3422, 3430, 3438, 3446, 3454, 
    3462, 3470, 3478, 3486, 3494, 3502, 3510, 3518, 3526, 3534, 3542, 3550, 3558, 3566, 3574, 3582, 
    3590, 3598, 3606, 3614, 3622, 3630, 3638, 3646, 3654, 3662, 3670, 3678, 3686, 3694, 3702, 3710, 
    3718, 3726, 3734, 3742, 3750, 3758, 3766, 3774, 3782, 3790, 3798, 3806, 3814, 3822, 3830, 3838, 
    3846, 3854, 3862, 3870, 3878, 3886, 3894, 3902, 3910, 3918, 3926, 3934, 3942, 3950, 3959, 3967, 
    3975, 3983, 3991, 3999, 4007, 4015, 4023, 4031, 4039, 4047, 4055, 4063, 4071, 4079, 4087, 4095
};


uint16_t high_freq_square[2] = {4095, 0};  // 1M

uint16_t current_wave_buffer[512] = {2048,2251,2453,2651,2843,3027,3201,3364,3513,3648,3767,3870,3953,4018,4064,4089,4094,
	4079,4044,3988,3914,3821,3710,3583,3440,3284,3115,2936,2748,2553,2353,2150,1945,1742,1542,1347,1159,980,811,655,512,385,
	274,181,107,51,16,1,6,31,77,142,225,328,447,582,731,894,1068,1252,1444,1642,1844,2047,}
;

uint32_t timer_clock = 72000000;

WaveType current_wave_type = SINE_WAVE;
//uint16_t *current_wave_ptr = sin_wave;
uint16_t current_wave_length = sizeof(sin_wave)/sizeof(uint16_t);

uint32_t new_arr = (72000000 / (20000 * 64)) - 1; 

void dac_config_init(void)
{

  GPIO_InitTypeDef GPIO_InitStructure;
  DAC_InitTypeDef DAC_InitStruct;
  DMA_InitTypeDef DMA_InitStructure;
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);  //??GPIOA???
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);  //??DAC??
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA2, ENABLE);  //??DMA??
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);  //?????2??
  

  
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;    //??????
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;        //GPIO??A4
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;    //GPIO??50MHz  
  GPIO_Init(GPIOA, &GPIO_InitStructure);  
 

  TIM_PrescalerConfig(TIM2,0,TIM_PSCReloadMode_Update);
  TIM_SetAutoreload(TIM2,new_arr);
  TIM_SelectOutputTrigger(TIM2,TIM_TRGOSource_Update);

 
  DAC_InitStruct.DAC_Trigger = DAC_Trigger_T2_TRGO;      //????:???2??
  DAC_InitStruct.DAC_WaveGeneration = DAC_WaveGeneration_None;  //?????
  DAC_InitStruct.DAC_LFSRUnmask_TriangleAmplitude = DAC_LFSRUnmask_Bit0;
  DAC_InitStruct.DAC_OutputBuffer = DAC_OutputBuffer_Enable;   //??????
  DAC_Init(DAC_Channel_1,&DAC_InitStruct);  //
  
 
  DMA_InitStructure.DMA_PeripheralBaseAddr =  (uint32_t)&DAC -> DHR12R1;        //?????
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;  //??????,????
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;      //??????,????
  
	//DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)high_freq_square;//1M

  DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)current_wave_buffer;           //20k
	
	//DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)triangle_wave; // 2k
	
	//DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)square_wave;   // 2k
	
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;      //???????,????,????????
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;            //???????,????,?????,?????????
  
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;              //??????,????????
  DMA_InitStructure.DMA_BufferSize = current_wave_length;                    //???????
  DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;                //??,??????
  DMA_InitStructure.DMA_Priority = DMA_Priority_Medium;            //???,????
  DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;                  //??????
  DMA_Init(DMA2_Channel3, &DMA_InitStructure);                //????????DMA_Init,??DMA2???3
  
  
  TIM_Cmd(TIM2, ENABLE);          //???2??
  DMA_Cmd(DMA2_Channel3,ENABLE);  //??dma
  DAC_Cmd(DAC_Channel_1, ENABLE); //??DAC??1
  DAC_DMACmd(DAC_Channel_1, ENABLE);  //??DAC???DMA
	
}

void change_waveform(WaveType wave_type) {
    //if(wave_type == current_wave_type) return;
    
		
	
    DAC_Cmd(DAC_Channel_1, DISABLE);
    DMA_Cmd(DMA2_Channel3, DISABLE);
    
    switch(wave_type) {
        case SINE_WAVE:
            //current_wave_ptr = sin_wave;
						memcpy(current_wave_buffer, sin_wave, sizeof(sin_wave));
            current_wave_length = sizeof(sin_wave)/sizeof(uint16_t);
            break;
        case SQUARE_WAVE:
            //current_wave_ptr = square_wave;
						memcpy(current_wave_buffer, square_wave, sizeof(square_wave));
            current_wave_length = sizeof(square_wave)/sizeof(uint16_t);
            break;
        case TRIANGLE_WAVE:
            //current_wave_ptr = triangle_wave;
						memcpy(current_wave_buffer, triangle_wave, sizeof(triangle_wave));
            current_wave_length = sizeof(triangle_wave)/sizeof(uint16_t);
            break;
				case SAWTOOTH_WAVE:
            //current_wave_ptr = sawtooth_wave;
						memcpy(current_wave_buffer, sawtooth_wave, sizeof(sawtooth_wave));
            current_wave_length = sizeof(sawtooth_wave)/sizeof(uint16_t);
            break;
    }
    
    // ??DMA
    DMA_Cmd(DMA2_Channel3, DISABLE);
    DMA2_Channel3->CNDTR = current_wave_length; // ??????
    DMA2_Channel3->CMAR = (uint32_t)current_wave_buffer; // ??????
    DMA_Cmd(DMA2_Channel3, ENABLE);
    
    // ????DAC
    DAC_Cmd(DAC_Channel_1, ENABLE);
    
    current_wave_type = wave_type;
		
		if(current_wave_type == SINE_WAVE) set_frequency(20000);
		else set_frequency(2000);
		
		set_amplitude(62);
			
    printf("Wave changed: %d\r\n", wave_type);
}

void set_frequency(uint32_t freq_hz) {
    //uint32_t max_freq = 0;
		
		uint32_t trigger_freq = 0;
    if(freq_hz < 1) freq_hz = 1;
//    max_freq = 1000000 / current_wave_length; // DAC?????1MSPS
//    if(freq_hz > max_freq) freq_hz = max_freq;
//    
    
     // 72MHz
    trigger_freq = freq_hz * current_wave_length;
    new_arr = timer_clock / trigger_freq - 1;
    
    TIM_SetAutoreload(TIM2, new_arr);
    
    printf("Freq set: %u Hz\r\n", freq_hz);
}

void set_square_duty(uint8_t duty) {
		int i = 0;
		uint16_t high_points = 0;
    if(duty > 100) duty = 100;
    
		
    // ??????????
    if(current_wave_type != SQUARE_WAVE) {
        printf("Duty only for square wave!\r\n");
        return;
    }
    
		
		
		high_points = (current_wave_length * duty) / 100;
    
    // ??????
    for(i = 0; i < current_wave_length; i++) {
        if(i < high_points) {
            square_wave[i] = 4095; // ???
        } else {
            square_wave[i] = 0; // ???
        }
    }
    
    // ??DMA(????????)
    change_waveform(SQUARE_WAVE);
    
		
    printf("Duty set: %d%%\r\n", duty);
}

void set_amplitude(uint8_t percent) {
		int i = 0;
		float scale = 0.0;
		uint16_t max_val = 0;
	
    DAC_Cmd(DAC_Channel_1, DISABLE);
    DMA_Cmd(DMA2_Channel3, DISABLE);
    
    scale = percent / 100.0f;
    max_val = 4095 * scale;
    
    // ??????????
    switch(current_wave_type) {
        case SINE_WAVE:
            for(i = 0; i < current_wave_length; i++) {
								current_wave_buffer[i] = 2048 + (current_wave_buffer[i] - 2048)*scale;
            }
            break;
        case SQUARE_WAVE:
            for(i = 0; i < current_wave_length; i++) {
                current_wave_buffer[i] = current_wave_buffer[i] == 4095 ? max_val : 0;
            }
            break;
        case TRIANGLE_WAVE:
            for(i = 0; i < current_wave_length; i++) {
                current_wave_buffer[i] = current_wave_buffer[i] * scale;
            }
            break;
				case SAWTOOTH_WAVE:
            for(i = 0; i < current_wave_length; i++) {
                current_wave_buffer[i] = current_wave_buffer[i] * scale;
            }
            break;
    }
    
    // ????
    DMA_Cmd(DMA2_Channel3, ENABLE);
    DAC_Cmd(DAC_Channel_1, ENABLE);
    
    printf("Amplitude set: %d%%\r\n", percent);
}
