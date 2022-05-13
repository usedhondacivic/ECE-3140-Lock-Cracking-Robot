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

void go_to_number_right(int num){
	go_to_position_right(num * 5, 50);
}

void go_to_number_left(int num){
	go_to_position_left(num * 5, 50);
}

bool try_combo(int one, int two, int three){
	move_stepper(600, -1, 50); // Reset the lock

	go_to_number_right(9);

	move_stepper(200, 1, 50); //Full turn
	go_to_number_left(19);

	go_to_number_right(25);

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
			}
		}
	}
}


int main (void)
{

	init_pwm();
	set_control(500, 20000);

	stepper_init();
	move_stepper(500, -1, 50); // Reset the lock

	try_combo(9, 19, 25);
	set_control(1500, 20000);
	delay(100000);
	set_control(500, 20000);
}
