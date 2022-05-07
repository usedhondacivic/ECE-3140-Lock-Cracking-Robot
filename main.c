/*
 * main.c
 *
 *  Created on: May 2, 2022
 *      Author: Michael Crum
*/

#include <MKL46Z4.h>
#include <stdbool.h>

#include "stepper.h"

void go_to_number_right(int num){
	go_to_position_right(num * 5, 50);
}

void go_to_number_left(int num){
	go_to_position_left(num * 5, 50);
}

void test_combo(int one, int two, int three){
	move_stepper(600, -1, 50); // Reset the lock

	go_to_number_right(9);
	//delay(100000);

	move_stepper(200, 1, 50); //Full turn
	go_to_number_left(19);
	//delay(100000);

	go_to_number_right(25);
}


int main (void)
{
	stepper_init();
	move_stepper(600, -1, 50); // Reset the lock

	test_combo(9, 19, 25);
}
