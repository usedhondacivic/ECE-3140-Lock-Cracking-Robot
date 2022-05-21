/*
 * PWM.h
 *
 *  Created on: May 12, 2022
 *      Author: Michael Crum
 */

#ifndef PWM_H_
#define PWM_H_

void pwm_init(void);

void set_control(int pulse_width, int period);

void pwm_disable(void);

#endif /* PWM_H_ */
