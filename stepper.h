/*
 * stepper.h
 *
 *  Created on: May 2, 2022
 *      Author: Michael Crum
 */

#ifndef STEPPER_H_
#define STEPPER_H_

void delay(int milsec);

void stepper_init(void);

void move_stepper(int steps, int direction, int speed);

void go_to_position_right(int position, int speed);

void go_to_position_left(int position, int speed);

#endif /* STEPPER_H_ */
