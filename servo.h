/*
 * servo.h
 *
 *  Created on: May 16, 2022
 *      Author: Michael Crum
 */

#ifndef SERVO_H_
#define SERVO_H_

void servo_init(void);

void servo_set_pos(int deg);

int servo_get_pos(void);

void servo_disable(void);

#endif /* SERVO_H_ */
