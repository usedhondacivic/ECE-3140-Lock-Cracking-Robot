/*
 * servo.c
 *
 *  Created on: May 16, 2022
 *      Author: Michael Crum
 */


void servo_set_pos(int deg){
	//Range (micro sec in PWM pulse width): 500-2000
	int pulse_width = ((deg / 180.0) * 1500) + 500;

	set_control(pulse_width, 20000); // 1 / period -> 50 hz
}
