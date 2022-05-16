/*
 * stepper.h
 *
 *  Created on: May 2, 2022
 *      Author: Michael Crum
 */

#ifndef STEPPER_H_
#define STEPPER_H_

void delay(int microsec);

void stepper_init(void);

void stepper_move(int steps, int direction, int speed);

void stepper_go_to_position_right(int position, int speed);

void stepper_go_to_position_left(int position, int speed);

void stepper_enable();

void stepper_disable();

#endif /* STEPPER_H_ */
