/*
 * servo.c
 *
 *  Created on: May 16, 2022
 *      Author: Michael Crum
 */

#include "PWM.h"
#include "ADC/adc.h"

void servo_init(){
	adc_init();
	pwm_init();
}

int servo_get_pos(){
	return adc_get_val();
}

void servo_set_pos(int deg){
	//Range (micro sec in PWM pulse width): 500-2000
	int pulse_width = ((deg / 180.0) * 1500) + 500;

	set_control(pulse_width, 20000); // 1 / period -> 50 hz
}

void servo_disable(){
	pwm_disable();
}
