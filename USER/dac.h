#ifndef _DAC_H
#define _DAC_H
#include "sys.h"
typedef enum {
    SINE_WAVE,
    SQUARE_WAVE,
    TRIANGLE_WAVE
} WaveType;
extern uint16_t sin_wave[64];
extern uint16_t triangle_wave[512];
extern uint16_t square_wave[512];
extern uint16_t high_freq_square[2];
extern uint32_t new_arr; 
void dac_config_init(void);
void change_waveform(WaveType wave_type);
void set_frequency(uint32_t freq_hz);
void set_square_duty(uint8_t duty);
void set_amplitude(uint8_t percent);

#endif
