/*
 * ui.c
 *
 *  Created on: May 16, 2022
 *      Author: Michael Crum
 */

#include <MKL46Z4.h>
#include <stdbool.h>
#include "LCD/lcd.h"
#include "Touch_Sen.h"
#include "stepper.h"

int SWITCH_1_PIN = 3;
int SWITCH_3_PIN = 12;

int combo[3];
int curr_disp = 0;

void ui_init(void){
	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK; //Enable the clock to port C

	//Setup SW1 (Right button)
	PORTC->PCR[SWITCH_1_PIN] &= ~PORT_PCR_MUX(0b111); // Clear PCR Mux bits for PTC3
	PORTC->PCR[SWITCH_1_PIN] |= PORT_PCR_MUX(0b001); // Set up PTC3 as GPIO
	PTC->PDDR &= ~GPIO_PDDR_PDD(1 << SWITCH_1_PIN); // make it input
	PORTC->PCR[SWITCH_1_PIN] |= PORT_PCR_PE(1); // Turn on the pull enable
	PORTC->PCR[SWITCH_1_PIN] |= PORT_PCR_PS(1); // Enable the pullup resistor
	PORTC->PCR[SWITCH_1_PIN] &= ~PORT_PCR_IRQC(0b1111); // Clear IRQC bits for PTC3
	PORTC->PCR[SWITCH_1_PIN] |= PORT_PCR_IRQC(0b1011); // Set up the IRQC to interrupt on either edge (i.e. from high to low or low to high)

	//Setup SW3 (Left button)
	PORTC->PCR[SWITCH_3_PIN] &= ~PORT_PCR_MUX(0b111); // Clear PCR Mux bits for PTC12
	PORTC->PCR[SWITCH_3_PIN] |= PORT_PCR_MUX(0b001); // Set up PTC12 as GPIO
	PTC->PDDR &= ~GPIO_PDDR_PDD(1 << SWITCH_3_PIN); // make it input
	PORTC->PCR[SWITCH_3_PIN] |= PORT_PCR_PE(1); // Turn on the pull enable
	PORTC->PCR[SWITCH_3_PIN] |= PORT_PCR_PS(1); // Enable the pullup resistor
	PORTC->PCR[SWITCH_3_PIN] &= ~PORT_PCR_IRQC(0b1111); // Clear IRQC bits for PTC3
	PORTC->PCR[SWITCH_3_PIN] |= PORT_PCR_IRQC(0b1011); // Set up the IRQC to interrupt on either edge (i.e. from high to low or low to high)

	init_lcd();

	NVIC_EnableIRQ(PIT_IRQn);

	SIM->SCGC6 |= SIM_SCGC6_PIT_MASK; //Enable clock to PIT
	PIT->MCR = 0x00; //Enable PIT timers

	PIT->CHANNEL[1].LDVAL = 0x00A00000; //10.48576 million cycles at 10.48576MHz = 1 second
	PIT->CHANNEL[1].TCTRL |= (1 << 1); //Enable interrupts for channel 1

	Touch_Init();
}

void display_number(int i){
	int tens = i / 10;
	int ones = i % 10;
	if(tens > 9){
		tens = 9;
	}
	displayDigit(1, tens);
	displayDigit(2, ones);
}

void display_combo(int one, int two, int three){
	combo[0] = one;
	combo[1] = two;
	combo[2] = three;
	PIT->CHANNEL[1].TCTRL |= 0x1; //Enable channel 1
}

void PIT_IRQHandler(void)
{
	/* code goes here */
	PIT->CHANNEL[1].TCTRL &= ~(0x1); //Disable channel 1
	curr_disp++;
	if(curr_disp == 3){
		curr_disp = 0;
	}
	display_number(combo[curr_disp]);
	if(curr_disp == 2){
		displayDecimalPoint(2);
	}else{
		clearDecimalPoint(2);
	}
	PIT->CHANNEL[1].TFLG = 1; //Clear the interrupt
	PIT->CHANNEL[1].TCTRL |= 0x1; //Enable channel 1
}

void wait_button_left(){
	while(1) {
		if((PORTC->PCR[SWITCH_3_PIN] & PORT_PCR_ISF(1)) != 0) {
			PORTC->PCR[SWITCH_3_PIN] |= PORT_PCR_ISF(1);  // clear the interrupt status flag by writing 1 to it
			break;
		}
	}
}

void wait_button_right(){
	while(1) {
		if((PORTC->PCR[SWITCH_1_PIN] & PORT_PCR_ISF(1)) != 0) {
			PORTC->PCR[SWITCH_1_PIN] |= PORT_PCR_ISF(1);  // clear the interrupt status flag by writing 1 to it
			break;
		}
	}
}

bool get_button_left(){
	if((PORTC->PCR[SWITCH_3_PIN] & PORT_PCR_ISF(1)) != 0) {
		PORTC->PCR[SWITCH_3_PIN] |= PORT_PCR_ISF(1);  // clear the interrupt status flag by writing 1 to it
		return true;
	}
	return false;
}

bool get_button_right(){
	if((PORTC->PCR[SWITCH_1_PIN] & PORT_PCR_ISF(1)) != 0) {
		PORTC->PCR[SWITCH_1_PIN] |= PORT_PCR_ISF(1);  // clear the interrupt status flag by writing 1 to it
		return true;
	}
	return false;
}

int get_slider_val(){
	PORTC->PCR[SWITCH_1_PIN] |= PORT_PCR_ISF(1);
	PORTC->PCR[SWITCH_3_PIN] |= PORT_PCR_ISF(1);
	int count = 0;
	while(1){
		int x = Touch_Scan_LH()/ 20.;
		if(x > 30){
			count ++;
		} else if(x >5){
			count --;
		}
		if(count > 39){
			count = 39;
		}
		if(count < 0){
			count = 0;
		}
		delay(10000);
		display_number(count);
		if(get_button_right() == true){
			return count;
		}
	}
}
