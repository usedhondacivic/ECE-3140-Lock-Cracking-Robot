/*
 * stepper.c
 *
 * Stepper driver for the FRDM-KL46Z
 *
 *  Created on: May 2, 2022
 *      Author: Michael Crum
 */

#include <MKL46Z4.h>

int accumulator = 0;

void delay(int microsec){
	// 48 MHz system clock / 10^6 microsec per second = 48 cycles / microsecond
	int j;
	for(j=0; j<48*microsec; j++);
}


void stepper_init(void){
	//Turn on the clock gating to ports A and D
	SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;
	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;
	//Set the pin MUX to GPIO
	PORTA->PCR[1] = PORT_PCR_MUX(001); // Direction
	PORTA->PCR[2] = PORT_PCR_MUX(001); // Step
	PORTA->PCR[12] = PORT_PCR_MUX(001); // Enable

	//Set the pins to output
	PTA->PDDR |= (1 << 1);
	PTA->PDDR |= (1 << 2);
	PTA->PDDR |= (1 << 12);

	// Set pins low
	PTA->PCOR |= (1 << 1);
	PTA->PCOR |= (1 << 2);
	PTA->PCOR |= (1 << 12);
}

/*
 * Move the stepper motor.
 * Speed corresponds to the delay between steps, so a lower value = faster movement
 */
void stepper_move(int steps, int direction, int speed){
	if(direction == 1){
		PTA->PCOR |= (1 << 1);  // Set direction to forward
	}else{
		PTA->PSOR |= (1 << 1);  // Set direction to backward
	}

	for(int i = 0; i < steps; i++){
		PTA->PSOR |= (1 << 2); //Single high-low pulse
		delay(speed);
		PTA->PCOR |= (1 << 2);
		delay(speed);
		accumulator += direction;
	}
}

int positive_modulo(int i, int n) {
    return (i % n + n) % n;
}

void stepper_go_to_position_right(int position, int speed){
	int currentPos = positive_modulo(accumulator, 200);
	int delta = currentPos - position;
	if(delta >= 0){
		stepper_move(delta, -1, speed);
	}else{
		int move = currentPos + (200 - position);
		stepper_move(move, -1, speed);
	}
}

void stepper_go_to_position_left(int position, int speed){
	int currentPos = positive_modulo(accumulator, 200);
	int delta = position - currentPos;
	if(delta >= 0){
		stepper_move(delta, 1, speed);
	}else{
		int move =  (200 - currentPos) + position;
		stepper_move(move, 1, speed);
	}
}

void stepper_enable(){
	PTA->PCOR |= (1 << 12); // Active low
}

void stepper_disable(){
	PTA->PSOR |= (1 << 12);
}
