/*
 * main.c
 *
 *  Created on: May 2, 2022
 *      Author: Michael Crum
*/

#include <MKL46Z4.h>
#include <stdbool.h>

#include "stepper.h"
#include "servo.h"
#include "ui.h"
#include "ADC/adc.h"

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

	servo_set_pos(130);
	delay(30000);
	int x = servo_get_pos();
	//check servo feedback
	if(x > 850){
		servo_set_pos(0);
		servo_disable();
		return true;
	}
	servo_set_pos(0);
	delay(30000);
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

void advanced_crack(int lck_one, int lck_two, int resist){
	int one, two, three;

	one = resist + 5;

	for(two = 0; two < 40; two++){
		if(one == two) continue;
		for(three = 0; three < 40; three++){
			if(two == three) continue;
			if(three % 10 != lck_one && three % 10 != lck_two) continue;
			if(three % 4 != one % 4) continue;
			if((two + 2) % 4 != three % 4) continue;
			//if(three - two <= 2 && three - two >= -2) continue;
			display_combo(one, two, three);
			if(try_combo(one, two, three)){
				return; //Unlocked!
			}

			if(three != 0){
				go_to_number_right(0);
			}

		}
	}
}

int main (void)
{
 	servo_init();
	ui_init();
	stepper_init();

	stepper_disable();

	int one = get_slider_val();
	int two = get_slider_val();
	int three = get_slider_val();

	wait_button_left();

	stepper_enable();

	advanced_crack(one, two, three);
	//advanced_crack(5, 8, 4);
	//advanced_crack(6, 9, 9);

	stepper_disable();

	while(1){}
}
