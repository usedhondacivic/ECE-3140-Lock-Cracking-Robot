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
	// 20.97152 MHz system clock / 10^6 microsec per second = 21 cycles / microsecond
	int j;
	for(j=0; j<21*microsec; j++);
}


void stepper_init(void){
	//Turn on the clock gating to ports A and D
	SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;
	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;
	//Set the pin MUX to GPIO
	PORTA->PCR[1] = PORT_PCR_MUX(001); // Direction
	PORTA->PCR[2] = PORT_PCR_MUX(001); // Step
	PORTD->PCR[3] = PORT_PCR_MUX(001); // Servo feedback
	PORTA->PCR[12] = PORT_PCR_MUX(001); // Enable

	//Set the pins to output
	PTA->PDDR |= (1 << 1);
	PTA->PDDR |= (1 << 2);
	PTD->PDDR |= (1 << 3);
	PTA->PDDR |= (1 << 12);

	// Set pins low
	PTA->PCOR |= (1 << 1);
	PTA->PCOR |= (1 << 2);
	PTD->PCOR |= (1 << 3);
	PTA->PCOR |= (1 << 12);
}

/*
 * Move the stepper motor.
 * Speed corresponds to the delay between steps, so a lower value = faster movement
 */
void move_stepper(int steps, int direction, int speed){
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

void go_to_position_right(int position, int speed){
	int currentPos = positive_modulo(accumulator, 200);
	int delta = currentPos - position;
	if(delta >= 0){
		move_stepper(delta, -1, speed);
	}else{
		int move = currentPos + (200 - position);
		move_stepper(move, -1, speed);
	}
}

void go_to_position_left(int position, int speed){
	int currentPos = positive_modulo(accumulator, 200);
	int delta = position - currentPos;
	if(delta >= 0){
		move_stepper(delta, 1, speed);
	}else{
		int move =  (200 - currentPos) + position;
		move_stepper(move, 1, speed);
	}
}
