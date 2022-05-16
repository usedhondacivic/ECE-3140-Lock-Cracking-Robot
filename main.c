/*
 * main.c
 *
 *  Created on: May 2, 2022
 *      Author: Michael Crum
*/

#include <MKL46Z4.h>
#include <stdbool.h>

#include "stepper.h"
#include "PWM.h"
#include "servo.h"
#include "ui.h"

void go_to_number_right(int num){
	stepper_go_to_position_right(num * 5, 50);
}

void go_to_number_left(int num){
	stepper_go_to_position_left(num * 5, 50);
}

bool try_combo(int one, int two, int three){
	servo_set_pos(0);
	stepper_move(600, -1, 50); // Reset the lock

	go_to_number_right(one);

	stepper_move(200, 1, 50); //Full turn
	go_to_number_left(two);

	go_to_number_right(three);

	servo_set_pos(120);
	delay(50000);
	servo_set_pos(0);

	//check servo feedback / button press
	return false;
}

void brute_force(int interval){
	/* Optimizations:
	 *	Second number cannot be equal to the first (There may be a offset (1/8th turn?) required, need to research more)
	 *	Third number cannot be equal to the second
	 *
	 *	Combos can be mis-entered by a small margin, so we can skip that margin between each number.
	 */

	int one, two, three;

	for(one = 0; one < 40; one+=interval){
		for(two = 0; two < 40; two+=interval){
			if(one == two) continue;
			for(three = 0; three < 40; three+=interval){
				if(two == three) continue;
				if(try_combo(one, two, three)){
					break; //Unlocked!
				}
				go_to_number_left(0);
			}
		}
	}
}

int main (void)
{
 	init_pwm();
	stepper_init();

	ui_init();

	//display_combo(9, 19, 25);

	get_slider_val();

	stepper_disable();

	wait_button_left();

	stepper_enable();

	try_combo(9, 19, 25);
	//brute_force(1);

	stepper_disable();
}
